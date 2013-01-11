/*****************************************************************************
Copyright (C) 2011 Elliot Laster

Permission is hereby granted, free of charge, to any person obtaining a copy of 
this software and associated documentation files (the ‘Software’), to deal in 
the Software without restriction, including without limitation the rights to 
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all 
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED ‘AS IS’, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
SOFTWARE.
 *****************************************************************************/
#include "_mapnik_datasource.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Hash.hpp>
#include <rice/Array.hpp>

// Mapnik
#include <mapnik/layer.hpp>
#include <mapnik/version.hpp>
#include <mapnik/datasource.hpp>
#include <mapnik/datasource_cache.hpp>
#include <mapnik/feature_layer_desc.hpp>
#include <mapnik/box2d.hpp>

#if MAPNIK_VERSION >= 200200
	typedef mapnik::value_integer value_integer;
#else
	typedef int value_integer;
#endif

namespace {
  class mapnik_value_holder_to_ruby_visitor : public boost::static_visitor<Rice::Object>
  {
  public:

   Rice::Object operator()(value_integer i) const {
     // TODO - support long long?
     return to_ruby<int>(static_cast<int>(i));
   }

   Rice::Object operator()(bool i) const {
     return to_ruby<bool>(i);
   }
   Rice::Object operator()(double i) const {
     return to_ruby<double>(i);
   }

   Rice::Object operator()(std::string const& str) const {
     return to_ruby<std::string>(str);
   }

   Rice::Object operator()(mapnik::value_null const& value) const {
     return NULL;
   }

  };


  std::string name(boost::shared_ptr<mapnik::datasource> self){
    mapnik::layer_descriptor ld = self->get_descriptor();
    return ld.get_name();
  }

  boost::shared_ptr<mapnik::datasource> create(Rice::Object params){
    Rice::Hash options = (Rice::Hash) params;
    mapnik::parameters datasource_params;

    Rice::Hash::iterator it = options.begin();
    Rice::Hash::iterator end = options.end();
    for(; it != end; ++it) {
      Rice::String keyString = it->key.to_s();
      Rice::Object value = it->value;
      switch (value.rb_type()) {
        case T_STRING:
          datasource_params[keyString.str()] = ((Rice::String) value).str();
          break;
        case T_FLOAT:
          datasource_params[keyString.str()] = NUM2DBL(value.value());
          break;
        case T_FIXNUM:
          // The compiler wanted this explicit cast here, not sure why...
          // TODO FIXME - won't compile....
          //datasource_params[keyString.str()] = static_cast<value_integer>(NUM2INT(value.value()));
          break;
      }
    }
    
#if MAPNIK_VERSION >= 200200
    return mapnik::datasource_cache::instance().create(datasource_params);
#else
    return mapnik::datasource_cache::instance()->create(datasource_params);
#endif
  }


  mapnik::box2d<double> get_datasource_envelope(boost::shared_ptr<mapnik::datasource> self){
    return self->envelope();
  }

  Rice::Object get_datasource_params(boost::shared_ptr<mapnik::datasource> const & self){
    Rice::Hash params;
    mapnik::parameters ds_params = self->params();
    mapnik::parameters::const_iterator pos=ds_params.begin();
    while(pos!=ds_params.end())
    {
      params[Rice::Symbol(pos->first)] = boost::apply_visitor(mapnik_value_holder_to_ruby_visitor(), pos->second);
      ++pos;
    }
    return params;
  }
}
void register_datasource(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< boost::shared_ptr<mapnik::datasource> > rb_cdatasource = Rice::define_class_under< boost::shared_ptr<mapnik::datasource> >(rb_mapnik, "Datasource");
  
  /*
  * Document-method: envelope
  * @return [Mapnik::Envelope]
  * Returns an envelope containing the datasource's features
  */
  rb_cdatasource.define_method("envelope", &get_datasource_envelope);

  /*
  * Document-method: name
  * @return [String]
  * The name of the datasource
  */
  rb_cdatasource.define_method("name", &name);

  /*
  * Document-method: params
  * @return [Hash]
  * The params used to create the datasource
  */
  rb_cdatasource.define_method("params", &get_datasource_params);

  /*
  * Document-method: create
  * call-seq:
  *   Mapnik::Datasource.create(params)
  * 
  * @param [Hash] the parameters for the datasource
  *
  * Creates a new datasource, with the params provided. The parameters required
  * will depend on the input plugin
  *
  * -- TODO: more
  */
  rb_cdatasource.define_singleton_method("create", &create, (Rice::Arg("params")));
  
  // TODO: Descriptor, features at point...
  // rb_cdatasource.define_method("descriptor", &mapnik::datasource::get_descriptor);
  
}
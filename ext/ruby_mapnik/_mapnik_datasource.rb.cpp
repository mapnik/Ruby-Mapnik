/*****************************************************************************
 * 
 * Copyright (C) 2011 Elliot Laster
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
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
#include <mapnik/datasource.hpp>
#include <mapnik/datasource_cache.hpp>
#include <mapnik/feature_layer_desc.hpp>
#include <mapnik/box2d.hpp>

namespace {
  class mapnik_value_holder_to_ruby_visitor : public boost::static_visitor<Rice::Object>
  {
  public:

   Rice::Object operator()(int i) const {
     return to_ruby<int>(i);
   }

   Rice::Object operator()(double i) const {
     return to_ruby<double>(i);
   }

   Rice::Object operator()(const std::string & str) const {
     return to_ruby<std::string>(str);
   }
  };


  std::string name(boost::shared_ptr<mapnik::datasource> self){
    mapnik::layer_descriptor ld = self->get_descriptor();
    return ld.get_name();
  }

  boost::shared_ptr<mapnik::datasource> create(Rice::Object params){
    bool bind=true;
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
          datasource_params[keyString.str()] = (int)NUM2INT(value.value());
          break;
      }
    }
    
    return mapnik::datasource_cache::create(datasource_params, bind);
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
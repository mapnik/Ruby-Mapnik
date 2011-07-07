#include "_mapnik_datasource.rb.h"
#include <mapnik2/layer.hpp>
#include <rice/Address_Registration_Guard_defn.hpp>

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

void register_datasource(Rice::Module rb_mapnik){
  Rice::Data_Type< boost::shared_ptr<mapnik::datasource> > rb_cdatasource = Rice::define_class_under< boost::shared_ptr<mapnik::datasource> >(rb_mapnik, "Datasource");
  
  // TODO:
  // rb_cdatasource.define_method("envelope", &mapnik::datasource::envelope);
  // rb_cdatasource.define_method("descriptor", &mapnik::datasource::get_descriptor);
  rb_cdatasource.define_method("name", &name);
  
  rb_cdatasource.define_singleton_method("create", &create, (Rice::Arg("params")));
  // TODO: more
}
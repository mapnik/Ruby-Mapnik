#include "_mapnik_datasource_cache.rb.h"
#include "rice/Hash.hpp"

bool rubysafe_register_sources(std::string path){
  mapnik::datasource_cache::instance()->register_datasources(path);
  return true;
}

Rice::Array rubysafe_plugin_names(){
  std::vector<std::string, std::allocator<std::string> > names = mapnik::datasource_cache::instance()->plugin_names();

  Rice::Array o;

  int unsigned count = names.size();
  
  for (unsigned i=0;i<count;++i){
    Rice::String n = names[i];
    o.push(n);
  }
  
  return o;
}

void register_datasource_cache(Rice::Module rb_mRapnik) {
  Rice::Data_Type< mapnik::datasource_cache > rb_cdatasource_cache =  Rice::define_class_under< mapnik::datasource_cache >(rb_mRapnik, "DatasourceCache");
  
  rb_cdatasource_cache.define_singleton_method("available_plugins", &rubysafe_plugin_names);  
  rb_cdatasource_cache.define_singleton_method("register", &rubysafe_register_sources, Rice::Arg("path"));
}
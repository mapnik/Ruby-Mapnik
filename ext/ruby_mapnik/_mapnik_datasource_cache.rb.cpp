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
  
  // TODO: possibly add create here? I like it going though the datasource
  // class, but I suppose that some people will be conditioned otherwise.
  

}
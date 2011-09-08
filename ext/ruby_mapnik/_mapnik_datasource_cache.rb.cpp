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
#include "_mapnik_datasource_cache.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Array.hpp>
#include <rice/Hash.hpp>

// Mapnik
#include <mapnik/datasource.hpp>
#include <mapnik/datasource_cache.hpp>

namespace {
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
}
void register_datasource_cache(Rice::Module rb_mapnik) {
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::datasource_cache > rb_cdatasource_cache =  Rice::define_class_under< mapnik::datasource_cache >(rb_mapnik, "DatasourceCache");
  
  /*
  * Document-method: available_plugins
  *
  * @return [Array] the datasource plugins available. (Determined by your Mapnik install)
  */
  rb_cdatasource_cache.define_singleton_method("available_plugins", &rubysafe_plugin_names);  
  
  /*
  * Document-method: register
  * call-seq:
  *   Mapnik::DatasourceCache.register(path_to_mapnik_input_plugins)
  * @param [String] The path
  * 
  * Registers the input plugins with mapnik. Used internally by Ruby-Mapnik. 
  * You should never have to call this. 
  */
  rb_cdatasource_cache.define_singleton_method("register", &rubysafe_register_sources, Rice::Arg("path"));
}
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
#include "_mapnik_feature.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>

// Mapnik
#include <mapnik/wkt/wkt_factory.hpp>
#include <mapnik/feature.hpp>

void add_geometries_from_wkt(mapnik::Feature * self, std::string wkt){
  bool result = mapnik::from_wkt(wkt, self->paths());
  if (!result) throw std::runtime_error("Failed to parse WKT");
}

void register_feature(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::Feature > rb_cfeature = Rice::define_class_under< mapnik::Feature >(rb_mapnik, "Feature");
  rb_cfeature.define_constructor(Rice::Constructor< mapnik::Feature,int >());
  rb_cfeature.define_method("id", &mapnik::Feature::id);
  rb_cfeature.define_method("to_s", &mapnik::Feature::to_string);
  rb_cfeature.define_method("number_of_geometries", &mapnik::Feature::num_geometries);
  rb_cfeature.define_method("envelope", &mapnik::Feature::envelope);
  
  rb_cfeature.define_method("add_geometries_from_wkt", &add_geometries_from_wkt, Rice::Arg("geom"));  
}
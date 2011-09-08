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
#include "_mapnik_style.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>

// Mapnik
#include <mapnik/feature_type_style.hpp>


template<>
Rice::Object to_ruby<std::vector<mapnik::rule> >(std::vector<mapnik::rule> const & x)
{
  return Rice::Array(x.begin(), x.end());
}

namespace {

  void set_style_filter(mapnik::feature_type_style& self, mapnik::filter_mode_enum value){
    mapnik::filter_mode_e v(value);
    self.set_filter_mode(v);
  }

  mapnik::filter_mode_enum get_style_filter(const mapnik::feature_type_style& self){
    return self.get_filter_mode();
  }

}
void register_style(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::feature_type_style > rb_cstyle = Rice::define_class_under< mapnik::feature_type_style >(rb_mapnik, "Style");
  
  /*
  * Document-method: new
  * @return [Mapnik::Style]
  */
  rb_cstyle.define_constructor(Rice::Constructor< mapnik::feature_type_style >());
  
  // Dont-Document-method: __rules__
  rb_cstyle.define_method("__rules__", &mapnik::feature_type_style::get_rules);
  
  // Dont-Document-method: __add_rule__
  rb_cstyle.define_method("__add_rule__", &mapnik::feature_type_style::add_rule);
  
  rb_cstyle.define_method("filter_mode=", &set_style_filter);
  rb_cstyle.define_method("filter_mode", &get_style_filter);

  Rice::Enum<mapnik::filter_mode_enum> rb_cfilter_mode_enum = Rice::define_enum<mapnik::filter_mode_enum>("FilterMode", rb_mapnik);
  rb_cfilter_mode_enum.define_value("ALL",mapnik::FILTER_ALL);
  rb_cfilter_mode_enum.define_value("FIRST",mapnik::FILTER_FIRST);
}
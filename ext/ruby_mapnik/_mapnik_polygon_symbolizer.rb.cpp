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
#include "_mapnik_polygon_symbolizer.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>

// Mapnik
#include <mapnik/polygon_symbolizer.hpp>
#include <mapnik/rule.hpp>
  
void register_polygon_symbolizer(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::polygon_symbolizer > rb_cpolygon_symbolizer = Rice::define_class_under< mapnik::polygon_symbolizer >(rb_mapnik, "PolygonSymbolizer");
  
  /*
  * Document-method: new
  * @return [Mapnik::PolygonSymbolzer]
  */
  rb_cpolygon_symbolizer.define_constructor(Rice::Constructor< mapnik::polygon_symbolizer >());
  
  /*
  * Document-method: fill
  * @return [Mapnik::Color]
  */
  rb_cpolygon_symbolizer.define_method("fill", &mapnik::polygon_symbolizer::get_fill);
  
  /*
  * Document-method: fill=
  * call-seq:
  *   fill=(color)
  * @param [Mapnik::Color] color
  * @return [nil]
  */
  rb_cpolygon_symbolizer.define_method("fill=", &mapnik::polygon_symbolizer::set_fill, Rice::Arg("new_color"));
  
  /*
  * Document-method: opacity
  * @return [Float]
  */
  rb_cpolygon_symbolizer.define_method("opacity", &mapnik::polygon_symbolizer::get_opacity);
  
  /* Document-method: opacity=
  * call-seq:
  *   opacity=(new_value)
  * @param [Float]
  * @return [nil]
  */
  rb_cpolygon_symbolizer.define_method("opacity=", &mapnik::polygon_symbolizer::set_opacity, Rice::Arg("new_opacity"));
  
  /*
  * Document-method: gamma
  * @return [Float]
  */
  rb_cpolygon_symbolizer.define_method("gamma", &mapnik::polygon_symbolizer::get_gamma);
  
  /* Document-method: gamma=
  * call-seq:
  *   gamma=(new_value)
  * @param [Float]
  * @return [nil]
  */
  rb_cpolygon_symbolizer.define_method("gamma=", &mapnik::polygon_symbolizer::set_gamma, Rice::Arg("new_gamma"));

};

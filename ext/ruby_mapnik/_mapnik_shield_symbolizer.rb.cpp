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
#include "_mapnik_shield_symbolizer.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>

// Mapnik
#include <mapnik/text_symbolizer.hpp>  
#include <mapnik/shield_symbolizer.hpp>

namespace{

  Rice::Object get_shield_displacement(const mapnik::shield_symbolizer& t){
    mapnik::position pos = t.get_shield_displacement();
    Rice::Array out;
    out.push(boost::get<0>(pos));
    out.push(boost::get<1>(pos));
    return out;
  }

  void set_shield_displacement(mapnik::shield_symbolizer & t, Rice::Array ary){
    double x = from_ruby<double>(ary[0]);
    double y = from_ruby<double>(ary[1]);
    t.set_shield_displacement(x,y);
  }

}
void register_shield_symbolizer(Rice::Module rb_mapnik){  
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::shield_symbolizer > rb_cshield_symbolizer = Rice::define_class_under< mapnik::shield_symbolizer, mapnik::text_symbolizer >(rb_mapnik, "ShieldSymbolizer");
  
  /*
  * Document-method: new
  * call-seq:
  *   new(expression, face_name, size, color, file)
  *
  * @param [Mapnik::Expression] expression
  * @param [String] face_name
  * @param [Integer] size
  * @param [Mapnik::Color] color
  * @param [Mapnik::PathExpression] file
  *
  * @return [Mapnik::ShieldSymbolizer]
  */
  rb_cshield_symbolizer.define_constructor(Rice::Constructor< mapnik::shield_symbolizer, mapnik::expression_ptr, std::string, unsigned, mapnik::color, mapnik::path_expression_ptr >());  
  
  /*
  * Document-method: shield_displacement
  * @return [Array] Two element array [x,y]
  */
  rb_cshield_symbolizer.define_method("shield_displacement", &get_shield_displacement);
  
  /*
  * Document-method: shield_displacement=
  * call-seq:
  *   shield_displacement=(new_displacement)
  * @param [Array] new_displacement Two element array [x,y]
  */
  rb_cshield_symbolizer.define_method("shield_displacement=", &set_shield_displacement);
  
}
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
#include "_mapnik_stroke.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>
#include <rice/Array.hpp>
#include <rice/Hash.hpp>
#include <rice/Symbol.hpp>

// Mapnik
#include <mapnik/stroke.hpp>

namespace {
  
  Rice::Object get_dashes(const mapnik::stroke& stroke){
    Rice::Array out;
    if (stroke.has_dash()) {
        mapnik::dash_array const& dash = stroke.get_dash_array();
        mapnik::dash_array::const_iterator iter = dash.begin();
        mapnik::dash_array::const_iterator end = dash.end();
        for (; iter != end; ++iter) {
          Rice::Array tuple;
          tuple.push(iter->first);
          tuple.push(iter->second);
          out.push(tuple);
        }
    } 
    return out;
  }

  mapnik::line_cap_enum get_stroke_line_cap(mapnik::stroke const & self){
    mapnik::line_cap_enum line_cap = self.get_line_cap();
    return line_cap;
  }

  void set_stroke_line_cap(mapnik::stroke & self, mapnik::line_cap_enum val){
    self.set_line_cap(val);
  }

  mapnik::line_join_enum get_stroke_line_join(mapnik::stroke const & self){
    mapnik::line_join_enum line_join = self.get_line_join();
    return line_join;
  }

  void set_stroke_line_join(mapnik::stroke & self, mapnik::line_join_enum val){
    self.set_line_join(val);
  }

}

void register_stroke(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::stroke > rb_cstroke = Rice::define_class_under< mapnik::stroke >(rb_mapnik, "Stroke");
  
  /*
  * Document-method: new
  * call-seq:
  *   new(color, width)
  * @param [Mapnik::Color] color
  * @param [Float] width
  *
  * @return [Mapnik::Stroke] 
  */
  rb_cstroke.define_constructor(Rice::Constructor< mapnik::stroke, mapnik::color, float >());
  
  /*
  * Document-method: color
  * @return [Mapnik::Color]
  */
  rb_cstroke.define_method("color", &mapnik::stroke::get_color);
  
  /*
  * Document-method: color=
  * call-seq:
  *   color=(color)
  * @param [Mapnik::Color] color
  * @return [nil]
  */
  rb_cstroke.define_method("color=", &mapnik::stroke::set_color, Rice::Arg("new_color"));
  
  /*
  * Document-method: opacity
  * @return [Float]
  */
  rb_cstroke.define_method("opacity", &mapnik::stroke::get_opacity);
  
  /*
  * Document-method: opacity=
  * call-seq:
  *   opactiy=(new_value)
  * @param [Float] new_value
  * @return [nil]
  */
  rb_cstroke.define_method("opacity=", &mapnik::stroke::set_opacity, Rice::Arg("new_opacity"));
  
  /*
  * Document-method: gamma
  * @return [Float]
  */
  rb_cstroke.define_method("gamma", &mapnik::stroke::get_gamma);
  
  /*
  * Document-method: gamma=
  * call-seq:
  *   gamma=(new_value)
  * @param [Float] new_value
  * @return [nil]
  */
  rb_cstroke.define_method("gamma=", &mapnik::stroke::set_gamma, Rice::Arg("new_gamma"));
  
  /*
  * Document-method: width
  * @return [Float]
  */
  rb_cstroke.define_method("width", &mapnik::stroke::get_width);
  
  /*
  * Document-method: width=
  * call-seq:
  *   width=(new_value)
  * @param [Float] new_value
  * @return [nil]
  */
  rb_cstroke.define_method("width=", &mapnik::stroke::set_width, Rice::Arg("new_width"));

  /*
  * Document-method: dash_offset
  * @return [Float]
  */
  rb_cstroke.define_method("dash_offset", &mapnik::stroke::dash_offset);
  
  /*
  * Document-method: dash_offset=
  * call-seq:
  *   dash_offset=(new_value)
  * @param [Float] new_value
  * @return [nil]
  */
  rb_cstroke.define_method("dash_offset=", &mapnik::stroke::set_dash_offset, Rice::Arg("new_dash_offset"));

  rb_cstroke.define_method("line_cap", &get_stroke_line_cap);
  rb_cstroke.define_method("line_cap=", &set_stroke_line_cap);
  
  rb_cstroke.define_method("line_join", &get_stroke_line_join);
  rb_cstroke.define_method("line_join=", &set_stroke_line_join);
  
  // Dont-Document-method: __dashes__
  rb_cstroke.define_method("__dashes__", &get_dashes);
  
  // Dont-Document-method: __add_dash__
  rb_cstroke.define_method("__add_dash__", &mapnik::stroke::add_dash);

  Rice::Enum<mapnik::line_cap_enum> rb_eline_cap_enum = Rice::define_enum<mapnik::line_cap_enum>("LineCap", rb_mapnik);
  rb_eline_cap_enum.define_value("BUTT_CAP", mapnik::BUTT_CAP);
  rb_eline_cap_enum.define_value("SQUARE_CAP", mapnik::SQUARE_CAP);
  rb_eline_cap_enum.define_value("ROUND_CAP", mapnik::ROUND_CAP);
 
  Rice::Enum<mapnik::line_join_enum> rb_eline_join_enum = Rice::define_enum<mapnik::line_join_enum>("LineJoin", rb_mapnik);
  rb_eline_join_enum.define_value("MITER_JOIN", mapnik::MITER_JOIN);
  rb_eline_join_enum.define_value("MITER_REVERT_JOIN", mapnik::MITER_REVERT_JOIN);
  rb_eline_join_enum.define_value("ROUND_JOIN", mapnik::ROUND_JOIN);
  rb_eline_join_enum.define_value("BEVEL_JOIN", mapnik::BEVEL_JOIN);
}

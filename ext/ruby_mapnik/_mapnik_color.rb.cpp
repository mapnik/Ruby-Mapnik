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

#include "_mapnik_color.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>

// Mapnik
#include <mapnik/color.hpp>

namespace {
  bool check_color_equality(mapnik::color const & self, mapnik::color const & rhs){
    return self == rhs;
  }

  // All this for optional constructor arguments. There must be a better way...
  void initialize_color(Rice::Object self, Rice::Object arg1 = Rice::Object(), Rice::Object arg2 = Rice::Object(), Rice::Object arg3 = Rice::Object(), Rice::Object arg4 = Rice::Object()){
    if(arg1.rb_type() == T_STRING && arg2.is_nil() && arg3.is_nil() && arg4.is_nil()) 
    {
      std::string hex = from_ruby<std::string>(arg1);
      DATA_PTR(self.value()) = new mapnik::color(hex);
    } else if(arg1.is_nil() && arg2.is_nil() && arg3.is_nil() && arg4.is_nil())
    {
      DATA_PTR(self.value()) = new mapnik::color();
    } else if(arg1.rb_type() == T_FIXNUM && arg2.rb_type() == T_FIXNUM && arg3.rb_type() == T_FIXNUM && arg4.rb_type() == T_FIXNUM)
    {
      DATA_PTR(self.value()) = new mapnik::color((int)NUM2INT(arg1.value()), (int)NUM2INT(arg2.value()), (int)NUM2INT(arg3.value()), (int)NUM2INT(arg4.value()));
    } else if(arg1.rb_type() == T_FIXNUM && arg2.rb_type() == T_FIXNUM && arg3.rb_type() == T_FIXNUM && arg4.is_nil())
    {
      DATA_PTR(self.value()) = new mapnik::color((int)NUM2INT(arg1.value()), (int)NUM2INT(arg2.value()), (int)NUM2INT(arg3.value()));
    } else 
    {
      rb_raise(rb_eRuntimeError, "Could not instantiate color");
    }
  }
}
void register_color(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  
  /* 
   * Document-class: Mapnik::Color
   * A RGBA color.
   */
  Rice::Data_Type< mapnik::color > rb_ccolor = Rice::define_class_under< mapnik::color >(rb_mapnik, "Color");
  
  /*
  * Document-method: new
  * call-seq: 
  *   new()
  *   new(red, green, blue)
  *   new(red, green, blues, alpha)
  *   new(css_string)
  * @return [Mapnik::Color] 
  * Returns a new Color object. The first form returns a value of white 
  * (255, 255, 255, 255), the others set the values properly. 
  *
  * The CSS String form
  * should be of the format "#FF0000" (leading '#').
  */
  rb_ccolor.define_constructor(Rice::Constructor< mapnik::color >());  
  
  rb_ccolor.define_method("initialize", &initialize_color, (Rice::Arg("arg1") = Rice::Object(), Rice::Arg("arg2") = Rice::Object(), Rice::Arg("arg3") = Rice::Object(), Rice::Arg("arg4") = Rice::Object()));
  
  /* 
   * Document-method: red
   * Returns the red value of the color as an integer value between 0 and 255
   * @return [Integer]
   */
  rb_ccolor.define_method("red", &mapnik::color::red);
  
  /* 
   * Document-method: green
   * Returns the green value of the color as an integer value between 0 and 255
   * @return [Integer]
   */
  rb_ccolor.define_method("green", &mapnik::color::green);
  
  /* 
   * Document-method: blue
   * Returns the blue value of the color as an integer value between 0 and 255
   * @return [Integer]
   */
  rb_ccolor.define_method("blue", &mapnik::color::blue);
  
  /* 
   * Document-method: alpha
   * Returns the alpha value of the color as an integer value between 0 and 255
   * @return [Integer]
   */
  rb_ccolor.define_method("alpha", &mapnik::color::alpha);
  
  /*
   * Document-method: red=
   * call-seq:
   *  red=(value)
   * @param [Integer] value between 0 and 255
   * @return [nil]
   * Sets the red value of the color
   */
  rb_ccolor.define_method("red=", &mapnik::color::set_red, (Rice::Arg("value")));
  
  /*
   * Document-method: green=
   * call-seq:
   *  green=(value)
   * @param [Integer] value between 0 and 255
   * @return [nil]
   * Sets the green value of the color
   */
  rb_ccolor.define_method("green=", &mapnik::color::set_green, (Rice::Arg("value")));
  
  /*
   * Document-method: blue=
   * call-seq:
   *  blue=(value)
   * @param [Integer] value between 0 and 255
   * @return [nil]
   * Sets the blue value of the color
   */
  rb_ccolor.define_method("blue=", &mapnik::color::set_blue, (Rice::Arg("value")));
  
  /*
   * Document-method: alpha=
   * call-seq:
   *  alpha=(value)
   * @param [Integer] value between 0 and 255
   * @return [nil]
   * Sets the alpha value of the color
   */
  rb_ccolor.define_method("alpha=", &mapnik::color::set_alpha, (Rice::Arg("value")));

  /*
  * Document-method: to_hex
  * Returns a string with a CSS hex value representing the color
  * @return [String] the CSS hex color string
  */
  rb_ccolor.define_method("to_hex", &mapnik::color::to_hex_string);
  
  /*
  * Document-method: to_s
  * Returns a string with rgb(a) values representing the color
  * @return [String] RGBA values like so: "rgb(0,0,0)"
   */
  rb_ccolor.define_method("to_s", &mapnik::color::to_string);
  
  /*
  * Document-method: ==
  * call-seq:
  *   == another_color
  * Returns true if the red, blue, green, and alpha values are equal for both colors
  * @return [boolean]
  */
  rb_ccolor.define_method("==", &check_color_equality);
    
}
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

bool check_color_equality(mapnik::color const & self, mapnik::color const & rhs){
  return self == rhs;
}

void register_color(Rice::Module rb_mapnik){
  Rice::Data_Type< mapnik::color > rb_ccolor = Rice::define_class_under< mapnik::color >(rb_mapnik, "Color");
  rb_ccolor.define_constructor(Rice::Constructor< mapnik::color, std::string >());  
  
  rb_ccolor.define_method("red", &mapnik::color::red);
  rb_ccolor.define_method("green", &mapnik::color::green);
  rb_ccolor.define_method("blue", &mapnik::color::blue);
  rb_ccolor.define_method("alpha", &mapnik::color::alpha);
  
  rb_ccolor.define_method("red=", &mapnik::color::set_red, (Rice::Arg("value")));
  rb_ccolor.define_method("green=", &mapnik::color::set_green, (Rice::Arg("value")));
  rb_ccolor.define_method("blue=", &mapnik::color::set_blue, (Rice::Arg("value")));
  rb_ccolor.define_method("alpha=", &mapnik::color::set_alpha, (Rice::Arg("value")));

  rb_ccolor.define_method("to_hex", &mapnik::color::to_hex_string);
  rb_ccolor.define_method("to_s", &mapnik::color::to_string);
  rb_ccolor.define_method("==", &check_color_equality);
    
}
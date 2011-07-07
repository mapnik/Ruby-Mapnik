#include "_mapnik_color.rb.h"

void register_color(Rice::Module rb_mapnik){
  Rice::Data_Type< mapnik::color > rb_ccolor = Rice::define_class_under< mapnik::color >(rb_mapnik, "Color");
  rb_ccolor.define_constructor(Rice::Constructor< mapnik::color, int, int, int, int >());
  
  rb_ccolor.define_method("red", &mapnik::color::red);
  rb_ccolor.define_method("green", &mapnik::color::green);
  rb_ccolor.define_method("blue", &mapnik::color::blue);
  rb_ccolor.define_method("alpha", &mapnik::color::alpha);
  
  rb_ccolor.define_method("red=", &mapnik::color::set_red, (Rice::Arg("value")));
  rb_ccolor.define_method("green=", &mapnik::color::set_green, (Rice::Arg("value")));
  rb_ccolor.define_method("blue=", &mapnik::color::set_blue, (Rice::Arg("value")));
  rb_ccolor.define_method("alpha=", &mapnik::color::set_alpha, (Rice::Arg("value")));

//  These symbols are not found on my installation. Moving on...
  rb_ccolor.define_method("to_hex", &mapnik::color::to_hex_string);
  rb_ccolor.define_method("to_s", &mapnik::color::to_string);
  
}
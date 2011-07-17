#include "_mapnik_stroke.rb.h"

void register_stroke(Rice::Module rb_mapnik){
  Rice::Data_Type< mapnik::stroke > rb_cstroke = Rice::define_class_under< mapnik::stroke >(rb_mapnik, "Stroke");
  rb_cstroke.define_constructor(Rice::Constructor< mapnik::stroke, mapnik::color, float >());
  
  rb_cstroke.define_method("color", &mapnik::stroke::get_color);
  rb_cstroke.define_method("color=", &mapnik::stroke::set_color, Rice::Arg("new_color"));
  
  rb_cstroke.define_method("opacity", &mapnik::stroke::get_opacity);
  rb_cstroke.define_method("opacity=", &mapnik::stroke::set_opacity, Rice::Arg("new_opacity"));
  
  rb_cstroke.define_method("gamma", &mapnik::stroke::get_gamma);
  rb_cstroke.define_method("gamma=", &mapnik::stroke::set_gamma, Rice::Arg("new_gamma"));
  
  rb_cstroke.define_method("width", &mapnik::stroke::get_width);
  rb_cstroke.define_method("width=", &mapnik::stroke::set_width, Rice::Arg("new_width"));
 
  // TODO: Line caps, joins, and dashes...
  
}

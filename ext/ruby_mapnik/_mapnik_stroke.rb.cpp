#include "_mapnik_stroke.rb.h"

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

  rb_cstroke.define_method("dash_offset", &mapnik::stroke::dash_offset);
  rb_cstroke.define_method("dash_offset=", &mapnik::stroke::set_dash_offset, Rice::Arg("new_dash_offset"));

  rb_cstroke.define_method("__dashes__", &get_dashes);
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

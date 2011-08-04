#include "_mapnik_glyph_symbolizer.rb.h"

Rice::Object get_displacement(const mapnik::glyph_symbolizer& t){
  mapnik::position pos = t.get_displacement();
  Rice::Array out;
  out.push(boost::get<0>(pos));
  out.push(boost::get<1>(pos));
  return out;
}

void set_displacement(mapnik::glyph_symbolizer & t, Rice::Array ary){
  double x = from_ruby<double>(ary[0]);
  double y = from_ruby<double>(ary[1]);
  
  t.set_displacement(x,y);
}

mapnik::angle_mode_enum get_angle_mode(mapnik::glyph_symbolizer const & self){
  return self.get_angle_mode();
}

void set_angle_mode(mapnik::glyph_symbolizer & self, mapnik::angle_mode_enum val){
  self.set_angle_mode(val);
}


void register_glyph_symbolizer(Rice::Module rb_mapnik){
  
  Rice::Enum<mapnik::angle_mode_enum> angle_enum = Rice::define_enum<mapnik::angle_mode_enum>("AngleMode", rb_mapnik);
  angle_enum.define_value("AZIMUTH", mapnik::AZIMUTH);
  angle_enum.define_value("TRIGONOMETRIC", mapnik::TRIGONOMETRIC);
  
  Rice::Data_Type< mapnik::glyph_symbolizer > rb_cglyph_symbolizer = Rice::define_class_under< mapnik::glyph_symbolizer >(rb_mapnik, "GlyphSymbolizer");
  rb_cglyph_symbolizer.define_constructor(Rice::Constructor< mapnik::glyph_symbolizer, std::string, mapnik::expression_ptr >());
  
  rb_cglyph_symbolizer.define_method("face_name", &mapnik::glyph_symbolizer::get_face_name);
  rb_cglyph_symbolizer.define_method("face_name=", &mapnik::glyph_symbolizer::set_face_name);
  
  rb_cglyph_symbolizer.define_method("char", &mapnik::glyph_symbolizer::get_char);
  rb_cglyph_symbolizer.define_method("char=", &mapnik::glyph_symbolizer::set_char);
  
  rb_cglyph_symbolizer.define_method("allow_overlap?", &mapnik::glyph_symbolizer::get_allow_overlap);
  rb_cglyph_symbolizer.define_method("allow_overlap=", &mapnik::glyph_symbolizer::set_allow_overlap);

  rb_cglyph_symbolizer.define_method("displacement", &get_displacement);
  rb_cglyph_symbolizer.define_method("displacement=", &set_displacement);

  rb_cglyph_symbolizer.define_method("avoid_edges?", &mapnik::glyph_symbolizer::get_avoid_edges);
  rb_cglyph_symbolizer.define_method("avoid_edges=", &mapnik::glyph_symbolizer::set_avoid_edges);
  
  rb_cglyph_symbolizer.define_method("halo_fill", &mapnik::glyph_symbolizer::get_halo_fill);
  rb_cglyph_symbolizer.define_method("halo_fill=", &mapnik::glyph_symbolizer::set_halo_fill);

  rb_cglyph_symbolizer.define_method("halo_radius", &mapnik::glyph_symbolizer::get_halo_radius);
  rb_cglyph_symbolizer.define_method("halo_radius=", &mapnik::glyph_symbolizer::set_halo_radius);
  
  rb_cglyph_symbolizer.define_method("size", &mapnik::glyph_symbolizer::get_size);
  rb_cglyph_symbolizer.define_method("size=", &mapnik::glyph_symbolizer::set_size);
  
  rb_cglyph_symbolizer.define_method("angle", &mapnik::glyph_symbolizer::get_angle);
  rb_cglyph_symbolizer.define_method("angle=", &mapnik::glyph_symbolizer::set_angle);
  
  rb_cglyph_symbolizer.define_method("value", &mapnik::glyph_symbolizer::get_value);
  rb_cglyph_symbolizer.define_method("value=", &mapnik::glyph_symbolizer::set_value);
  
  rb_cglyph_symbolizer.define_method("angle_mode", &get_angle_mode);
  rb_cglyph_symbolizer.define_method("angle_mode=", &set_angle_mode);
  
  rb_cglyph_symbolizer.define_method("color", &mapnik::glyph_symbolizer::get_color);
  rb_cglyph_symbolizer.define_method("color=", &mapnik::glyph_symbolizer::set_color);

  // TODO: Colorizer support
  // rb_cglyph_symbolizer.define_method("colorizer", &get_colorizer);
  // rb_cglyph_symbolizer.define_method("colorizer=", &set_colorizer);
}
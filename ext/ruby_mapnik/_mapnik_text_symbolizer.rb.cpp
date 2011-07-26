#include "_mapnik_text_symbolizer.rb.h"

Rice::Object get_anchor(const mapnik::text_symbolizer& t){
  mapnik::position pos = t.get_anchor();
  Rice::Array out;
  out.push(boost::get<0>(pos));
  out.push(boost::get<1>(pos));
  return out;
}

void set_anchor(mapnik::text_symbolizer & t, Rice::Array ary) {
  double x = from_ruby<double>(ary[0]);
  double y = from_ruby<double>(ary[1]);
  
  t.set_anchor(x, y);
}

Rice::Object get_text_displacement(const mapnik::text_symbolizer& t){
  mapnik::position pos = t.get_displacement();
  Rice::Array out;
  out.push(boost::get<0>(pos));
  out.push(boost::get<1>(pos));
  return out;
}

void set_text_displacement(mapnik::text_symbolizer & t, Rice::Array ary){
  double x = from_ruby<double>(ary[0]);
  double y = from_ruby<double>(ary[1]);
  
  t.set_displacement(x,y);
}

mapnik::horizontal_alignment get_text_horizontal_alignment(mapnik::text_symbolizer const & self){
  mapnik::horizontal_alignment alignment = self.get_horizontal_alignment();
  return alignment;
}

void set_text_horizontal_alignment(mapnik::text_symbolizer & self, mapnik::horizontal_alignment val){
  self.set_horizontal_alignment(val);
}

mapnik::justify_alignment get_text_justify_alignment(mapnik::text_symbolizer const & self){
  mapnik::justify_alignment alignment = self.get_justify_alignment();
  return alignment;
}

void set_text_justify_alignment(mapnik::text_symbolizer & self, mapnik::justify_alignment val){
  self.set_justify_alignment(val);
}

mapnik::label_placement_enum get_text_label_placement(mapnik::text_symbolizer const & self){
  mapnik::label_placement_enum alignment = self.get_label_placement();
  return alignment;
}

void set_text_label_placement(mapnik::text_symbolizer & self, mapnik::label_placement_enum val){
  self.set_label_placement(val);
}

mapnik::text_transform get_text_transform(mapnik::text_symbolizer const & self){
  mapnik::text_transform transform = self.get_text_transform();
  return transform;
}

void set_text_transform(mapnik::text_symbolizer & self, mapnik::text_transform val){
  self.set_text_transform(val);
}

mapnik::vertical_alignment get_vertical_alignment(mapnik::text_symbolizer const & self){
  mapnik::vertical_alignment transform = self.get_vertical_alignment();
  return transform;
}

void set_vertical_alignment(mapnik::text_symbolizer & self, mapnik::vertical_alignment val){
  self.set_vertical_alignment(val);
}

void register_text_symbolizer(Rice::Module rb_mapnik){
  Rice::Enum<mapnik::label_placement_enum> label_placement = Rice::define_enum<mapnik::label_placement_enum>("LABEL_PLACEMENT", rb_mapnik);
  label_placement.define_value("LINE_PLACEMENT", mapnik::LINE_PLACEMENT);
  label_placement.define_value("POINT_PLACEMENT", mapnik::POINT_PLACEMENT);
  label_placement.define_value("VERTEX_PLACEMENT", mapnik::VERTEX_PLACEMENT);
  label_placement.define_value("INTERIOR_PLACEMENT", mapnik::INTERIOR_PLACEMENT);

  Rice::Enum<mapnik::vertical_alignment> vertical_alignment = Rice::define_enum<mapnik::vertical_alignment>("VERTICAL_ALIGNMENT", rb_mapnik);
  vertical_alignment.define_value("TOP", mapnik::V_TOP);
  vertical_alignment.define_value("MIDDLE", mapnik::V_MIDDLE);
  vertical_alignment.define_value("BOTTOM", mapnik::V_BOTTOM);
  vertical_alignment.define_value("AUTO", mapnik::V_AUTO);
    
  Rice::Enum<mapnik::horizontal_alignment> horizontal_alignment = Rice::define_enum<mapnik::horizontal_alignment>("HORIZONTAL_ALIGNMENT", rb_mapnik);
  horizontal_alignment.define_value("LEFT", mapnik::H_LEFT);
  horizontal_alignment.define_value("MIDDLE", mapnik::H_MIDDLE);
  horizontal_alignment.define_value("RIGHT", mapnik::H_RIGHT);

  Rice::Enum<mapnik::justify_alignment> justify_alignment_rice = Rice::define_enum<mapnik::justify_alignment>("JUSTIFY_ALIGNMENT", rb_mapnik);
  justify_alignment_rice.define_value("LEFT", mapnik::J_LEFT);
  justify_alignment_rice.define_value("MIDDLE", mapnik::J_MIDDLE);
  justify_alignment_rice.define_value("RIGHT", mapnik::J_RIGHT);
              
  Rice::Enum<mapnik::text_transform> text_transform = Rice::define_enum<mapnik::text_transform>("TEXT_TRANSFORM", rb_mapnik);
  text_transform.define_value("NONE", mapnik::NONE);
  text_transform.define_value("UPPERCASE", mapnik::UPPERCASE);
  text_transform.define_value("LOWERCASE", mapnik::LOWERCASE);
  text_transform.define_value("CAPITALIZE", mapnik::CAPITALIZE);
    
  Rice::Data_Type< mapnik::text_symbolizer > rb_ctext_symbolizer = Rice::define_class_under< mapnik::text_symbolizer >(rb_mapnik, "TextSymbolizer");
  rb_ctext_symbolizer.define_constructor(Rice::Constructor< mapnik::text_symbolizer, mapnik::expression_ptr, std::string, int, mapnik::color >());
  
  rb_ctext_symbolizer.define_method("anchor", &get_anchor);
  rb_ctext_symbolizer.define_method("anchor=", &set_anchor);

  rb_ctext_symbolizer.define_method("allow_overlap?", &mapnik::text_symbolizer::get_allow_overlap);
  rb_ctext_symbolizer.define_method("allow_overlap=", &mapnik::text_symbolizer::set_allow_overlap);

  rb_ctext_symbolizer.define_method("displacement", &get_text_displacement);
  rb_ctext_symbolizer.define_method("displacement=", &set_text_displacement);

  rb_ctext_symbolizer.define_method("avoid_edges?", &mapnik::text_symbolizer::get_avoid_edges);
  rb_ctext_symbolizer.define_method("avoid_edges=", &mapnik::text_symbolizer::set_avoid_edges);
  
  rb_ctext_symbolizer.define_method("character_spacing", &mapnik::text_symbolizer::get_character_spacing);
  rb_ctext_symbolizer.define_method("character_spacing=", &mapnik::text_symbolizer::set_character_spacing);
  
  rb_ctext_symbolizer.define_method("face_name", &mapnik::text_symbolizer::get_face_name);
  rb_ctext_symbolizer.define_method("face_name=", &mapnik::text_symbolizer::set_face_name);
  
  rb_ctext_symbolizer.define_method("fill", &mapnik::text_symbolizer::get_fill);
  rb_ctext_symbolizer.define_method("fill=", &mapnik::text_symbolizer::set_fill);

  // TODO: Need fontset
  // rb_ctext_symbolizer.define_method("fontset", &mapnik::text_symbolizer::get_fontset);
  // rb_ctext_symbolizer.define_method("fontset=", &mapnik::text_symbolizer::set_fontset);

  rb_ctext_symbolizer.define_method("force_odd_labels?", &mapnik::text_symbolizer::get_force_odd_labels);
  rb_ctext_symbolizer.define_method("force_odd_labels=", &mapnik::text_symbolizer::set_force_odd_labels);
  
  rb_ctext_symbolizer.define_method("halo_fill", &mapnik::text_symbolizer::get_halo_fill);
  rb_ctext_symbolizer.define_method("halo_fill=", &mapnik::text_symbolizer::set_halo_fill);

  rb_ctext_symbolizer.define_method("halo_radius", &mapnik::text_symbolizer::get_halo_radius);
  rb_ctext_symbolizer.define_method("halo_radius=", &mapnik::text_symbolizer::set_halo_radius);

  rb_ctext_symbolizer.define_method("horizontal_alignment", &get_text_horizontal_alignment);
  rb_ctext_symbolizer.define_method("horizontal_alignment=", &set_text_horizontal_alignment);

  rb_ctext_symbolizer.define_method("justify_alignment", &get_text_justify_alignment);
  rb_ctext_symbolizer.define_method("justify_alignment=", &set_text_justify_alignment);

  rb_ctext_symbolizer.define_method("label_placement", &get_text_label_placement);
  rb_ctext_symbolizer.define_method("label_placement=", &set_text_label_placement);
  
  rb_ctext_symbolizer.define_method("label_position_tolerance", &mapnik::text_symbolizer::get_label_position_tolerance);
  rb_ctext_symbolizer.define_method("label_position_tolerance=", &mapnik::text_symbolizer::set_label_position_tolerance);
  
  rb_ctext_symbolizer.define_method("label_spacing", &mapnik::text_symbolizer::get_label_spacing);
  rb_ctext_symbolizer.define_method("label_spacing=", &mapnik::text_symbolizer::set_label_spacing);
  
  rb_ctext_symbolizer.define_method("line_spacing", &mapnik::text_symbolizer::get_line_spacing);
  rb_ctext_symbolizer.define_method("line_spacing=", &mapnik::text_symbolizer::set_line_spacing);
  
  rb_ctext_symbolizer.define_method("max_char_angle_delta", &mapnik::text_symbolizer::get_max_char_angle_delta);
  rb_ctext_symbolizer.define_method("max_char_angle_delta=", &mapnik::text_symbolizer::set_max_char_angle_delta);
  
  rb_ctext_symbolizer.define_method("minimum_distance", &mapnik::text_symbolizer::get_minimum_distance);
  rb_ctext_symbolizer.define_method("minimum_distance=", &mapnik::text_symbolizer::set_minimum_distance);
  
  rb_ctext_symbolizer.define_method("minimum_padding", &mapnik::text_symbolizer::get_minimum_padding);
  rb_ctext_symbolizer.define_method("minimum_padding=", &mapnik::text_symbolizer::set_minimum_padding);
  
  rb_ctext_symbolizer.define_method("name", &mapnik::text_symbolizer::get_name);
  rb_ctext_symbolizer.define_method("name=", &mapnik::text_symbolizer::set_name);
  
  rb_ctext_symbolizer.define_method("opacity", &mapnik::text_symbolizer::get_text_opacity);
  rb_ctext_symbolizer.define_method("opacity=", &mapnik::text_symbolizer::set_text_opacity);
  
  rb_ctext_symbolizer.define_method("text_transform", &get_text_transform);
  rb_ctext_symbolizer.define_method("text_transform=", &set_text_transform);  
  
  rb_ctext_symbolizer.define_method("ratio", &mapnik::text_symbolizer::get_text_ratio);
  rb_ctext_symbolizer.define_method("ratio=", &mapnik::text_symbolizer::set_text_ratio);
  
  rb_ctext_symbolizer.define_method("size", &mapnik::text_symbolizer::get_text_size);
  rb_ctext_symbolizer.define_method("size=", &mapnik::text_symbolizer::set_text_size);
  
  rb_ctext_symbolizer.define_method("vertical_alignment", &get_vertical_alignment);
  rb_ctext_symbolizer.define_method("vertical_alignment=", &set_vertical_alignment);
  
  rb_ctext_symbolizer.define_method("wrap_width", &mapnik::text_symbolizer::get_wrap_width);
  rb_ctext_symbolizer.define_method("wrap_width=", &mapnik::text_symbolizer::set_wrap_width);
  
  rb_ctext_symbolizer.define_method("wrap_character", &mapnik::text_symbolizer::get_wrap_char_string);
  rb_ctext_symbolizer.define_method("wrap_character=", &mapnik::text_symbolizer::set_wrap_char_from_string);
  
  rb_ctext_symbolizer.define_method("wrap_before", &mapnik::text_symbolizer::get_wrap_before);
  rb_ctext_symbolizer.define_method("wrap_before=", &mapnik::text_symbolizer::set_wrap_before);
  
};


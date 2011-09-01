#include "_mapnik_glyph_symbolizer.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>
  
// Mapnik
#include <mapnik/glyph_symbolizer.hpp>

namespace {
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
}

void register_glyph_symbolizer(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Enum<mapnik::angle_mode_enum> angle_enum = Rice::define_enum<mapnik::angle_mode_enum>("AngleMode", rb_mapnik);
  angle_enum.define_value("AZIMUTH", mapnik::AZIMUTH);
  angle_enum.define_value("TRIGONOMETRIC", mapnik::TRIGONOMETRIC);
  

  Rice::Data_Type< mapnik::glyph_symbolizer > rb_cglyph_symbolizer = Rice::define_class_under< mapnik::glyph_symbolizer >(rb_mapnik, "GlyphSymbolizer");
  
  /*
  * Document-method: new
  * call-seq:
  *   new(font_name, expression)
  * 
  * @param [String] font_name Name of a font registered with the FontEngine
  * @param [Mapnik::Expression] expression The value expression
  *
  * Returns a new Mapnik::GlyphSymbolizer
  */
  rb_cglyph_symbolizer.define_constructor(Rice::Constructor< mapnik::glyph_symbolizer, std::string, mapnik::expression_ptr >());
  
  /*
  * Document-method: face_name
  * @return [String] the font face name
  */
  rb_cglyph_symbolizer.define_method("face_name", &mapnik::glyph_symbolizer::get_face_name);
  
   /*
  * Document-method: face_name=
  * call-seq:
  *   face_name=(new_face_name)
  * @param [String] The new font face name
  * @return [nil]
  */
  rb_cglyph_symbolizer.define_method("face_name=", &mapnik::glyph_symbolizer::set_face_name);
  
   /*
  * Document-method: char
  * @return [String]
  */
  rb_cglyph_symbolizer.define_method("char", &mapnik::glyph_symbolizer::get_char);
  
  /*
  * Document-method: char=
  * call-seq:
  *   char=(new_char)
  * @param [String]
  * @return [nil]
  */
  rb_cglyph_symbolizer.define_method("char=", &mapnik::glyph_symbolizer::set_char);
  
   /*
  * Document-method: allow_overlap?
  * @return [Boolean] Whether or not glyphs should overlap
  */
  rb_cglyph_symbolizer.define_method("allow_overlap?", &mapnik::glyph_symbolizer::get_allow_overlap);
  
  /*
  * Document-method: allow_overlap=
  * call-seq:
  *  allow_overlap=(new_overlap_value)
  * @param [Boolean] 
  * @return [nil]
  */
  rb_cglyph_symbolizer.define_method("allow_overlap=", &mapnik::glyph_symbolizer::set_allow_overlap);

  /*
  * Document-method: displacement?
  * @return [Array] Two element array of the x-y displacement
  */
  rb_cglyph_symbolizer.define_method("displacement", &get_displacement);
  
  /*
  * Document-method: displacement=
  * call-seq:
  *  displacement=(new_displacement_values)
  * @param [Array] array in the format [x,y] 
  * @return [nil]
  */
  rb_cglyph_symbolizer.define_method("displacement=", &set_displacement);

  /*
  * Document-method: avoid_edges?
  * @return [Boolean] Whether or not glyphs should avoid edges
  */
  rb_cglyph_symbolizer.define_method("avoid_edges?", &mapnik::glyph_symbolizer::get_avoid_edges);
  
  /*
  * Document-method: avoid_edges=
  * call-seq:
  *  avoid_edges=(new_value)
  * @param [Boolean] 
  * @return [nil]
  */
  rb_cglyph_symbolizer.define_method("avoid_edges=", &mapnik::glyph_symbolizer::set_avoid_edges);
  
  /*
  * Document-method: halo_fill
  * @return [Mapnik::Color] Color of the halo around the text
  */
  rb_cglyph_symbolizer.define_method("halo_fill", &mapnik::glyph_symbolizer::get_halo_fill);
  
  /*
  * Document-method: halo_fill=
  * call-seq:
  *  halo_fill=(color)
  * @param [Mapnik::Color] The color of the halo around the text. 
  * @return [nil]
  */
  rb_cglyph_symbolizer.define_method("halo_fill=", &mapnik::glyph_symbolizer::set_halo_fill);

  /*
  * Document-method: halo_radius
  * @return [Integer] Thickness of the text halo
  */
  rb_cglyph_symbolizer.define_method("halo_radius", &mapnik::glyph_symbolizer::get_halo_radius);
  
  /*
  * Document-method: halo_radius=
  * call-seq:
  *  halo_fill=(color)
  * @param [Integer] The thickness of the text halo 
  * @return [nil]
  */
  rb_cglyph_symbolizer.define_method("halo_radius=", &mapnik::glyph_symbolizer::set_halo_radius);
  
  /*
  * Document-method: size
  * @return [Mapnik::Expression] Font size of the glyph
  */
  rb_cglyph_symbolizer.define_method("size", &mapnik::glyph_symbolizer::get_size);
  
  /*
  * Document-method: size=
  * call-seq:
  *  size=(size_expression)
  * @param [Mapnik::Expression] The new size expression
  * @return [nil]
  */
  rb_cglyph_symbolizer.define_method("size=", &mapnik::glyph_symbolizer::set_size);
  
  /*
  * Document-method: angle
  * @return [Mapnik::Expression]
  */
  rb_cglyph_symbolizer.define_method("angle", &mapnik::glyph_symbolizer::get_angle);
  
  /*
  * Document-method: angle=
  * call-seq:
  *  angle=(angle_expression)
  * @param [Mapnik::Expression]
  * @return [nil]
  */
  rb_cglyph_symbolizer.define_method("angle=", &mapnik::glyph_symbolizer::set_angle);
  
   /*
  * Document-method: value
  * @return [Mapnik::Expression]
  */
  rb_cglyph_symbolizer.define_method("value", &mapnik::glyph_symbolizer::get_value);
  
  /*
  * Document-method: value=
  * call-seq:
  *  value=(value_expression)
  * @param [Mapnik::Expression]
  * @return [nil]
  */
  rb_cglyph_symbolizer.define_method("value=", &mapnik::glyph_symbolizer::set_value);
  

  rb_cglyph_symbolizer.define_method("angle_mode", &get_angle_mode);
  rb_cglyph_symbolizer.define_method("angle_mode=", &set_angle_mode);
  
 /*
  * Document-method: color
  * @return [Mapnik::Color] Color of the text
  */
  rb_cglyph_symbolizer.define_method("color", &mapnik::glyph_symbolizer::get_color);
  
  /*
  * Document-method: color=
  * call-seq:
  *  color=(color)
  * @param [Mapnik::Color] The color of the text. 
  * @return [nil]
  */
  rb_cglyph_symbolizer.define_method("color=", &mapnik::glyph_symbolizer::set_color);

}
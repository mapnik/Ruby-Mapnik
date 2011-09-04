#include "_mapnik_polygon_pattern_symbolizer.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>

// Mapnik
#include <mapnik/polygon_pattern_symbolizer.hpp>

namespace {

  const std::string get_filename(mapnik::polygon_pattern_symbolizer const& t) { 
    return mapnik::path_processor_type::to_string(*t.get_filename()); 
  }

  void set_filename(mapnik::polygon_pattern_symbolizer & t, std::string const& file_expr) { 
    t.set_filename(mapnik::parse_path(file_expr)); 
  }

  mapnik::pattern_alignment_enum get_alignment(mapnik::polygon_pattern_symbolizer const& t){
    return t.get_alignment();
  }

  void set_alignment(mapnik::polygon_pattern_symbolizer & t, mapnik::pattern_alignment_enum value){
    t.set_alignment(value);
  }

}

void register_polygon_pattern_symbolizer(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Enum<mapnik::pattern_alignment_enum> alignment_enum = Rice::define_enum<mapnik::pattern_alignment_enum>("PatternAlignment", rb_mapnik);
  
  alignment_enum.define_value("LOCAL",mapnik::LOCAL_ALIGNMENT);
  alignment_enum.define_value("GLOBAL",mapnik::GLOBAL_ALIGNMENT);
  

  Rice::Data_Type< mapnik::polygon_pattern_symbolizer > rb_cpolygon_pattern_symbolizer = Rice::define_class_under< mapnik::polygon_pattern_symbolizer >(rb_mapnik, "PolygonPatternSymbolizer");
  
  /*
  * Document-method: new
  * call-seq:
  *   new(path_expression)
  * @param [Mapnik::PathExpression] path_expression file to pattern
  * @return [Mapnik::PolygonPatternSymbolizer]
  */
  rb_cpolygon_pattern_symbolizer.define_constructor(Rice::Constructor< mapnik::polygon_pattern_symbolizer, mapnik::path_expression_ptr>());
  
  /*
  * Document-method: filename
  * @return [String]
  */
  rb_cpolygon_pattern_symbolizer.define_method("filename", &get_filename);
  
  /*
  * Document-method: filename=
  * call-seq:
  *   filename=(new_filename)
  * @param [String] new_filename
  * @return [nil]
  */
  rb_cpolygon_pattern_symbolizer.define_method("filename=", &set_filename);
  
  rb_cpolygon_pattern_symbolizer.define_method("alignment", &get_alignment);
  rb_cpolygon_pattern_symbolizer.define_method("alignment=", &set_alignment);
  
}
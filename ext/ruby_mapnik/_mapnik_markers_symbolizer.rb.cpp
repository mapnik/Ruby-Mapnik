#include "_mapnik_markers_symbolizer.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>

// Mapnik
#include <mapnik/markers_symbolizer.hpp>

namespace {
  const std::string get_filename(mapnik::markers_symbolizer const& t) { 
      return mapnik::path_processor_type::to_string(*t.get_filename()); 
  }

  void set_filename(mapnik::markers_symbolizer & t, std::string const& file_expr) { 
      t.set_filename(mapnik::parse_path(file_expr)); 
  }

  const double get_markers_opacity(mapnik::markers_symbolizer const& t){
    return t.get_opacity();
  }

  void set_markers_opacity(mapnik::markers_symbolizer & t, double value){
    t.set_opacity(value);
  }
}
void register_markers_symbolizer(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::markers_symbolizer > rb_cmarkers_symbolizer = Rice::define_class_under< mapnik::markers_symbolizer >(rb_mapnik, "MarkersSymbolizer");
  
  /*
  * Document-method: new
  * call-seq:
  *  new(path_expression)
  * @param [Mapnik::PathExpression]
  * @return [Mapnik::MarkersSymbolizer]
  */
  rb_cmarkers_symbolizer.define_constructor(Rice::Constructor< mapnik::markers_symbolizer, mapnik::path_expression_ptr>());
  
  /*
  * Document-method: filename
  * @return [String]
  */
  rb_cmarkers_symbolizer.define_method("filename", &get_filename);
  
  /*
  * Document-method: filename=
  * call-seq:
  *   filename=(new_filename)
  * @param [String] filename
  * @return [nil]
  */
  rb_cmarkers_symbolizer.define_method("filename=", &set_filename);
  
  /*
  * Document-method: allow_overlap?
  * @return [Boolean]
  */
  rb_cmarkers_symbolizer.define_method("allow_overlap?", &mapnik::markers_symbolizer::get_allow_overlap);
  
  /*
  * Document-method: allow_overlap=
  * call-seq:
  *   allow_overlap=(new_value)
  * @param [Boolean] new_value
  * @return [nil]
  */
  rb_cmarkers_symbolizer.define_method("allow_overlap=", &mapnik::markers_symbolizer::set_allow_overlap);
  
  /*
  * Document-method: spacing
  * @return [Integer]
  */
  rb_cmarkers_symbolizer.define_method("spacing", &mapnik::markers_symbolizer::get_spacing);
  
  /*
  * Document-method: spacing=
  * call-seq:
  *   spacing=(new_spacing_value)
  * @param [Integer] new_spacing_value
  * @return [nil]
  */
  rb_cmarkers_symbolizer.define_method("spacing=", &mapnik::markers_symbolizer::set_spacing);
  
  /*
  * Document-method: max_error
  * @return [Integer]
  */
  rb_cmarkers_symbolizer.define_method("max_error", &mapnik::markers_symbolizer::get_max_error);
  
  /*
  * Document-method:max_error=
  * call-seq: 
  *   max_error=(new_value)
  * @param [Integer] new_value
  * @return [nil]
  */
  rb_cmarkers_symbolizer.define_method("max_error=", &mapnik::markers_symbolizer::set_max_error);
  
  /*
  * Document-method: opacity
  * @return [Float]
  */
  rb_cmarkers_symbolizer.define_method("opacity", &get_markers_opacity);
  
  /*
  * Document-method: opacity=
  * call-seq:
  *   opacity=(new_value)
  * @param [Float]
  * @return [nil]
  */
  rb_cmarkers_symbolizer.define_method("opacity=", &set_markers_opacity);
  
}
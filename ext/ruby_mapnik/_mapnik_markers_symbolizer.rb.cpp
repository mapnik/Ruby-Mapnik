#include "_mapnik_markers_symbolizer.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>

// Mapnik
#include <mapnik/markers_symbolizer.hpp>

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

void register_markers_symbolizer(Rice::Module rb_mapnik){
  Rice::Data_Type< mapnik::markers_symbolizer > rb_cmarkers_symbolizer = Rice::define_class_under< mapnik::markers_symbolizer >(rb_mapnik, "MarkersSymbolizer");
  rb_cmarkers_symbolizer.define_constructor(Rice::Constructor< mapnik::markers_symbolizer, mapnik::path_expression_ptr>());
  
  rb_cmarkers_symbolizer.define_method("filename", &get_filename);
  rb_cmarkers_symbolizer.define_method("filename=", &set_filename);
  
  rb_cmarkers_symbolizer.define_method("allow_overlap?", &mapnik::markers_symbolizer::get_allow_overlap);
  rb_cmarkers_symbolizer.define_method("allow_overlap=", &mapnik::markers_symbolizer::set_allow_overlap);
  
  rb_cmarkers_symbolizer.define_method("spacing", &mapnik::markers_symbolizer::get_spacing);
  rb_cmarkers_symbolizer.define_method("spacing=", &mapnik::markers_symbolizer::set_spacing);
  
  rb_cmarkers_symbolizer.define_method("max_error", &mapnik::markers_symbolizer::get_max_error);
  rb_cmarkers_symbolizer.define_method("max_error=", &mapnik::markers_symbolizer::set_max_error);
  
  rb_cmarkers_symbolizer.define_method("opacity", &get_markers_opacity);
  rb_cmarkers_symbolizer.define_method("opacity=", &set_markers_opacity);
  
  
}
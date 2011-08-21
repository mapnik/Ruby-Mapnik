#include "_mapnik_line_pattern_symbolizer.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>

// Mapnik
#include <mapnik/line_pattern_symbolizer.hpp>

const std::string get_filename(mapnik::line_pattern_symbolizer const& t) { 
  return mapnik::path_processor_type::to_string(*t.get_filename()); 
}

void set_filename(mapnik::line_pattern_symbolizer & t, std::string const& file_expr) { 
  t.set_filename(mapnik::parse_path(file_expr)); 
}

void register_line_pattern_symbolizer(Rice::Module rb_mapnik){  
  Rice::Data_Type< mapnik::line_pattern_symbolizer > rb_cline_pattern_symbolizer = Rice::define_class_under< mapnik::line_pattern_symbolizer >(rb_mapnik, "LinePatternSymbolizer");
  rb_cline_pattern_symbolizer.define_constructor(Rice::Constructor< mapnik::line_pattern_symbolizer, mapnik::path_expression_ptr>());
  
  rb_cline_pattern_symbolizer.define_method("filename", &get_filename);
  rb_cline_pattern_symbolizer.define_method("filename=", &set_filename);
  
}
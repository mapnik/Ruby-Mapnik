#include "_mapnik_line_symbolizer.rb.h"

void register_line_symbolizer(Rice::Module rb_mapnik){
  
  Rice::Data_Type< mapnik::line_symbolizer > rb_cline_symbolizer = Rice::define_class_under< mapnik::line_symbolizer >(rb_mapnik, "LineSymbolizer");
  rb_cline_symbolizer.define_constructor(Rice::Constructor< mapnik::line_symbolizer >());
  
  rb_cline_symbolizer.define_method("stroke", &mapnik::line_symbolizer::get_stroke);
  rb_cline_symbolizer.define_method("stroke=", &mapnik::line_symbolizer::set_stroke, Rice::Arg("new_stroke"));

}

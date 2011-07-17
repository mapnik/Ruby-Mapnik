#include "_mapnik_polygon_symbolizer.rb.h"

void register_polygon_symbolizer(Rice::Module rb_mapnik){
  Rice::Data_Type< mapnik::polygon_symbolizer > rb_cpolygon_symbolizer = Rice::define_class_under< mapnik::polygon_symbolizer >(rb_mapnik, "PolygonSymbolizer");
  rb_cpolygon_symbolizer.define_constructor(Rice::Constructor< mapnik::polygon_symbolizer >());
  
  rb_cpolygon_symbolizer.define_method("fill", &mapnik::polygon_symbolizer::get_fill);
  rb_cpolygon_symbolizer.define_method("fill=", &mapnik::polygon_symbolizer::set_fill, Rice::Arg("new_color"));
  
  rb_cpolygon_symbolizer.define_method("opacity", &mapnik::polygon_symbolizer::get_opacity);
  rb_cpolygon_symbolizer.define_method("opacity=", &mapnik::polygon_symbolizer::set_opacity, Rice::Arg("new_opacity"));
  
  rb_cpolygon_symbolizer.define_method("gamma", &mapnik::polygon_symbolizer::get_gamma);
  rb_cpolygon_symbolizer.define_method("gamma=", &mapnik::polygon_symbolizer::set_gamma, Rice::Arg("new_gamma"));

};

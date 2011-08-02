#include "_mapnik_raster_symbolizer.rb.h"

void register_raster_symbolizer(Rice::Module rb_mapnik){
  Rice::Data_Type< mapnik::raster_symbolizer > rb_craster_symbolizer = Rice::define_class_under< mapnik::raster_symbolizer >(rb_mapnik, "RasterSymbolizer");
  rb_craster_symbolizer.define_constructor(Rice::Constructor< mapnik::raster_symbolizer >());
  
  rb_craster_symbolizer.define_method("mode", &mapnik::raster_symbolizer::get_mode);
  rb_craster_symbolizer.define_method("mode=", &mapnik::raster_symbolizer::set_mode);
  
  rb_craster_symbolizer.define_method("scaling", &mapnik::raster_symbolizer::get_scaling);
  rb_craster_symbolizer.define_method("scaling=", &mapnik::raster_symbolizer::set_scaling);
  
  rb_craster_symbolizer.define_method("opacity", &mapnik::raster_symbolizer::get_opacity);
  rb_craster_symbolizer.define_method("opacity=", &mapnik::raster_symbolizer::set_opacity);
  
  
  rb_craster_symbolizer.define_method("filter_factor", &mapnik::raster_symbolizer::get_filter_factor);
  rb_craster_symbolizer.define_method("filter_factor=", &mapnik::raster_symbolizer::set_filter_factor);
  
}
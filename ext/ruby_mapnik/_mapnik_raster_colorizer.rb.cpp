#include "_mapnik_raster_colorizer.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>

// Mapnik
#include <mapnik/raster_colorizer.hpp>

mapnik::colorizer_mode_enum get_default_colorizer_mode(mapnik::raster_colorizer & self){
  mapnik::colorizer_mode_enum out = self.get_default_mode();
  return out;
}

void set_default_colorizer_mode(mapnik::raster_colorizer & self, mapnik::colorizer_mode_enum value){
  self.set_default_mode(value);
}

mapnik::colorizer_mode_enum get_colorizer_stop_mode(mapnik::colorizer_stop & self){
  mapnik::colorizer_mode_enum out = self.get_mode_enum();
  return out;
}

void set_colorizer_stop_mode(mapnik::colorizer_stop & self, mapnik::colorizer_mode_enum value){
  self.set_mode_enum(value);
}

Rice::Array get_raster_colorizer_stops(mapnik::raster_colorizer & self){
  mapnik::colorizer_stops stops = self.get_stops();
  return Rice::Array(stops.begin(), stops.end());
}

void add_raster_colorizer_stop(mapnik::raster_colorizer & self, mapnik::colorizer_stop stop){
  self.add_stop(stop);
}

bool check_colorizer_stop_equality(mapnik::colorizer_stop stop_l, mapnik::colorizer_stop stop_r){
  return stop_l == stop_r;
}

void register_raster_colorizer(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::raster_colorizer > rb_craster_colorizer = Rice::define_class_under< mapnik::raster_colorizer >(rb_mapnik, "RasterColorizer");
  rb_craster_colorizer.define_constructor(Rice::Constructor< mapnik::raster_colorizer >());

  rb_craster_colorizer.define_method("default_color", &mapnik::raster_colorizer::get_default_color);
  rb_craster_colorizer.define_method("default_color=", &mapnik::raster_colorizer::set_default_color);
  
  rb_craster_colorizer.define_method("default_mode", &get_default_colorizer_mode);
  rb_craster_colorizer.define_method("default_mode=", &set_default_colorizer_mode);
  
  rb_craster_colorizer.define_method("epsilon", &mapnik::raster_colorizer::get_epsilon);
  rb_craster_colorizer.define_method("epsilon=", &mapnik::raster_colorizer::set_epsilon);
  
  rb_craster_colorizer.define_method("__stops__", &get_raster_colorizer_stops);
  rb_craster_colorizer.define_method("__add_stop__", &add_raster_colorizer_stop);
  
  Rice::Enum<mapnik::colorizer_mode_enum> cm_colorizer_mode = Rice::define_enum<mapnik::colorizer_mode_enum>("ColorizerMode", rb_mapnik);  
  cm_colorizer_mode.define_value("INHERIT", mapnik::COLORIZER_INHERIT);
  cm_colorizer_mode.define_value("LINEAR", mapnik::COLORIZER_LINEAR);
  cm_colorizer_mode.define_value("DISCRETE", mapnik::COLORIZER_DISCRETE);
  cm_colorizer_mode.define_value("EXACT", mapnik::COLORIZER_EXACT);
  
  Rice::Data_Type< mapnik::colorizer_stop > rb_ccolorizer_stop = Rice::define_class_under< mapnik::colorizer_stop >(rb_mapnik, "ColorizerStop");
  rb_ccolorizer_stop.define_constructor(Rice::Constructor< mapnik::colorizer_stop, float, mapnik::colorizer_mode_enum, mapnik::color >());
  
  rb_ccolorizer_stop.define_method("color", &mapnik::colorizer_stop::get_color);
  rb_ccolorizer_stop.define_method("color=", &mapnik::colorizer_stop::set_color);
  
  rb_ccolorizer_stop.define_method("value", &mapnik::colorizer_stop::get_value);
  rb_ccolorizer_stop.define_method("value=", &mapnik::colorizer_stop::set_value);
  
  rb_ccolorizer_stop.define_method("mode", &get_colorizer_stop_mode);
  rb_ccolorizer_stop.define_method("mode=", &set_colorizer_stop_mode);
  
  rb_ccolorizer_stop.define_method("==", &check_colorizer_stop_equality);
  
}
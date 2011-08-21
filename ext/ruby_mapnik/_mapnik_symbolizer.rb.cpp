#include "_mapnik_symbolizer.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>

// Mapnik
#include <mapnik/rule.hpp>

// TODO: Hackasaurus!
mapnik::symbolizer from_subtype(Rice::Object obj){
  mapnik::symbolizer out;
  std::string class_name = obj.class_of().to_s().str();
  if(class_name == "Mapnik::PolygonSymbolizer") {
    out = mapnik::symbolizer(from_ruby<mapnik::polygon_symbolizer>(obj));
  } else if(class_name == "Mapnik::LineSymbolizer") {
    out = mapnik::symbolizer(from_ruby<mapnik::line_symbolizer>(obj));
  } else if(class_name == "Mapnik::TextSymbolizer"){
    out = mapnik::symbolizer(from_ruby<mapnik::text_symbolizer>(obj));
  } else if(class_name == "Mapnik::GlyphSymbolizer"){
    out = mapnik::symbolizer(from_ruby<mapnik::glyph_symbolizer>(obj));
  } else if(class_name == "Mapnik::LinePatternSymbolizer"){
    out = mapnik::symbolizer(from_ruby<mapnik::line_pattern_symbolizer>(obj));
  } else if(class_name == "Mapnik::MarkersSymbolizer"){
    out = mapnik::symbolizer(from_ruby<mapnik::markers_symbolizer>(obj));
  } else if(class_name == "Mapnik::PointSymbolizer") {
    out = mapnik::symbolizer(from_ruby<mapnik::point_symbolizer>(obj));
  } else if(class_name == "Mapnik::PolygonPatternSymbolizer"){
    out = mapnik::symbolizer(from_ruby<mapnik::polygon_pattern_symbolizer>(obj));
  } else if(class_name == "Mapnik::RasterSymbolizer"){
    out = mapnik::symbolizer(from_ruby<mapnik::raster_symbolizer>(obj));
  } else if(class_name == "Mapnik::ShieldSymbolizer"){
    out = mapnik::symbolizer(from_ruby<mapnik::shield_symbolizer>(obj));
  }
  return out;
}

void register_symbolizer(Rice::Module rb_mapnik){
  Rice::Data_Type< mapnik::symbolizer > rb_csymbolizer = Rice::define_class_under< mapnik::symbolizer >(rb_mapnik, "Symbolizer");
  rb_csymbolizer.define_singleton_method("from_subtype", &from_subtype, Rice::Arg("obj"));
}
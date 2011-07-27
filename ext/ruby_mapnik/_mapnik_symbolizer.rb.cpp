#include "_mapnik_symbolizer.rb.h"

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
  }
  return out;
}

void register_symbolizer(Rice::Module rb_mapnik){
  Rice::Data_Type< mapnik::symbolizer > rb_csymbolizer = Rice::define_class_under< mapnik::symbolizer >(rb_mapnik, "Symbolizer");
  rb_csymbolizer.define_singleton_method("from_subtype", &from_subtype, Rice::Arg("obj"));
}
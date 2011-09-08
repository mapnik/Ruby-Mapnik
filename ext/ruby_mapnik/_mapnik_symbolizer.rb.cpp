/*****************************************************************************
Copyright (C) 2011 Elliot Laster

Permission is hereby granted, free of charge, to any person obtaining a copy of 
this software and associated documentation files (the ‘Software’), to deal in 
the Software without restriction, including without limitation the rights to 
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all 
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED ‘AS IS’, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
SOFTWARE.
 *****************************************************************************/
#include "_mapnik_symbolizer.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>

// Mapnik
#include <mapnik/rule.hpp>

namespace {

  // TODO: This is just terrible...
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

}
void register_symbolizer(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::symbolizer > rb_csymbolizer = Rice::define_class_under< mapnik::symbolizer >(rb_mapnik, "Symbolizer");
  
  /*
  * Document-method: from_subtype
  * call-seq:
  *   from_subtype(symbolizer)
  * @return [Mapnik::Symbolizer]
  */
  rb_csymbolizer.define_singleton_method("from_subtype", &from_subtype, Rice::Arg("obj"));
}
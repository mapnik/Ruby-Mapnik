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
#include "_mapnik.h"

void register_mapnik(){
  Rice::Module rb_mapnik = Rice::define_module("Mapnik");
  
  register_color(rb_mapnik);
  register_coord(rb_mapnik);
  register_datasource(rb_mapnik);
  register_datasource_cache(rb_mapnik);
  register_envelope(rb_mapnik);
  register_feature(rb_mapnik);
  register_geometry(rb_mapnik);
  register_polygon_symbolizer(rb_mapnik);
  register_line_symbolizer(rb_mapnik);
  register_stroke(rb_mapnik);
  register_rule(rb_mapnik);
  register_expression(rb_mapnik);
  register_symbolizer(rb_mapnik);
  register_style(rb_mapnik);
  register_layer(rb_mapnik);
  register_map(rb_mapnik);
  register_projection(rb_mapnik);
  register_text_symbolizer(rb_mapnik);
  register_font_engine(rb_mapnik);
  register_raster_symbolizer(rb_mapnik);
  register_raster_colorizer(rb_mapnik);
  register_point_symbolizer(rb_mapnik);
  register_polygon_pattern_symbolizer(rb_mapnik);
  register_line_pattern_symbolizer(rb_mapnik);
  register_markers_symbolizer(rb_mapnik);
  register_shield_symbolizer(rb_mapnik);
}
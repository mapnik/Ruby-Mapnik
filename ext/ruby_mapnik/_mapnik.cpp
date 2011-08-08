/*****************************************************************************
 * 
 * Copyright (C) 2011 Elliot Laster
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
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
  register_glyph_symbolizer(rb_mapnik);
  register_line_pattern_symbolizer(rb_mapnik);
  register_markers_symbolizer(rb_mapnik);
  register_shield_symbolizer(rb_mapnik);
}
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
#ifndef mapnik_HPP
#define mapnik_HPP

  // Rice
#include <rice/Enum.hpp>
#include <rice/Object.hpp>
#include <rice/Data_Type.hpp>
#include <rice/Data_Object.hpp>
#include <rice/Allocation_Strategies.hpp>
#include <rice/Module.hpp>
#include <rice/Enum.hpp>

// Ruby Mapnik
#include "_mapnik_color.rb.h"
#include "_mapnik_coord.rb.h"
#include "_mapnik_datasource.rb.h"
#include "_mapnik_datasource_cache.rb.h"
#include "_mapnik_envelope.rb.h"
#include "_mapnik_feature.rb.h"
#include "_mapnik_geometry.rb.h"
 
#include "_mapnik_polygon_symbolizer.rb.h" 
#include "_mapnik_line_symbolizer.rb.h" 
#include "_mapnik_stroke.rb.h" 
#include "_mapnik_rule.rb.h"

#include "_mapnik_expression.rb.h"
#include "_mapnik_symbolizer.rb.h"
#include "_mapnik_style.rb.h" 
#include "_mapnik_layer.rb.h" 
#include "_mapnik_map.rb.h" 
 
#include "_mapnik_projection.rb.h" 
#include "_mapnik_text_symbolizer.rb.h" 
#include "_mapnik_font_engine.rb.h" 
#include "_mapnik_raster_symbolizer.rb.h"
#include "_mapnik_raster_colorizer.rb.h"
#include "_mapnik_point_symbolizer.rb.h"
#include "_mapnik_polygon_pattern_symbolizer.rb.h"
#include "_mapnik_line_pattern_symbolizer.rb.h" 
#include "_mapnik_markers_symbolizer.rb.h" 
#include "_mapnik_shield_symbolizer.rb.h"  
 
void register_mapnik();

#endif
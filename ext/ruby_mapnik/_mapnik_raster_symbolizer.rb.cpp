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
#include "_mapnik_raster_symbolizer.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>

// Mapnik
#include <mapnik/raster_symbolizer.hpp>

void register_raster_symbolizer(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
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
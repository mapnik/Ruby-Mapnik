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
#include <mapnik/version.hpp>
#include <mapnik/raster_symbolizer.hpp>

#if MAPNIK_VERSION >= 200100
  #include <mapnik/image_scaling.hpp>
#endif

void register_raster_symbolizer(Rice::Module rb_mapnik){

#if MAPNIK_VERSION >= 200100  
  Rice::Enum<mapnik::scaling_method_e> scaling_enum = Rice::define_enum<mapnik::scaling_method_e>("ScalingMethod", rb_mapnik);
  
  scaling_enum.define_value("NEAR",mapnik::SCALING_NEAR);
  scaling_enum.define_value("BILINEAR",mapnik::SCALING_BILINEAR);
  scaling_enum.define_value("BICUBIC", mapnik::SCALING_BICUBIC);
  scaling_enum.define_value("SPLINE16", mapnik::SCALING_SPLINE16);
  scaling_enum.define_value("SPLINE36", mapnik::SCALING_SPLINE36);
  scaling_enum.define_value("HANNING", mapnik::SCALING_HANNING);
  scaling_enum.define_value("HAMMING", mapnik::SCALING_HAMMING);
  scaling_enum.define_value("HERMITE", mapnik::SCALING_HERMITE);
  scaling_enum.define_value("KAISER", mapnik::SCALING_KAISER);
  scaling_enum.define_value("QUADRIC", mapnik::SCALING_QUADRIC);
  scaling_enum.define_value("CATROM", mapnik::SCALING_CATROM);
  scaling_enum.define_value("GAUSSIAN", mapnik::SCALING_GAUSSIAN);
  scaling_enum.define_value("BESSEL", mapnik::SCALING_BESSEL);
  scaling_enum.define_value("MITCHELL", mapnik::SCALING_MITCHELL);
  scaling_enum.define_value("SINC", mapnik::SCALING_SINC);
  scaling_enum.define_value("LANCZOS", mapnik::SCALING_LANCZOS);
  scaling_enum.define_value("BLACKMAN", mapnik::SCALING_BLACKMAN);
  scaling_enum.define_value("BILINEAR8", mapnik::SCALING_BILINEAR8);
#endif

  /*  
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::raster_symbolizer > rb_craster_symbolizer = Rice::define_class_under< mapnik::raster_symbolizer >(rb_mapnik, "RasterSymbolizer");
  rb_craster_symbolizer.define_constructor(Rice::Constructor< mapnik::raster_symbolizer >());
  
  rb_craster_symbolizer.define_method("mode", &mapnik::raster_symbolizer::get_mode);
  rb_craster_symbolizer.define_method("mode=", &mapnik::raster_symbolizer::set_mode);

#if MAPNIK_VERSION >= 200100
  rb_craster_symbolizer.define_method("scaling", &mapnik::raster_symbolizer::get_scaling_method);
  rb_craster_symbolizer.define_method("scaling=", &mapnik::raster_symbolizer::set_scaling_method);
#else
  rb_craster_symbolizer.define_method("scaling", &mapnik::raster_symbolizer::get_scaling);
  rb_craster_symbolizer.define_method("scaling=", &mapnik::raster_symbolizer::set_scaling);
#endif

  rb_craster_symbolizer.define_method("opacity", &mapnik::raster_symbolizer::get_opacity);
  rb_craster_symbolizer.define_method("opacity=", &mapnik::raster_symbolizer::set_opacity);
  
  
  rb_craster_symbolizer.define_method("filter_factor", &mapnik::raster_symbolizer::get_filter_factor);
  rb_craster_symbolizer.define_method("filter_factor=", &mapnik::raster_symbolizer::set_filter_factor);
  
}
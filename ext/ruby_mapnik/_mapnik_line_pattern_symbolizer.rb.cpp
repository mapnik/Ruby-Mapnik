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
#include "_mapnik_line_pattern_symbolizer.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>

// Mapnik
#include <mapnik/line_pattern_symbolizer.hpp>

const std::string get_filename(mapnik::line_pattern_symbolizer const& t) { 
  return mapnik::path_processor_type::to_string(*t.get_filename()); 
}

void set_filename(mapnik::line_pattern_symbolizer & t, std::string const& file_expr) { 
  t.set_filename(mapnik::parse_path(file_expr)); 
}

void register_line_pattern_symbolizer(Rice::Module rb_mapnik){  
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::line_pattern_symbolizer > rb_cline_pattern_symbolizer = Rice::define_class_under< mapnik::line_pattern_symbolizer >(rb_mapnik, "LinePatternSymbolizer");
  
  /*
  * Document-method: new
  * call-seq:
  *   new(expression)
  * @param [Mapnik::Expression]
  * @return [Mapnik::LinePatternSymbolizer] a new line symbolzier object
  */
  rb_cline_pattern_symbolizer.define_constructor(Rice::Constructor< mapnik::line_pattern_symbolizer, mapnik::path_expression_ptr>());
  
  /*
  * Document-method: filename
  * @return [Mapnik::PathExpression]
  */
  rb_cline_pattern_symbolizer.define_method("filename", &get_filename);
  
  /*
  * Document-method: filename=
  * call-seq:
  *   filename=(new_filename)
  * @param [Mapnik::PathExpression]
  * @return [nil]
  */
  rb_cline_pattern_symbolizer.define_method("filename=", &set_filename);
  
}
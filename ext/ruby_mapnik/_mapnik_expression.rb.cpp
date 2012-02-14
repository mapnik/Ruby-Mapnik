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
#include "_mapnik_expression.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>

// Mapnik
#include <mapnik/feature.hpp>
#include <mapnik/expression.hpp>
#include <mapnik/expression_node.hpp>
#include <mapnik/expression_string.hpp>
#include <mapnik/expression_evaluator.hpp>
#include <mapnik/parse_path.hpp>

namespace {  
  boost::shared_ptr<mapnik::expr_node> parse_expression_(std::string const& wkt){
    return mapnik::parse_expression(wkt,"utf8");
  }

  std::string expr_node_to_string_(boost::shared_ptr<mapnik::expr_node> node_ptr){
    return mapnik::to_expression_string(*node_ptr);
  }

  // path expression
  mapnik::path_expression_ptr parse_path_(std::string const& path){
    return mapnik::parse_path(path);
  }
}

void register_expression(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< boost::shared_ptr<mapnik::expr_node> > rb_cexpression = Rice::define_class_under< boost::shared_ptr<mapnik::expr_node> >(rb_mapnik, "Expression");
  
  /*
  * Document-method: parse
  * call-seq:
  *  parse(expression_string)
  *
  * @param [String]
  *
  * @return [Mapnk::Expression] a new expression
  */
  rb_cexpression.define_singleton_method("parse", &parse_expression_);

  /*
  * Document-method: to_s
  * @return [String] a string representation of the expression 
  */
  rb_cexpression.define_method("to_s",&expr_node_to_string_);
  
  Rice::Data_Type< mapnik::path_expression_ptr > rb_cpath_expression = Rice::define_class_under< mapnik::path_expression_ptr >(rb_mapnik, "PathExpression");
  // rb_cpath_expression.define_singleton_method("evaluate", &path_evaluate_);
  // rb_cpath_expression.define_method("to_s",&path_to_string_);
  
    /*
  * Document-method: parse
  * call-seq:
  *  parse(path_expression_string)
  *
  * @param [String]
  *
  * @return [Mapnk::PathExpression] a new expression
  */
  rb_cpath_expression.define_singleton_method("parse", &parse_path_);
  
}
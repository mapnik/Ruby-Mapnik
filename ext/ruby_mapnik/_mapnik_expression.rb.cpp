#include "_mapnik_expression.rb.h"

// expression
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

void register_expression(Rice::Module rb_mapnik){
  Rice::Data_Type< boost::shared_ptr<mapnik::expr_node> > rb_cexpression = Rice::define_class_under< boost::shared_ptr<mapnik::expr_node> >(rb_mapnik, "Expression");
  rb_cexpression.define_singleton_method("parse", &parse_expression_);
  rb_cexpression.define_method("to_s",&expr_node_to_string_);
  
  Rice::Data_Type< mapnik::path_expression_ptr > rb_cpath_expression = Rice::define_class_under< mapnik::path_expression_ptr >(rb_mapnik, "PathExpression");
  // rb_cpath_expression.define_singleton_method("evaluate", &path_evaluate_);
  // rb_cpath_expression.define_method("to_s",&path_to_string_);
  rb_cpath_expression.define_singleton_method("parse", &parse_path_);
  
}
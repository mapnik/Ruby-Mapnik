#include "_mapnik_expression.rb.h"

void register_expression(Rice::Module rb_mapnik){
  Rice::Data_Type< mapnik::expression_ptr > rb_cstroke = Rice::define_class_under< mapnik::expression_ptr >(rb_mapnik, "Expression");
}
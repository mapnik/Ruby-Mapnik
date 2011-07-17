#include "_mapnik_style.rb.h"

template<>
Rice::Object to_ruby<std::vector<mapnik::rule> >(std::vector<mapnik::rule> const & x)
{
  return Rice::Array(x.begin(), x.end());
}

// TODO: Filter Mode!
void register_style(Rice::Module rb_mapnik){
  Rice::Data_Type< mapnik::feature_type_style > rb_cstyle = Rice::define_class_under< mapnik::feature_type_style >(rb_mapnik, "Style");
  rb_cstyle.define_constructor(Rice::Constructor< mapnik::feature_type_style >());
  rb_cstyle.define_method("__rules__", &mapnik::feature_type_style::get_rules);
  rb_cstyle.define_method("__add_rule__", &mapnik::feature_type_style::add_rule);
}
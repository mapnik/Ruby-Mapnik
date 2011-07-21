#include "_mapnik_rule.rb.h"

template<>
Rice::Object to_ruby<std::vector<mapnik::symbolizer> >(std::vector<mapnik::symbolizer> const & x)
{
  return Rice::Array(x.begin(), x.end());
}


void register_rule(Rice::Module rb_mapnik){
  Rice::Data_Type< mapnik::rule > rb_crule = Rice::define_class_under< mapnik::rule >(rb_mapnik, "Rule");
  rb_crule.define_constructor(Rice::Constructor< mapnik::rule >());
  
  rb_crule.define_method("name", &mapnik::rule::get_name);
  rb_crule.define_method("name=", &mapnik::rule::set_name, Rice::Arg("new_name"));
  
  rb_crule.define_method("title", &mapnik::rule::get_title);
  rb_crule.define_method("title=", &mapnik::rule::set_title, Rice::Arg("new_title"));
  
  rb_crule.define_method("abstract", &mapnik::rule::get_abstract);
  rb_crule.define_method("abstract=", &mapnik::rule::set_abstract, Rice::Arg("new_abstract"));
  
  rb_crule.define_method("filter", &mapnik::rule::get_filter);
  rb_crule.define_method("filter=", &mapnik::rule::set_filter, Rice::Arg("new_filter"));

  rb_crule.define_method("__symbols__", &mapnik::rule::get_symbolizers);
  rb_crule.define_method("__append_symbol__", &mapnik::rule::append, Rice::Arg("new_symbol"));
  rb_crule.define_method("__remove_symbol__", &mapnik::rule::remove_at, Rice::Arg("index"));
  
}
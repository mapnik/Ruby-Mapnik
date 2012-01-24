#include "_mapnik_rule.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Array.hpp>

// Mapnik
#include <mapnik/rule.hpp>

template<>
Rice::Object to_ruby<std::vector<mapnik::symbolizer> >(std::vector<mapnik::symbolizer> const & x)
{
  return Rice::Array(x.begin(), x.end());
}

void register_rule(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::rule > rb_crule = Rice::define_class_under< mapnik::rule >(rb_mapnik, "Rule");
  
  /*
  * Document-method: new
  * @return [Mapnik::Rule]
  */
  rb_crule.define_constructor(Rice::Constructor< mapnik::rule >());
  
  /*
  * Document-method: name
  * @return [String]
  */
  rb_crule.define_method("name", &mapnik::rule::get_name);
  
  /*
  * Document-method: name=
  * call-seq:
  *   name=(new_name)
  * @param [String]
  * @return [nil]
  */
  rb_crule.define_method("name=", &mapnik::rule::set_name, Rice::Arg("new_name"));
    
  /*
  * Document-method: filter
  * @return [Mapnik::Expression]
  */
  rb_crule.define_method("filter", &mapnik::rule::get_filter);
  
  /*
  * Document-method: filter=
  * call-seq:
  *   filter=(new_filter)
  * @param [Mapnik::Expression]
  * @return [nil]
  */
  rb_crule.define_method("filter=", &mapnik::rule::set_filter, Rice::Arg("new_filter"));

  // Dont-Document-method: __symbols__
  rb_crule.define_method("__symbols__", &mapnik::rule::get_symbolizers);
  
  // Dont-Document-method: __append_symbol__
  rb_crule.define_method("__append_symbol__", &mapnik::rule::append, Rice::Arg("new_symbol"));
  
  // Dont-Document-method: __remove_symbol__
  rb_crule.define_method("__remove_symbol__", &mapnik::rule::remove_at, Rice::Arg("index"));
  
}
#include "_mapnik_shield_symbolizer.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>

// Mapnik
#include <mapnik/text_symbolizer.hpp>  
#include <mapnik/shield_symbolizer.hpp>

Rice::Object get_shield_displacement(const mapnik::shield_symbolizer& t){
  mapnik::position pos = t.get_shield_displacement();
  Rice::Array out;
  out.push(boost::get<0>(pos));
  out.push(boost::get<1>(pos));
  return out;
}

void set_shield_displacement(mapnik::shield_symbolizer & t, Rice::Array ary){
  double x = from_ruby<double>(ary[0]);
  double y = from_ruby<double>(ary[1]);
  
  t.set_shield_displacement(x,y);
}

void register_shield_symbolizer(Rice::Module rb_mapnik){  
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::shield_symbolizer > rb_cshield_symbolizer = Rice::define_class_under< mapnik::shield_symbolizer, mapnik::text_symbolizer >(rb_mapnik, "ShieldSymbolizer");
  rb_cshield_symbolizer.define_constructor(Rice::Constructor< mapnik::shield_symbolizer, mapnik::expression_ptr, std::string, unsigned, mapnik::color, mapnik::path_expression_ptr >());  
  
  rb_cshield_symbolizer.define_method("shield_displacement", &get_shield_displacement);
  rb_cshield_symbolizer.define_method("shield_displacement=", &set_shield_displacement);
  
}
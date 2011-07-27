#include "_mapnik_font_engine.rb.h"

Rice::Object get_font_face_names(){
  Rice::Array out;
  std::vector<std::string> const& names = mapnik::freetype_engine::face_names();
  std::vector<std::string>::const_iterator end = names.end();
  for (std::vector<std::string>::const_iterator it = names.begin(); it != end; ++it){
    out.push(to_ruby<std::string>(*it));
  }
  return out;
}

void register_font_name(std::string font_name){
  mapnik::freetype_engine::register_font(font_name);
}

void register_font_engine(Rice::Module rb_mapnik){
  Rice::Data_Type< mapnik::freetype_engine > rb_cfont_engine = Rice::define_class_under< mapnik::freetype_engine >(rb_mapnik, "FontEngine");
  rb_cfont_engine.define_singleton_method("register_font", &register_font_name);
  rb_cfont_engine.define_singleton_method("face_names", &get_font_face_names);
}
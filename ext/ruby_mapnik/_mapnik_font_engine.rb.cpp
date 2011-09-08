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
#include "_mapnik_font_engine.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>

// Mapnik
#include <mapnik/font_engine_freetype.hpp>

namespace {
  
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

}

void register_font_engine(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::freetype_engine > rb_cfont_engine = Rice::define_class_under< mapnik::freetype_engine >(rb_mapnik, "FontEngine");
  
  /*
  * Document-method: register_font
  * call-seq:
  *   register_font(font_name)
  * Registers a font with the FontEngine
  * @return [nil]
  */
  rb_cfont_engine.define_singleton_method("register_font", &register_font_name);

  /*
  * Document-method: face_names
  * @return [Array] Names of the fonts that have been registered
  */
  rb_cfont_engine.define_singleton_method("face_names", &get_font_face_names);
}
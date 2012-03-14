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
#include "_mapnik_layer.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>

// Mapnik
#include <mapnik/layer.hpp>

template<>
Rice::Object to_ruby<std::vector<std::string> >(std::vector<std::string> const & x)
{
  return Rice::Array(x.begin(), x.end());
}

std::vector<std::string> & (mapnik::layer::*_styles_)() = &mapnik::layer::styles;

void register_layer(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::layer > rb_clayer = Rice::define_class_under< mapnik::layer >(rb_mapnik, "Layer");
  
  /*
  * Document-method: new
  * call-seq:
  *   new(name, srs)
  * @param [String] name
  * @param [String] srs
  * @return [Mapnik::Layer] a new layer object
  */
  rb_clayer.define_constructor(Rice::Constructor< mapnik::layer, std::string, std::string >(), (Rice::Arg("name"), Rice::Arg("srs") = (std::string)"+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs"));
 
  /*
  * Document-method: datasource
  * @return [Mapnik::Datasource] the layer's datasource
  */
  rb_clayer.define_method("datasource", &mapnik::layer::datasource);

  /*
  * Document-method: datasource=
  * call-seq:
  *   datasource=(new_datasource)
  * @param [Mapnik::Datasource]
  * @return [nil]
  */
  rb_clayer.define_method("datasource=", &mapnik::layer::set_datasource, Rice::Arg("new_datasource"));

  /*
  * Document-method: envelope
  * @return [Mapnik::Envelope] The layer's envelope
  * Should correspond to the layer's datasource envelope.
  */
  rb_clayer.define_method("envelope", &mapnik::layer::envelope);
  
  /*
  * Document-method: name
  * @return [String] The layer's name
  */
  rb_clayer.define_method("name", &mapnik::layer::name);

  /*
  * Document-method: name=
  * call-seq:
  *   name=(new_name)
  * @param [String]
  * @return [nil]
  */
  rb_clayer.define_method("name=", &mapnik::layer::set_name, Rice::Arg("new_name"));
    
  /*
  * Document-method: srs
  * @return [String] the layer's srs
  */
  rb_clayer.define_method("srs", &mapnik::layer::srs);
  
  /*
  * Document-method: srs=
  * call-seq:
  *   srs=(new_srs)
  * @param [String]
  */
  rb_clayer.define_method("srs=", &mapnik::layer::set_srs, Rice::Arg("new_srs"));
  
  /*
  * Document-method: min_zoom
  * @return [Integer] the layer's minimum zoom factor
  */
  rb_clayer.define_method("min_zoom", &mapnik::layer::min_zoom);
  
  /*
  * Document-method: min_zoom=
  * call-seq:
  *   min_zoom=(min_zoom)
  * @return [nil]
  */
  rb_clayer.define_method("min_zoom=", &mapnik::layer::set_min_zoom, Rice::Arg("new_min_zoom"));
  
  /*
  * Document-method: max_zoom
  * @return [Integer] the layer's maximum zoom factor
  */
  rb_clayer.define_method("max_zoom", &mapnik::layer::max_zoom);
  
 
  /*
  * Document-method: max_zoom=
  * call-seq:
  *   min_zoom=(min_zoom)
  * @return [nil]
  */
  rb_clayer.define_method("max_zoom=", &mapnik::layer::set_max_zoom, Rice::Arg("new_max_zoom"));

  /*
  * Document-method: visible_at_scale?
  * @return [Boolean]
  */
  rb_clayer.define_method("visible_at_scale?", &mapnik::layer::visible, Rice::Arg("scale"));
  
  /*
  * Document-method: active?
  * @return [Boolean]
  */
  rb_clayer.define_method("active?", &mapnik::layer::active);
  
  /*
  * Document-method: active=
  * call-seq:
  *   active=(new_active_value)
  * @return [nil]
  */
  rb_clayer.define_method("active=", &mapnik::layer::set_active, Rice::Arg("new_active_value"));
  
  /*
  * Document-method: queryable?
  * @return [Boolean]
  */
  rb_clayer.define_method("queryable?", &mapnik::layer::queryable);
  
  /*
  * Document-method: queryable=
  * call-seq:
  *   queryable=(new_queryable_value)
  * @return [nil]
  */
  rb_clayer.define_method("queryable=", &mapnik::layer::set_queryable, Rice::Arg("new_queryable_value"));
  
  /*
  * Document-method: cache_features?
  * @return [Boolean]
  */
  rb_clayer.define_method("cache_features?", &mapnik::layer::cache_features);
  
  /*
  * Document-method: cache_features=
  * call-seq:
  *   cache_features=(new_cache_features_value)
  * @return [nil]
  */
  rb_clayer.define_method("cache_features=", &mapnik::layer::set_cache_features, Rice::Arg("new_cache_features_value"));
  
  /*
  * Document-method: clear_label_cache?
  * @return [Boolean]
  */
  rb_clayer.define_method("clear_label_cache?", &mapnik::layer::clear_label_cache);
  
  /*
  * Document-method: clear_label_cache=
  * call-seq:
  *   clear_label_cache=(new_clear_label_cache_value)
  * @return [nil]
  */
  rb_clayer.define_method("clear_label_cache=", &mapnik::layer::set_clear_label_cache, Rice::Arg("new_clear_label_cache_value"));
  
  /*
  * Dont-Document-method: __style_list__
  */
  rb_clayer.define_method("__style_list__", _styles_);
  
  /*
  * Dont-Document-method: __append_style__
  */
  rb_clayer.define_method("__append_style__", &mapnik::layer::add_style, Rice::Arg("new_style"));
}
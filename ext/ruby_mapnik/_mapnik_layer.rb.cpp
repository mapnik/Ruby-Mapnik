#include "_mapnik_layer.rb.h"

template<>
Rice::Object to_ruby<std::vector<std::string> >(std::vector<std::string> const & x)
{
  return Rice::Array(x.begin(), x.end());
}

std::vector<std::string> & (mapnik::layer::*_styles_)() = &mapnik::layer::styles;

void register_layer(Rice::Module rb_mapnik){
  Rice::Data_Type< mapnik::layer > rb_clayer = Rice::define_class_under< mapnik::layer >(rb_mapnik, "Layer");
  rb_clayer.define_constructor(Rice::Constructor< mapnik::layer, std::string, std::string >(), (Rice::Arg("name"), Rice::Arg("srs") = (std::string)"+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs"));
 
  rb_clayer.define_method("datasource", &mapnik::layer::datasource);
  rb_clayer.define_method("datasource=", &mapnik::layer::set_datasource, Rice::Arg("new_datasource"));

  rb_clayer.define_method("envelope", &mapnik::layer::envelope);
  
  rb_clayer.define_method("name", &mapnik::layer::name);
  rb_clayer.define_method("name=", &mapnik::layer::set_name, Rice::Arg("new_name"));
  
  rb_clayer.define_method("title", &mapnik::layer::title);
  rb_clayer.define_method("title=", &mapnik::layer::set_title, Rice::Arg("new_title"));
  
  rb_clayer.define_method("abstract", &mapnik::layer::abstract);
  rb_clayer.define_method("abstract=", &mapnik::layer::set_abstract, Rice::Arg("new_abstract"));
  
  rb_clayer.define_method("srs", &mapnik::layer::srs);
  rb_clayer.define_method("srs=", &mapnik::layer::set_srs, Rice::Arg("new_srs"));
  
  rb_clayer.define_method("min_zoom", &mapnik::layer::getMinZoom);
  rb_clayer.define_method("min_zoom=", &mapnik::layer::setMinZoom, Rice::Arg("new_min_zoom"));
  
  rb_clayer.define_method("max_zoom", &mapnik::layer::getMaxZoom);
  rb_clayer.define_method("max_zoom=", &mapnik::layer::setMaxZoom, Rice::Arg("new_max_zoom"));

  rb_clayer.define_method("visible_at_scale?", &mapnik::layer::isVisible, Rice::Arg("scale"));
  
  rb_clayer.define_method("active?", &mapnik::layer::isActive);
  rb_clayer.define_method("active=", &mapnik::layer::setActive, Rice::Arg("new_active_value"));
  
  rb_clayer.define_method("queryable?", &mapnik::layer::isQueryable);
  rb_clayer.define_method("queryable=", &mapnik::layer::setQueryable, Rice::Arg("new_queryable_value"));
  
  rb_clayer.define_method("cache_features?", &mapnik::layer::cache_features);
  rb_clayer.define_method("cache_features=", &mapnik::layer::set_cache_features, Rice::Arg("new_cache_features_value"));
  
  rb_clayer.define_method("clear_label_cache?", &mapnik::layer::clear_label_cache);
  rb_clayer.define_method("clear_label_cache=", &mapnik::layer::set_clear_label_cache, Rice::Arg("new_clear_label_cache_value"));
  
  rb_clayer.define_method("__style_list__", _styles_);
  rb_clayer.define_method("__append_style__", &mapnik::layer::add_style, Rice::Arg("new_style"));
}
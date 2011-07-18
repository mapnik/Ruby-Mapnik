#include "_mapnik_map.rb.h"
#include <mapnik2/agg_renderer.hpp>
#include <mapnik2/graphics.hpp>
#include <mapnik2/image_util.hpp>
#include <mapnik2/load_map.hpp>
#include <mapnik2/save_map.hpp>

// Seems like we could metaprogram these two away...
template<>
Rice::Object to_ruby<boost::optional<mapnik::color> >(boost::optional<mapnik::color> const & x){
  if(x)
  {
    return to_ruby<mapnik::color>(x.get());
  } else{
    return Rice::Object();
  }
}

template<>
Rice::Object to_ruby<boost::optional<mapnik::box2d<double> > >(boost::optional<mapnik::box2d<double> > const & x){
  if(x)
  {
    return to_ruby<mapnik::box2d<double> >(x.get());
  } else{
    return Rice::Object();
  }
}

template<>
Rice::Object to_ruby<std::map<std::string,mapnik::feature_type_style> >(std::map<std::string,mapnik::feature_type_style> const & x){
  Rice::Hash h;
  std::map<std::string,mapnik::feature_type_style>::const_iterator end = x.end();
  for (std::map<std::string,mapnik::feature_type_style>::const_iterator it = x.begin(); it != end; ++it){
    h[to_ruby<std::string>(it->first)] = to_ruby<mapnik::feature_type_style>(it->second);
  }
  return h;
}

template<>
Rice::Object to_ruby<std::vector<mapnik::layer> >(std::vector<mapnik::layer> const & x)
{
  return Rice::Array(x.begin(), x.end());
}

std::map<std::string,mapnik::feature_type_style> & (mapnik::Map::*_map_styles_)() = &mapnik::Map::styles;
std::vector<mapnik::layer> & (mapnik::Map::*_map_layers_)() = &mapnik::Map::layers;

void render_map_to_file(const mapnik::Map& map, const std::string& filename, const std::string& format){
  mapnik::image_32 image(map.width(),map.height());
  mapnik::agg_renderer<mapnik::image_32> ren(map,image,1.0,0,0);
  ren.apply();
  mapnik::save_to_file(image,filename,format);
}

std::string map_to_string(const mapnik::Map& map){
  return mapnik::save_map_to_string(map);
}

void register_map(Rice::Module rb_mapnik){
  Rice::Data_Type< mapnik::Map > rb_cmap = Rice::define_class_under< mapnik::Map >(rb_mapnik, "Map");
  rb_cmap.define_constructor(Rice::Constructor< mapnik::Map, int, int, std::string >(), (Rice::Arg("width"), Rice::Arg("height"), Rice::Arg("srs")));
  
  rb_cmap.define_singleton_method("__load_map_string__", &mapnik::load_map_string);
  rb_cmap.define_singleton_method("__load_map__", &mapnik::load_map);
  
  rb_cmap.define_method("background", &mapnik::Map::background);
  rb_cmap.define_method("background=", &mapnik::Map::set_background);
  
  rb_cmap.define_method("base_path", &mapnik::Map::base_path);
  rb_cmap.define_method("base_path=", &mapnik::Map::set_base_path);
  
  rb_cmap.define_method("buffer_size", &mapnik::Map::buffer_size);
  rb_cmap.define_method("buffer_size=", &mapnik::Map::set_buffer_size);
  
  rb_cmap.define_method("height", &mapnik::Map::height);
  rb_cmap.define_method("height=", &mapnik::Map::set_height);
  
  rb_cmap.define_method("maximum_extent", &mapnik::Map::maximum_extent);
  rb_cmap.define_method("maximum_extent=", &mapnik::Map::set_maximum_extent, Rice::Arg("new_extent"));
  
  rb_cmap.define_method("srs", &mapnik::Map::srs);
  rb_cmap.define_method("srs=", &mapnik::Map::set_srs);
  
  rb_cmap.define_method("width", &mapnik::Map::width);
  rb_cmap.define_method("width=", &mapnik::Map::set_width);
  
  rb_cmap.define_method("envelope", &mapnik::Map::get_current_extent);
  rb_cmap.define_method("buffered_envelope", &mapnik::Map::get_buffered_extent);
  
  rb_cmap.define_method("pan", &mapnik::Map::pan);
  rb_cmap.define_method("zoom", &mapnik::Map::zoom);
  rb_cmap.define_method("zoom_all", &mapnik::Map::zoom_all);
  rb_cmap.define_method("zoom_to_box", &mapnik::Map::zoom_to_box, Rice::Arg("envelope"));
  
  rb_cmap.define_method("resize", &mapnik::Map::resize);
  rb_cmap.define_method("scale", &mapnik::Map::scale);
  
  rb_cmap.define_method("__styles__", _map_styles_);
  rb_cmap.define_method("__insert_style__", &mapnik::Map::insert_style);
  rb_cmap.define_method("__remove_style__", &mapnik::Map::remove_style);
  
  rb_cmap.define_method("__layers__", _map_layers_);
  rb_cmap.define_method("__add_layer__", &mapnik::Map::addLayer);
  rb_cmap.define_method("__remove_layer__", &mapnik::Map::removeLayer);
  
  rb_cmap.define_method("__render_to_file__", &render_map_to_file);
  rb_cmap.define_method("to_xml", &map_to_string);
  
}
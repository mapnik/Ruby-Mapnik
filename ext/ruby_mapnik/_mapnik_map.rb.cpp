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
#include "_mapnik_map.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Hash.hpp>
#include <rice/Array.hpp>

// Mapnik
#include <mapnik/map.hpp>
#include <mapnik/version.hpp>
#include <mapnik/feature_type_style.hpp>
#include <mapnik/agg_renderer.hpp>
#include <mapnik/graphics.hpp>
#ifdef HAVE_CAIRO
#if MAPNIK_VERSION >= 200200
  #include <mapnik/cairo_context.hpp>
#endif
  #include <mapnik/cairo_renderer.hpp>
#endif
#include <mapnik/image_util.hpp>
#include <mapnik/load_map.hpp>
#include <mapnik/save_map.hpp>

#include <boost/optional.hpp>

// Seems like one could metaprogram these two away...
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
boost::optional<mapnik::box2d<double> > const& (mapnik::Map::*maximum_extent_const)() const =  &mapnik::Map::maximum_extent;

namespace {

  void render_map_to_file_with_format(const mapnik::Map& map, const std::string& filename, const std::string& format){
    if (format == "pdf" || format == "svg" || format =="ps") {
  #if defined(HAVE_CAIRO)
    mapnik::save_to_cairo_file(map,filename,format);
  #else
    throw mapnik::ImageWriterException("Cairo backend not available, cannot write to format: " + format);
  #endif
    } else {
        mapnik::image_32 image(map.width(),map.height());
        mapnik::agg_renderer<mapnik::image_32> ren(map,image,1.0,0,0);
        ren.apply();
        mapnik::save_to_file(image,filename, format);
    }
  }

  void render_map_to_file(const mapnik::Map& map, const std::string& filename){
    render_map_to_file_with_format(map, filename, mapnik::guess_type(filename));
  }

  std::string render_map_to_string(const mapnik::Map& map, std::string const& format){
    mapnik::image_32 image(map.width(),map.height());
    mapnik::agg_renderer<mapnik::image_32> ren(map,image,1.0,0,0);
    ren.apply();
    return mapnik::save_to_string(image,format);
  }

  std::string map_to_string(const mapnik::Map& map){
    return mapnik::save_map_to_string(map);
  }

  #if defined(HAVE_CAIRO)

  // TODO: These are temporarily boosted from the ruby cairo gem...
  cairo_surface_t * rb_cairo_surface_from_ruby_object (VALUE obj) {
    cairo_surface_t *surface;
    // if (!rb_cairo__is_kind_of (obj, rb_cCairo_Surface))
    //   {
    //     rb_raise (rb_eTypeError, "not a cairo surface");
    //   }
    Data_Get_Struct (obj, cairo_surface_t, surface);
    // if (!surface)
    //   rb_cairo_check_status (CAIRO_STATUS_NULL_POINTER);
    return surface;
  }

  cairo_t * rb_cairo_context_from_ruby_object (VALUE obj) {
    cairo_t *context;
    // if (!rb_cairo__is_kind_of (obj, rb_cCairo_Surface))
    //   {
    //     rb_raise (rb_eTypeError, "not a cairo surface");
    //   }
    Data_Get_Struct (obj, cairo_t, context);
    // if (!surface)
    //   rb_cairo_check_status (CAIRO_STATUS_NULL_POINTER);
    return context;
  }

  void render_to_cairo_surface(mapnik::Map const & map, Rice::Object rb_surface, unsigned offset_x = 0, unsigned offset_y = 0){
    using namespace mapnik;
    cairo_surface_t * surface = rb_cairo_surface_from_ruby_object(rb_surface);
#if MAPNIK_VERSION >= 200200
    mapnik::cairo_surface_ptr surface_ref(cairo_surface_reference(surface), mapnik::cairo_surface_closer());
    double scale_factor = 1.0;
    mapnik::cairo_renderer<mapnik::cairo_surface_ptr> ren(map, surface_ref, scale_factor, offset_x, offset_y);
#else
    Cairo::RefPtr<Cairo::Surface> s(new Cairo::Surface(surface));
    mapnik::cairo_renderer<Cairo::Surface> ren(map,s,offset_x, offset_y);
#endif
    ren.apply();
  }

  void render_to_cairo_context(mapnik::Map const & map, Rice::Object rb_context, unsigned offset_x = 0, unsigned offset_y = 0){
    cairo_t * context = rb_cairo_context_from_ruby_object(rb_context);
#if MAPNIK_VERSION >= 200200
    mapnik::cairo_ptr context_ref(context, mapnik::cairo_closer());
    double scale_factor = 1.0;
    mapnik::cairo_renderer<mapnik::cairo_ptr> ren(map, context_ref, scale_factor, offset_x, offset_y);
#else
    Cairo::RefPtr<Cairo::Context> c(new Cairo::Context(context));
    mapnik::cairo_renderer<Cairo::Context> ren(map, c, offset_x, offset_y);
    ren.apply();
#endif
  }
  #endif

  void initialize_map(Rice::Object self){
    DATA_PTR(self.value()) = new mapnik::Map();
    if(rb_block_given_p()) {
      rb_yield(self);
    }
  }

}

void register_map(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
    Document-class: Mapnik::Map
    
    Maps are exactly what they sound like: the reason you are using mapnik. Maps
    have layers, which wrap a datasource, and styles, which contain instructions
    on how to render those layers. 

    Maps can be rendered to basic image formats (jpg, png), as well as to cairo
    surfaces and contexts, if mapnik has been compiled with cairo support, and if 
    the rcairo gem is installed. 
  
  */
  Rice::Data_Type< mapnik::Map > rb_cmap = Rice::define_class_under< mapnik::Map >(rb_mapnik, "Map");
  
  /* 
  * Document-method: new
  * Instantiates a new map object. The map is yielded if a block is given.
  * @return [Mapnik::Map] a new map object
  * @yield [map] the new map object

  */
  rb_cmap.define_constructor(Rice::Constructor< mapnik::Map >());
  
  /*
  * Dont-Document-method: __load_map_string__
  */
  rb_cmap.define_singleton_method("__load_map_string__", &mapnik::load_map_string);
  
  /*
  * Dont-Document-method: __load_map__
  */
  rb_cmap.define_singleton_method("__load_map__", &mapnik::load_map);
  
  /*
  * Dont-document-method: initialize
  */
  rb_cmap.define_method("initialize", &initialize_map);

  /*
  * Document-method: background
  * @return [Mapnik::Color]
  */
  rb_cmap.define_method("background", &mapnik::Map::background);
  
  /*
  * Document-method: background=
  * call-seq:
  *   background=(color)
  * @param [Mapnik::Color]
  * @return [nil]
  */
  rb_cmap.define_method("background=", &mapnik::Map::set_background);
  
  /*
  * Document-method: base_path
  * @return [String] The path all relative paths will be resolved with
  */
  rb_cmap.define_method("base_path", &mapnik::Map::base_path);
  
  /*
  * Document-method: base_path=
  * call-seq:
  *   base_path=(path)
  * @param [String]
  * @return [nil]
  */
  rb_cmap.define_method("base_path=", &mapnik::Map::set_base_path);
  
  /*
  * Document-method: buffer_size
  * @return [Integer]
  */  
  rb_cmap.define_method("buffer_size", &mapnik::Map::buffer_size);
  
  /*
  * Document-method: buffer_size=
  * call-seq:
  *   buffer_size=(size)
  * @param [Integer]
  * @return [nil]
  */  
  rb_cmap.define_method("buffer_size=", &mapnik::Map::set_buffer_size);
  
  /*
  * Document-method: height
  * The height of the rendered image in pixels.
  * @return [Integer]
  */
  rb_cmap.define_method("height", &mapnik::Map::height);
  
  /*
  * Document-method: height=
  * call-seq:
  *   height=(height_in_pixels) 
  * Sets the height of the rendered image.
  * @param [Integer] height_in_pixels
  * @return [nil]
  */
  rb_cmap.define_method("height=", &mapnik::Map::set_height);
  
  /*
  * Document-method: maximum_extent
  * @return [Mapnik::Envelope]
  */
  rb_cmap.define_method("maximum_extent", maximum_extent_const);

  /*
  * Document-method: maximum_extent=
  * call-seq:
  *  maximum_extent=(new_extent)
  * @param [Mapnik::Envelope] new_extent
  * @return [nil]
  */
  rb_cmap.define_method("maximum_extent=", &mapnik::Map::set_maximum_extent, Rice::Arg("new_extent"));
  
  /*
  * Document-method: srs
  * The spatial reference system string for the map. It does not need to match 
  * the srs of any of the layers.
  * @return [String]
  */
  rb_cmap.define_method("srs", &mapnik::Map::srs);
  
  /*
  * Document-method: srs=
  * call-seq:
  *   srs=(new_srs)
  * Sets the spatial reference system that will be used to render the map. All
  * layers will have thier data reprojected to this srs behind the scenes. 
  *
  * @param [String]
  * @return [nil]
  */
  rb_cmap.define_method("srs=", &mapnik::Map::set_srs);
  
  /*
  * Document-method: width
  * The width of the image in pixels.
  * @return [Integer]
  */
  rb_cmap.define_method("width", &mapnik::Map::width);
  
  /*
  * Document-method: width=
  * call-seq:
  *  width=(new_width)
  * Sets the width of the image.
  * @param [Integer] new_width in pixels
  * @return [nil]
  */
  rb_cmap.define_method("width=", &mapnik::Map::set_width);
  
  /*
  * Document-method: envelope
  * @return [Mapnik::Envelope]
  */
  rb_cmap.define_method("envelope", &mapnik::Map::get_current_extent);
  
  /*
  * Document-method: buffered_envelope
  * @return [Mapnik::Envelope]
  * The envelope plus any buffer set in buffer_size
  */
  rb_cmap.define_method("buffered_envelope", &mapnik::Map::get_buffered_extent);
  
  /*
  * Document-method: pan
  * call-seq:
  *   pan(x, y)
  * @param [Integer] x
  * @param [Integer] y
  * @return [nil]
  */
  rb_cmap.define_method("pan", &mapnik::Map::pan);
  
  /*
  * Document-method: zoom
  * call-seq:
  *   zoom(zoom_factor)
  * @param [Integer] zoom_factor
  * @return [nil]
  */
  rb_cmap.define_method("zoom", &mapnik::Map::zoom);
  
  /*
  * Document-method: zoom_all
  * Zooms the map so that all of the envelopes of the layers are visible.
  * @return [nil]
  */
  rb_cmap.define_method("zoom_all", &mapnik::Map::zoom_all);
  
  /*
  * Document-method: zoom_to_box
  * call-seq:
  *   zoom_to_box(envelope)
  * Zooms the map such that the envelope provided is all that will be rendered.
  * The height and width of the map will stay the same, but the content will be 
  * zoomed.
  * @param [Mapnik::Envelope] envelope
  * @return [nil]
  */
  rb_cmap.define_method("zoom_to_box", &mapnik::Map::zoom_to_box, Rice::Arg("envelope"));
  
  /* 
  * Document-method: resize
  * call-seq:
  *   resize(new_width, new_height)
  * Resizes the height and width of the map in one step.
  * @param [Integer] new_width in pixels
  * @param [Integer] new_height in pixels
  * @return [nil]
  */
  rb_cmap.define_method("resize", &mapnik::Map::resize);

  /*
  * Document-method: scale
  * @return [Float]
  */
  rb_cmap.define_method("scale", &mapnik::Map::scale);
  
  /*
  * Dont-Document-method: __styles__
  */
  rb_cmap.define_method("__styles__", _map_styles_);
  
  /*
  * Dont-Document-method: __insert_style__
  */
  rb_cmap.define_method("__insert_style__", &mapnik::Map::insert_style);
  
  /*
  * Dont-Document-method: __remove_style__
  */
  rb_cmap.define_method("__remove_style__", &mapnik::Map::remove_style);
  
  /*
  * Dont-Document-method: __layers__
  */
  rb_cmap.define_method("__layers__", _map_layers_);
  
  /*
  * Dont-Document-method: __add_layer__
  */
  rb_cmap.define_method("__add_layer__", &mapnik::Map::addLayer);
  
  /*
  * Dont-Document-method: __remove_layer__
  */
  rb_cmap.define_method("__remove_layer__", &mapnik::Map::removeLayer);
  
  /*
  * Dont-Document-method: __render_to_file__
  */
  rb_cmap.define_method("__render_to_file__", &render_map_to_file);

  /*
  * Dont-Document-method: __render_to_file_with_format__
  */
  rb_cmap.define_method("__render_to_file_with_format__", &render_map_to_file_with_format);

  /*
  * Document-method: to_xml
  * @return [String] 
  * An XML representation of the map that can be loaded via the from_xml method, or by other mapnik implementations
  */
  rb_cmap.define_method("to_xml", &map_to_string);

  /*
  * Document-method: render_to_string
  * call-seq:
  *   render_to_string(file_format)
  * @param [String] file_format One of 'png', 'jpg' or 'tiff'
  * @return [String] A string of the data for the image
  */
  rb_cmap.define_method("render_to_string", &render_map_to_string);

#if defined(HAVE_CAIRO)  
  
  /* 
  * Document-method: render_to_cairo_surface
  * call-seq:
  *   render_to_cairo_surface(cairo_surface)
  * @param [Cairo::Surface]
  * @return [nil]
  * Only available if Ruby-Mapnik was compiled with Cairo support and the 
  * Ruby Cairo gem is available
  */
  rb_cmap.define_method("render_to_cairo_surface", &render_to_cairo_surface);
    
  /* 
  * Document-method: render_to_cairo_context
  * call-seq:
  *   render_to_cairo_context(cairo_context)
  * @param [Cairo::Context]
  * @return [nil]
  * Only available if Ruby-Mapnik was compiled with Cairo support and the 
  * Ruby Cairo gem is available
  */
  rb_cmap.define_method("render_to_cairo_context", &render_to_cairo_context);
#endif  
  
}
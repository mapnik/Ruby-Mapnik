#include "_mapnik_point_symbolizer.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>

// Mapnik
#include <mapnik/point_symbolizer.hpp>

namespace {

  const std::string get_filename(mapnik::point_symbolizer const& t) { 
      return mapnik::path_processor_type::to_string(*t.get_filename()); 
  }

  void set_filename(mapnik::point_symbolizer & t, std::string const& file_expr) { 
      t.set_filename(mapnik::parse_path(file_expr)); 
  }

  const double get_point_opacity(mapnik::point_symbolizer const& t){
    return t.get_opacity();
  }

  void set_point_opacity(mapnik::point_symbolizer & t, double value){
    t.set_opacity(value);
  }

  mapnik::point_placement_enum get_placement(mapnik::point_symbolizer const& t){
    return t.get_point_placement();
  }

  void set_placement(mapnik::point_symbolizer & t, mapnik::point_placement_enum value){
    t.set_point_placement(value);
  }

  std::string get_point_transform_string(mapnik::point_symbolizer const& t){
    return t.get_transform_string();
  }

}

void register_point_symbolizer(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Enum<mapnik::point_placement_enum> placement_enum = Rice::define_enum<mapnik::point_placement_enum>("PointPlacement", rb_mapnik);
  
  placement_enum.define_value("CENTROID",mapnik::CENTROID_POINT_PLACEMENT);
  placement_enum.define_value("INTERIOR",mapnik::INTERIOR_POINT_PLACEMENT);
  
  Rice::Data_Type< mapnik::point_symbolizer > rb_cpoint_symbolizer = Rice::define_class_under< mapnik::point_symbolizer >(rb_mapnik, "PointSymbolizer");
  
  /*
  * Document-method: new
  * @return [Mapnik::PointSymbolizer]
  */
  rb_cpoint_symbolizer.define_constructor(Rice::Constructor< mapnik::point_symbolizer >());
  
  /*
  * Document-method: filename
  * @return [String]
  */
  rb_cpoint_symbolizer.define_method("filename", &get_filename);
  
  /* Document-method: filename=
  * call-seq:
  *   filename=(new_filename)
  * @param [String] filename
  * @return [nil]
  */
  rb_cpoint_symbolizer.define_method("filename=", &set_filename);
  
  /*
  * Document-method: allow_overlap?
  * @return [Boolean]
  */
  rb_cpoint_symbolizer.define_method("allows_overlap?", &mapnik::point_symbolizer::get_allow_overlap);
  
  /*
  * Document-method: allow_overlap=
  * call-seq:
  *   allow_overlap=(new_value)
  * @param [Boolean] new_value
  * @return [nil]
  */
  rb_cpoint_symbolizer.define_method("allows_overlap=", &mapnik::point_symbolizer::set_allow_overlap);
  
  /*
  * Document-method: opacity
  * @return [Float]
  */
  rb_cpoint_symbolizer.define_method("opacity", &get_point_opacity);
  
  /*
  * Document-method: opacity=
  * call-seq:
  *   opacity=(new_value)
  * @param [Float]
  * @return [nil]
  */
  rb_cpoint_symbolizer.define_method("opacity=", &set_point_opacity);
  
  /*
  * Document-method: ignores_placement?
  * @return [Boolean]
  */
  rb_cpoint_symbolizer.define_method("ignores_placement?", &mapnik::point_symbolizer::get_ignore_placement);
  
  /*
  * Document-method: ignores_placement=
  * call-seq:
  *   ignores_placement=(new_value)
  * @param [Boolean] new_value
  */
  rb_cpoint_symbolizer.define_method("ignores_placement=", &mapnik::point_symbolizer::set_ignore_placement);
  
  rb_cpoint_symbolizer.define_method("placement", &get_placement);
  rb_cpoint_symbolizer.define_method("placement=", &set_placement);

  // TODO:
  // rb_cpoint_symbolizer.define_method("transform", &get_point_transform_string);
  // // rb_cpoint_symbolizer.define_method("transform=", &set_point_transform_string);
  
}
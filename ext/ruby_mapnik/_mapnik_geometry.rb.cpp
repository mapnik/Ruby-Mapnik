#include <_mapnik_geometry.rb.h>

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>

// Mapnik
#include <mapnik/geometry.hpp>
#include <mapnik/wkt/wkt_factory.hpp>

namespace{
  // Borrowed from the python bindings...
  mapnik::geometry_type * make_from_wkt(std::string const& wkt) {
    std::pair<bool,mapnik::geometry_type*> result = mapnik::from_wkt(wkt);
    if (result.first){
      return result.second;
    }
    throw std::runtime_error("Failed to parse WKT");
  }

}

Rice::Enum<mapnik::eGeomType> geometry_enum;

template<>
mapnik::eGeomType from_ruby<mapnik::eGeomType>(Rice::Object x) {
  Rice::Data_Object<mapnik::eGeomType> d(x, geometry_enum);
  return *d;
}


void register_geometry(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  geometry_enum = Rice::define_enum<mapnik::eGeomType>("GeometryType", rb_mapnik);
  geometry_enum.define_value("Point",mapnik::Point);
  geometry_enum.define_value("LineString",mapnik::LineString);
  geometry_enum.define_value("Polygon",mapnik::Polygon);
  geometry_enum.define_value("MultiPoint",mapnik::MultiPoint);
  geometry_enum.define_value("MultiLineString",mapnik::MultiLineString);
  geometry_enum.define_value("MultiPolygon",mapnik::MultiPolygon);
  
  Rice::Data_Type< mapnik::geometry_type > rb_cgeometry2d = Rice::define_class_under< mapnik::geometry_type >(rb_mapnik, "Geometry2d");
  rb_cgeometry2d.define_singleton_method("from_wkt", &make_from_wkt, Rice::Arg("wkt"));
  rb_cgeometry2d.define_method("envelope", &mapnik::geometry_type::envelope);
  rb_cgeometry2d.define_method("type", &mapnik::geometry_type::type);
  rb_cgeometry2d.define_method("area", &mapnik::geometry_type::area);
}


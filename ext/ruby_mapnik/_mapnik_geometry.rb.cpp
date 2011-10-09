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

  typedef boost::ptr_vector<mapnik::geometry_type> path_type;

  // Borrowed from the python bindings...
  void from_wkt_impl(path_type& p, std::string const& wkt)
  {
      bool result = mapnik::from_wkt(wkt, p);
      if (!result) throw std::runtime_error("Failed to parse WKT");
  }

/*
  mapnik::geometry_type * from_wkt_impl(std::string const& wkt) {
    std::pair<bool,mapnik::geometry_type*> result = mapnik::from_wkt(wkt);
    if (result.first){
      return result.second;
    }
    throw std::runtime_error("Failed to parse WKT");
  }
*/

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
  rb_cgeometry2d.define_method("envelope", &mapnik::geometry_type::envelope);
  rb_cgeometry2d.define_method("type", &mapnik::geometry_type::type);
  rb_cgeometry2d.define_method("area", &mapnik::geometry_type::area);

  Rice::Data_Type< path_type > rb_cpath = Rice::define_class_under< path_type >(rb_mapnik, "Path");
  rb_cpath.define_singleton_method("from_wkt", &from_wkt_impl, Rice::Arg("wkt"));
}


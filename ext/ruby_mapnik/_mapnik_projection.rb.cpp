#include "_mapnik_projection.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>

// Mapnik
#include <mapnik/projection.hpp>

namespace {
mapnik::coord2d forward_pt(mapnik::projection const& prj, mapnik::coord2d const& pt)
{
    double x = pt.x;
    double y = pt.y;
    prj.forward(x,y);
    return mapnik::coord2d(x,y);
}
    
mapnik::coord2d inverse_pt(mapnik::projection const& prj, mapnik::coord2d const& pt)
{
    double x = pt.x;
    double y = pt.y;
    prj.inverse(x,y);
    return mapnik::coord2d(x,y);
}
   
mapnik::box2d<double> forward_env(mapnik::projection const& prj, mapnik::box2d<double> const & box)
{
    double minx = box.minx();
    double miny = box.miny();
    double maxx = box.maxx();
    double maxy = box.maxy();
    prj.forward(minx,miny);
    prj.forward(maxx,maxy);
    return mapnik::box2d<double>(minx,miny,maxx,maxy);
}
   
mapnik::box2d<double> inverse_env(mapnik::projection const& prj, mapnik::box2d<double> const & box)
{
    double minx = box.minx();
    double miny = box.miny();
    double maxx = box.maxx();
    double maxy = box.maxy();
    prj.inverse(minx,miny);
    prj.inverse(maxx,maxy);
    return mapnik::box2d<double>(minx,miny,maxx,maxy);
}
   
}


void register_projection(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::projection > rb_cproj = Rice::define_class_under< mapnik::projection >(rb_mapnik, "Projection");
  rb_cproj.define_constructor(Rice::Constructor< mapnik::projection, std::string >());
  rb_cproj.define_method("params", &mapnik::projection::params);
  rb_cproj.define_method("geographic?", &mapnik::projection::is_geographic);
  rb_cproj.define_method("expanded_params", &mapnik::projection::expanded);
  
  rb_cproj.define_method("__forward_pt__",&forward_pt);
  rb_cproj.define_method("__inverse_pt__",&inverse_pt);
  rb_cproj.define_method("__forward_env__",&forward_env);
  rb_cproj.define_method("__inverse_env__",&inverse_env);
  
}
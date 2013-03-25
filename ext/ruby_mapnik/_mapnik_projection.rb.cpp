#include "_mapnik_projection.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>

// Mapnik
#include <mapnik/projection.hpp>
#include <mapnik/coord.hpp>
#include <mapnik/box2d.hpp>

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
  
  /*
  * Document-method: new
  * call-seq:
  *   new(srs)
  * @param [String] srs
  * @return [Mapnik::Projection]
  */
  rb_cproj.define_constructor(Rice::Constructor< mapnik::projection, std::string >());
  
  /*
  * Document-method: params
  * @return [String] The srs params
  */
  rb_cproj.define_method("params", &mapnik::projection::params);
  
  /*
  * Document-method: geographic?
  * @return [Boolean]
  */
  rb_cproj.define_method("geographic?", &mapnik::projection::is_geographic);
  
  /* Document-method: expanded_params
  * @return [String] expanded set of srs params
  */
  rb_cproj.define_method("expanded_params", &mapnik::projection::expanded);
  
  // Dont-Document-method: __forward_pt__
  rb_cproj.define_method("__forward_pt__",&forward_pt);

  // Dont-Document-method: __inverse_pt__
  rb_cproj.define_method("__inverse_pt__",&inverse_pt);
  
  // Dont-Document-method: __forward_env__
  rb_cproj.define_method("__forward_env__",&forward_env);
  
  // Dont-Document-method: __inverse_env__
  rb_cproj.define_method("__inverse_env__",&inverse_env);
  
}
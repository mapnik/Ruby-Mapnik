#include "_mapnik_feature.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>

// Mapnik
#include <mapnik/wkt/wkt_factory.hpp>
#include <mapnik/feature.hpp>

// A cop out of sorts. I'll need to do more research on how to transfer ownership
// via rice.
void add_geometry(mapnik::Feature * self, std::string wkt){
  std::pair<bool,mapnik::geometry_type*> result = mapnik::from_wkt(wkt);
  if (result.first){
    self->add_geometry(result.second);
  } else {
    throw std::runtime_error("Failed to parse WKT");
  }
}

void register_feature(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::Feature > rb_cfeature = Rice::define_class_under< mapnik::Feature >(rb_mapnik, "Feature");
  rb_cfeature.define_constructor(Rice::Constructor< mapnik::Feature,int >());
  rb_cfeature.define_method("id", &mapnik::Feature::id);
  rb_cfeature.define_method("to_s", &mapnik::Feature::to_string);
  rb_cfeature.define_method("number_of_geometries", &mapnik::Feature::num_geometries);
  rb_cfeature.define_method("envelope", &mapnik::Feature::envelope);
  
  rb_cfeature.define_method("add_geometry", &add_geometry, Rice::Arg("geom"));  
}
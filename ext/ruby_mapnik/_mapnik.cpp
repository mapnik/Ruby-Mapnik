#include "_mapnik.h"

void register_mapnik(){
  Rice::Module rb_mapnik = Rice::define_module("Mapnik");
  
  register_color(rb_mapnik);
  register_coord(rb_mapnik);
  register_datasource(rb_mapnik);
}
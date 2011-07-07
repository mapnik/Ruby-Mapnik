#include "_mapnik_coord.rb.h"

void wrap_mapnik_coord_double__2__x_set(mapnik::coord2d* self, double val) {
  self->x = val;
}
double wrap_mapnik_coord_double__2__x_get(mapnik::coord2d* self) {
  return self->x;
}
void wrap_mapnik_coord_double__2__y_set(mapnik::coord2d* self, double val) {
  self->y = val;
}
double wrap_mapnik_coord_double__2__y_get(mapnik::coord2d* self) {
  return self->y;
}

mapnik::coord2d wrap_mapnik_coord_double__2__times_equals(mapnik::coord2d self, float value){
  return self *= value;
}

mapnik::coord2d wrap_mapnik_coord_double__2__addition(mapnik::coord2d self, float value){
  return self += value;
}

mapnik::coord2d wrap_mapnik_coord_double__2__subtraction(mapnik::coord2d self, float value){
  return self -= value;
}

mapnik::coord2d wrap_mapnik_coord_double__2__division(mapnik::coord2d self, float value){
  return self /= value;
}

bool wrap_mapnik_coord_double__2__equality(mapnik::coord2d self, mapnik::coord2d rhs){
  return self == rhs;
}

void register_coord(Rice::Module rb_mmapnik) {
  Rice::Data_Type< mapnik::coord2d > rb_ccoord2d = Rice::define_class_under< mapnik::coord2d >(rb_mmapnik, "Coord2d");
  rb_ccoord2d.define_constructor(Rice::Constructor< mapnik::coord2d,double,double >());
  rb_ccoord2d.define_method("x=", &wrap_mapnik_coord_double__2__x_set);
  rb_ccoord2d.define_method("x", &wrap_mapnik_coord_double__2__x_get);
  rb_ccoord2d.define_method("y=", &wrap_mapnik_coord_double__2__y_set);
  rb_ccoord2d.define_method("y", &wrap_mapnik_coord_double__2__y_get);
  rb_ccoord2d.define_method("*", &wrap_mapnik_coord_double__2__times_equals, (Rice::Arg("value")));
  rb_ccoord2d.define_method("==", &wrap_mapnik_coord_double__2__equality, (Rice::Arg("rhs")));
  rb_ccoord2d.define_method("+", &wrap_mapnik_coord_double__2__addition, (Rice::Arg("value")));
  rb_ccoord2d.define_method("-", &wrap_mapnik_coord_double__2__subtraction, (Rice::Arg("value")));
  rb_ccoord2d.define_method("/", &wrap_mapnik_coord_double__2__division, (Rice::Arg("value")));
}
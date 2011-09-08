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
#include "_mapnik_coord.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>

// Mapnik
#include <mapnik/coord.hpp>

namespace {
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
}
void register_coord(Rice::Module rb_mapnik) {
  /*
  * @@Module_var rb_mapnik = Mapnik
  *  
  * Document-class: Mapnik::Coord2d
  * A two dimensional coordinate
  */
  Rice::Data_Type< mapnik::coord2d > rb_ccoord2d = Rice::define_class_under< mapnik::coord2d >(rb_mapnik, "Coord2d");
  
  /*
  * Document-method: new
  * call-seq:
  *   new(x,y)
  * Returns a new Coord2d object
  */
  rb_ccoord2d.define_constructor(Rice::Constructor< mapnik::coord2d,double,double >());
  
  /*
  * Document-method: x=
  * @param [Float]
  * Sets the x value of the coord
  */
  rb_ccoord2d.define_method("x=", &wrap_mapnik_coord_double__2__x_set);
  rb_ccoord2d.define_method("x", &wrap_mapnik_coord_double__2__x_get);

  /*
  * Document-method: y=
  * @param [Float]
  * Sets the y value of the coord
  */
  rb_ccoord2d.define_method("y=", &wrap_mapnik_coord_double__2__y_set);
  rb_ccoord2d.define_method("y", &wrap_mapnik_coord_double__2__y_get);
  

  /*
  * Document-method: *
  * call-seq:
  *   * value
  * @param [Float]
  * Multiplies the x and y coordinates of the receiver by the value provided
  */
  rb_ccoord2d.define_method("*", &wrap_mapnik_coord_double__2__times_equals, (Rice::Arg("value")));

  /*
  * Document-method: ==
  * call-seq:
  *   ==(other_coord)
  * @param [Mapnik::Coord2d]
  * Returns true if the x and y values of other_coord equal those of the reciever
  */
  rb_ccoord2d.define_method("==", &wrap_mapnik_coord_double__2__equality, (Rice::Arg("rhs")));

  /*
  * Document-method: +=
  * call-seq:
  *   + value 
  * @param [Float]
  * Adds the x and y coordinates of the receiver by the value provided
  */
  rb_ccoord2d.define_method("+", &wrap_mapnik_coord_double__2__addition, (Rice::Arg("value")));
  
  /*
  * Document-method: -=
  * call-seq:
  *   - value 
  * @param [Float]
  * Subtracts the x and y coordinates of the receiver by the value provided
  */
  rb_ccoord2d.define_method("-", &wrap_mapnik_coord_double__2__subtraction, (Rice::Arg("value")));
  
  /*
  * Document-method: /=
  * call-seq:
  *   /=(value)
  * @param [Float]
  * Divides the x and y coordinates of the receiver by the value provided
  */
  rb_ccoord2d.define_method("/", &wrap_mapnik_coord_double__2__division, (Rice::Arg("value")));

}
/*****************************************************************************
 * 
 * Copyright (C) 2011 Elliot Laster
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
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
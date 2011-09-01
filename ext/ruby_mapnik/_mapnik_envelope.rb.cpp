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
#include "_mapnik_envelope.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>

// Mapnik
#include <mapnik/box2d.hpp>

namespace {
  // Height
  typedef double ( mapnik::box2d<double>::*height_func_type )() const;
  typedef void ( mapnik::box2d<double>::*set_height_func_type )(double h);

  // Width
  typedef double ( mapnik::box2d<double>::*width_func_type )() const;
  typedef void ( mapnik::box2d<double>::*set_width_func_type )(double w);

  // Re-center
  typedef void ( mapnik::box2d<double>::*re_center_func_type )( double x, double y );
  typedef void ( mapnik::box2d<double>::*re_center_func_type_coord )( const mapnik::coord2d& other );

  // Contains
  typedef bool (mapnik::box2d<double>::*contains_xy_func_type)(double x,double y) const;
  typedef bool (mapnik::box2d<double>::*contains_coord_func_type)(const mapnik::coord2d &c) const;
  typedef bool (mapnik::box2d<double>::*contains_envelope_func_type)(const mapnik::box2d<double> &other) const;

  // Intersects
  typedef bool (mapnik::box2d<double>::*intersects_xy_func_type)(double x,double y) const;
  typedef bool (mapnik::box2d<double>::*intersects_coord_func_type)(const mapnik::coord2d &c) const;
  typedef bool (mapnik::box2d<double>::*intersects_envelope_func_type)(const mapnik::box2d<double> &other) const;

  // Expand to include
  typedef void ( mapnik::box2d<double>::*expand_to_include_xy_func_type )( double x, double y );
  typedef void ( mapnik::box2d<double>::*expand_to_include_coord_func_type )( const mapnik::coord2d& c );
  typedef void ( mapnik::box2d<double>::*expand_to_include_envelope_func_type )( const mapnik::box2d<double>& other );

  bool wrap_mapnik_box2d_double__2__equality(mapnik::box2d<double> self, mapnik::box2d<double> rhs){
    return self == rhs;
  }
}
void register_envelope(Rice::Module rb_mapnik){
  /*
    @@Module_var rb_mapnik = Mapnik
  */
  Rice::Data_Type< mapnik::box2d<double> > rb_cenvelope = Rice::define_class_under< mapnik::box2d<double> >(rb_mapnik, "Envelope");
  
  /*
  * Document-method: new
  * call-seq:
  *   new(min_x, min_y, max_x, max_y)
  * 
  * @param [Float] min_x
  * @param [Float] min_y
  * @param [Float] max_x
  * @param [Float] max_y
  *
  * Returns a new Mapnik::Envelope
  */
  rb_cenvelope.define_constructor(Rice::Constructor< mapnik::box2d<double>,double,double,double,double >());
  
  /*
  * Document-method: min_x
  * @return [Float]
  */
  rb_cenvelope.define_method("min_x", &mapnik::box2d<double>::minx);
  
  /*
  * Document-method: min_y
  * @return [Float]
  */
  rb_cenvelope.define_method("min_y", &mapnik::box2d<double>::miny);
  
  /*
  * Document-method: max_x
  * @return [Float]
  */
  rb_cenvelope.define_method("max_x", &mapnik::box2d<double>::maxx);
  
  /*
  * Document-method: max_y
  * @return [Float]
  */
  rb_cenvelope.define_method("max_y", &mapnik::box2d<double>::maxy);

  /*
  * Document-method: center
  * @return [Mapnik::Coord2d] the center of the envelope.
  */
  rb_cenvelope.define_method("center", &mapnik::box2d<double>::center);

  /*
  * Dont-Document-method: re_center_to_xy!
  */
  rb_cenvelope.define_method("re_center_to_xy!", re_center_func_type( &mapnik::box2d<double>::re_center ), (Rice::Arg("x"), Rice::Arg("y")));
  
  /*
  * Dont-Document-method: re_center_to_coord!
  */
  rb_cenvelope.define_method("re_center_to_coord!", re_center_func_type_coord( &mapnik::box2d<double>::re_center ), (Rice::Arg("other")));


  rb_cenvelope.define_method("height", height_func_type( &mapnik::box2d<double>::height ));
  rb_cenvelope.define_method("height=", set_height_func_type( &mapnik::box2d<double>::height ), (Rice::Arg("h")));
  
  rb_cenvelope.define_method("width", height_func_type( &mapnik::box2d<double>::width ));
  rb_cenvelope.define_method("width=", set_height_func_type( &mapnik::box2d<double>::width ), (Rice::Arg("w")));
  
  /*
  * Dont-Document-method: contains_xy?
  */
  rb_cenvelope.define_method("contains_xy?", contains_xy_func_type( &mapnik::box2d<double>::contains ), (Rice::Arg("x"), Rice::Arg("y")));
  
  /*
  * Dont-Document-method: contains_coord?
  */
  rb_cenvelope.define_method("contains_coord?", contains_coord_func_type( &mapnik::box2d<double>::contains ), (Rice::Arg("c")));
  
  /*
  * Dont-Document-method: contains_envelope?
  */
  rb_cenvelope.define_method("contains_envelope?", contains_envelope_func_type( &mapnik::box2d<double>::contains ), (Rice::Arg("other")));
  
  /*
  * Dont-Document-method: intersects_xy?
  */
  rb_cenvelope.define_method("intersects_xy?", intersects_xy_func_type( &mapnik::box2d<double>::intersects ), (Rice::Arg("x"), Rice::Arg("y")));
  
  /*
  * Dont-Document-method: intersects_coord?
  */
  rb_cenvelope.define_method("intersects_coord?", intersects_coord_func_type( &mapnik::box2d<double>::intersects ), (Rice::Arg("c")));
  
  /*
  * Dont-Document-method: intersects_envelope?
  */
  rb_cenvelope.define_method("intersects_envelope?", intersects_envelope_func_type( &mapnik::box2d<double>::intersects ), (Rice::Arg("other")));  
  
  /*
  * Dont-Document-method: expand_to_include_xy!
  */
  rb_cenvelope.define_method("expand_to_include_xy!", expand_to_include_xy_func_type( &mapnik::box2d<double>::expand_to_include ), (Rice::Arg("x"), Rice::Arg("y")));
  
  /*
  * Dont-Document-method: expand_to_include_coord!
  */
  rb_cenvelope.define_method("expand_to_include_coord!", expand_to_include_coord_func_type( &mapnik::box2d<double>::expand_to_include ), (Rice::Arg("c")));
  
  /*
  * Dont-Document-method: expand_to_include_envelope!
  */
  rb_cenvelope.define_method("expand_to_include_envelope!", expand_to_include_envelope_func_type( &mapnik::box2d<double>::expand_to_include ), (Rice::Arg("other")));
  
  /*
  * Document-method: intersection
  * call-seq:
  *  intersection(other_envelope)
  *
  * @param [Mapnik::Envelope] the other envelope
  *
  * Returns a new envelope that is the intersection of another envelope and
  * the reciever.
  *
  * @return [Mapnik::Envelope]
  */
  rb_cenvelope.define_method("intersection", &mapnik::box2d<double>::intersect, Rice::Arg("other"));
  
  /*
  * Document-method: clip!
  * call-seq:
  *  clip!(other_envelope)
  *
  * @param [Mapnik::Envelope] the other envelope
  *
  * Clips the reciever by another other envelope
  * @return [nil]
  */
  rb_cenvelope.define_method("clip!", &mapnik::box2d<double>::clip, Rice::Arg("other"));
  
  /*
  * Document-method: valid?
  * Returns true if the envelope is sound.
  * @return [Boolean]
  */
  rb_cenvelope.define_method("valid?", &mapnik::box2d<double>::valid);
  
  /*
  * Document-method: ==
  * call-seq:
  *  ==(other_envelope)
  *
  * Returns true if the other envelope's coordinates match the reciever's
  *
  * @return [Boolean]
  */
  rb_cenvelope.define_method("==", &wrap_mapnik_box2d_double__2__equality, (Rice::Arg("rhs")));
  
}
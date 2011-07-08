#include "_mapnik_envelope.rb.h"

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

// Expand to include
typedef void ( mapnik::box2d<double>::*expand_to_include_xy_func_type )( double x, double y );
typedef void ( mapnik::box2d<double>::*expand_to_include_coord_func_type )( const mapnik::coord2d& c );
typedef void ( mapnik::box2d<double>::*expand_to_include_envelope_func_type )( const mapnik::box2d<double>& other );


void register_envelope(Rice::Module rb_mapnik){
  
  Rice::Data_Type< mapnik::box2d<double> > rb_cenvelope = Rice::define_class_under< mapnik::box2d<double> >(rb_mapnik, "Envelope");
  rb_cenvelope.define_constructor(Rice::Constructor< mapnik::box2d<double>,double,double,double,double >());
  
  rb_cenvelope.define_method("min_x", &mapnik::box2d<double>::minx);
  rb_cenvelope.define_method("min_y", &mapnik::box2d<double>::miny);
  rb_cenvelope.define_method("max_x", &mapnik::box2d<double>::maxx);
  rb_cenvelope.define_method("max_y", &mapnik::box2d<double>::maxy);

  rb_cenvelope.define_method("center", &mapnik::box2d<double>::center);
  rb_cenvelope.define_method("re_center_to_xy", re_center_func_type( &mapnik::box2d<double>::re_center ), (Rice::Arg("x"), Rice::Arg("y")));
  rb_cenvelope.define_method("re_center_to_coord", re_center_func_type_coord( &mapnik::box2d<double>::re_center ), (Rice::Arg("other")));

  rb_cenvelope.define_method("height", height_func_type( &mapnik::box2d<double>::height ));
  rb_cenvelope.define_method("height=", set_height_func_type( &mapnik::box2d<double>::height ), (Rice::Arg("h")));
  
  rb_cenvelope.define_method("width", height_func_type( &mapnik::box2d<double>::width ));
  rb_cenvelope.define_method("width=", set_height_func_type( &mapnik::box2d<double>::width ), (Rice::Arg("w")));
  
  rb_cenvelope.define_method("contains_xy?", contains_xy_func_type( &mapnik::box2d<double>::contains ), (Rice::Arg("x"), Rice::Arg("y")));
  rb_cenvelope.define_method("contains_coord?", contains_coord_func_type( &mapnik::box2d<double>::contains ), (Rice::Arg("c")));
  rb_cenvelope.define_method("contains_envelope?", contains_envelope_func_type( &mapnik::box2d<double>::contains ), (Rice::Arg("other")));
  
  rb_cenvelope.define_method("expand_to_include_xy", expand_to_include_xy_func_type( &mapnik::box2d<double>::expand_to_include ), (Rice::Arg("x"), Rice::Arg("y")));
  rb_cenvelope.define_method("expand_to_include_coord", expand_to_include_coord_func_type( &mapnik::box2d<double>::expand_to_include ), (Rice::Arg("c")));
  
}
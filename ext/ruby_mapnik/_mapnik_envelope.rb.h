#ifndef PIKA2_MAPNIK_ENVELOPE
#define PIKA2_MAPNIK_ENVELOPE
  // Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>

  // Mapnik
#include <mapnik2/box2d.hpp>

void register_envelope(Rice::Module rb_mapnik);

#endif
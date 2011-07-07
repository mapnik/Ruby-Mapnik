#ifndef PIKA2_MAPNIK_DATASOURCE
#define PIKA2_MAPNIK_DATASOURCE
  // Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Hash.hpp>
#include <rice/Array.hpp>

  // Mapnik
#include <mapnik2/datasource.hpp>
#include <mapnik2/datasource_cache.hpp>
#include <mapnik2/feature_layer_desc.hpp>

void register_datasource(Rice::Module rb_mapnik);

#endif
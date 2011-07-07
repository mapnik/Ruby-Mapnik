#ifndef PIKA2_MAPNIK_DATASOURCE_CACHE
#define PIKA2_MAPNIK_DATASOURCE_CACHE
  // Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Array.hpp>

  // Mapnik
#include <mapnik2/datasource.hpp>
#include <mapnik2/datasource_cache.hpp>

void register_datasource_cache(Rice::Module rb_mapnik);

#endif
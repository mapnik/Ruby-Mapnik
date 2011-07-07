#include <rice/Module.hpp>
#include "_mapnik.h"

extern "C"

void Init_ruby_mapnik() {
  RUBY_TRY {
    register_mapnik();
  } RUBY_CATCH
}
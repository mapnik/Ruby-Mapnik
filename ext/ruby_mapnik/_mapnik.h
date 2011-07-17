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
#ifndef mapnik_HPP
#define mapnik_HPP

  // Rice
#include <rice/Enum.hpp>
#include <rice/Object.hpp>
#include <rice/Data_Type.hpp>
#include <rice/Data_Object.hpp>
#include <rice/Allocation_Strategies.hpp>
#include <rice/Module.hpp>
#include <rice/Enum.hpp>

// // Mapnik
// #include <mapnik2/map.hpp>

// Ruby Mapnik
#include "_mapnik_color.rb.h"
#include "_mapnik_coord.rb.h"
#include "_mapnik_datasource.rb.h"
#include "_mapnik_datasource_cache.rb.h"
#include "_mapnik_envelope.rb.h"
#include "_mapnik_feature.rb.h"
#include "_mapnik_geometry.rb.h"
 
#include "_mapnik_polygon_symbolizer.rb.h" 
#include "_mapnik_line_symbolizer.rb.h" 
#include "_mapnik_stroke.rb.h" 
#include "_mapnik_rule.rb.h"

#include "_mapnik_expression.rb.h"
#include "_mapnik_symbolizer.rb.h"
 
void register_mapnik();

#endif
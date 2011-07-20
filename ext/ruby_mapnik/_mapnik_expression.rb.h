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
#ifndef PIKA2_MAPNIK_EXPRESSION
#define PIKA2_MAPNIK_EXPRESSION

  // Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>
#include <rice/Enum.hpp>

  // Mapnik
#include <mapnik2/feature.hpp>
#include <mapnik2/filter_factory.hpp>
#include <mapnik2/expression_node.hpp>
#include <mapnik2/expression_string.hpp>
#include <mapnik2/expression_evaluator.hpp>
#include <mapnik2/parse_path.hpp>

void register_expression(Rice::Module rb_mapnik);

#endif
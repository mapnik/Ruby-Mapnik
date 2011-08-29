=begin 
 ******************************************************************************
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
 ******************************************************************************
=end
require 'forwardable'

path = File.expand_path(File.dirname(__FILE__))

require 'ruby_mapnik_config'
require "#{path}/ruby_mapnik/ruby_mapnik"
require "#{path}/ruby_mapnik/mapnik/rule"
require "#{path}/ruby_mapnik/mapnik/style"
require "#{path}/ruby_mapnik/mapnik/layer"
require "#{path}/ruby_mapnik/mapnik/map"
require "#{path}/ruby_mapnik/mapnik/stroke"
require "#{path}/ruby_mapnik/mapnik/projection"
require "#{path}/ruby_mapnik/mapnik/font_engine"
require "#{path}/ruby_mapnik/mapnik/raster_colorizer"
require "#{path}/ruby_mapnik/mapnik/tile"


module Mapnik
  VERSION = '0.1'
  
  FontEngine.register_fonts(FONT_PATH)
  DatasourceCache.register(INPUT_PLUGIN_PATH)

  if DatasourceCache.available_plugins.empty?
    puts "RUBY-MAPNIK WARNING: No datasource plugins were found!"
  end
end
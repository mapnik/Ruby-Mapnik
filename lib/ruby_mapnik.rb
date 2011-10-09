=begin 
Copyright (C) 2011 Elliot Laster

Permission is hereby granted, free of charge, to any person obtaining a copy of 
this software and associated documentation files (the ‘Software’), to deal in 
the Software without restriction, including without limitation the rights to 
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all 
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED ‘AS IS’, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
SOFTWARE.
=end
require 'forwardable'

path = File.expand_path(File.dirname(__FILE__))

require "#{path}/ruby_mapnik_config"
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
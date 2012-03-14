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
module Mapnik

  class Tile
    
    # 900913
    DEFAULT_OUTPUT_PROJECTION = "+proj=merc +a=6378137 +b=6378137 +lat_ts=0.0 +lon_0=0.0 +x_0=0.0 +y_0=0 +k=1.0 +units=m +nadgrids=@null +no_defs +over"
    DEFAULT_HEIGHT = 256
    DEFAULT_WIDTH = 256
    
    include Math

    attr_accessor :min_x, :min_y, :max_x, :max_y, 
                  :zoom, :x, :y, :output_projection,
                  :height, :width

    def initialize(zoom, x, y, projection = nil)
      @zoom = zoom.to_i
      @x = x.to_i
      @y = y.to_i
      @output_projection = projection || DEFAULT_OUTPUT_PROJECTION.dup
      @height = DEFAULT_HEIGHT
      @width = DEFAULT_WIDTH
      setup_bounds
    end
      
    def render(map, filename, format=nil)
      map.height = @height
      map.width = @width
      map.zoom_to_box(forwarded_envelope)
      map.render_to_file(filename, format)
    end

    def render_to_string(map)
      map.height = @height
      map.width = @width
      map.zoom_to_box(forwarded_envelope)
      map.render_to_string('png')
    end

    def envelope
      @envelope ||= Mapnik::Envelope.new(@min_x, @min_y, @max_x, @max_y)
    end

    def forwarded_envelope
      projection = Mapnik::Projection.new(@output_projection)
      projection.forward(envelope)
    end

  private
  
    def setup_map_for_render(map)
      map.height = @height
      map.width = @width
      map.zoom_to_box(forwarded_envelope)
    end
  
    def setup_bounds
      @max_x, @min_y = zoom_x_y_to_lat_lng(@zoom, @x, @y)
      @min_x, @max_y = zoom_x_y_to_lat_lng(@zoom, @x + 1, @y + 1)
    end

    def zoom_x_y_to_lat_lng(zoom, x, y)
      n = 2.0 ** zoom
      lon_deg = x / n * 360.0 - 180.0
      lat_rad = atan(sinh(Math::PI * (1 - 2 * y / n)))
      lat_deg = lat_rad * 180.0 / Math::PI
      [lon_deg, lat_deg]
    end
    
  end
  
end

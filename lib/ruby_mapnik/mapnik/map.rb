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
  
  class MapStyleContainer < Hash
    
    def map=(map)
      @map = map
    end
    
    def []=(key, object)
      @map.send(:__insert_style__, key, object)
      super(key, object)
    end

    def delete(key)
      @map.send(:__remove_style__, key)
      super(key)
    end
          
  end
  
  class MapLayerContainer 
    
    extend Forwardable
    
    def_delegators :@collection, :empty?, :any?, :length, :first, :[], :count
    
    def initialize(collection)
      @collection = collection
    end
    
    def <<(object)
      @map.send(:__add_layer__, object)
      @collection << (object)
    end
    
    alias :push :<<      
    
    def clear
      (0..length-1).each{|index| remove_object_at_index(index)}
      @collection.clear
    end
    
    def delete_at(index)
       remove_object_at_index(index)
       @collection.delete_at(index)
    end
        
    def map=(map)
      @map = map
    end
    
    def pop
      delete_at(length - 1) unless length.zero?
    end
     
    private 
    
    def remove_object_at_index(index)
       @map.send(:__remove_layer__, index)
    end
          
  end
  
  class Map
    
    class << self
      
      # @return [Mapnik::Map]
      def from_xml(xml, strict = false, base_path = "")
        map = new
        __load_map_string__(map, xml, strict, base_path)
        map
      end
      
      # @return [Mapnik::Map]
      def from_file(filename, strict = false)
        map = new
        __load_map__(map, filename, strict)
        map
      end
            
    end
    
    # @return [Mapnik::Style]
    def style(name)
      style = Mapnik::Style.new
      yield style
      styles[name] = style
    end
    
    # @return [Mapnik::StyleContainer]
    def styles
      styles = MapStyleContainer[__styles__]
      styles.map = self
      styles
    end
    
    # @return [Mapnik::Layer]
    def layer(name, srs = nil)
      layer = Mapnik::Layer.new(name, srs)
      layer.map = self
      yield layer
      layers << layer
    end
    
    # @return [Mapnik::MapLayerContainer]
    def layers
      layers = MapLayerContainer.new(__layers__)
      layers.map = self
      layers
    end
    
    # @return [nil]
    def render_to_file(filename)
      __render_to_file__(filename)
    end
      
    private :__styles__, :__insert_style__, :__remove_style__, :__layers__, 
            :__add_layer__, :__remove_layer__
    
  end
  
end
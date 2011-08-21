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
      
      def from_xml(xml, strict = false, base_path = "")
        map = new
        __load_map_string__(map, xml, strict, base_path)
        map
      end
      
      def from_file(filename, strict = false)
        map = new
        __load_map__(map, filename, strict)
        map
      end
            
    end
    
    def style(name)
      style = Mapnik::Style.new
      yield style
      styles[name] = style
    end
    
    def styles
      styles = MapStyleContainer[__styles__]
      styles.map = self
      styles
    end
    
    def layer(name, srs = nil)
      layer = Mapnik::Layer.new(name, srs)
      layer.map = self
      yield layer
      layers << layer
    end
    
    def layers
      layers = MapLayerContainer.new(__layers__)
      layers.map = self
      layers
    end
    
    def render_to_file(filename)
      __render_to_file__(filename)
    end
      
    private :__styles__, :__insert_style__, :__remove_style__, :__layers__, 
            :__add_layer__, :__remove_layer__
    
  end
  
end
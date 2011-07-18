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

    # TODO: Maybe?
    # def [](key)
    #   @map.send(:__find_style__, key)
    # end  
          
  end
  
  class MapLayerContainer < Array
    
    # TODO: Rethink this?
    undef :insert, :replace, :flatten, :reject, :pack, :zip, :reverse, :sort, 
          :uniq, :shift, :unshift, :sort!, :pop, :delete_at
    
    def map=(map)
      @map = map
    end
    
    def <<(object)
      @map.send(:__add_layer__, object)
      super(object)
    end      
          
    alias :push :<<      
    
    def delete_at(index)
       remove_object_at_index(index)
       super(index)
     end

     def pop
       delete_at(length - 1) unless length.zero?
     end

     def clear
       (0..length-1).each{|index| remove_object_at_index(index)}
       super
     end
     
    private 
     
     def remove_object_at_index(index)
       @map.send(:__remove_layer__, index)
     end
          
  end
  
  class Map
    
    def styles
      styles = MapStyleContainer[__styles__]
      styles.map = self
      styles
    end
    
    def layers
      layers = MapLayerContainer.new(__layers__)
      layers.map = self
      layers
    end
    
    private :__styles__, :__insert_style__, :__remove_style__, :__layers__, 
            :__add_layer__, :__remove_layer__
    
  end
  
end
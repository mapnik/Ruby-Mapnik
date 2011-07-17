module Mapnik
  
  class LayerStyleContainer < Array
    
    # TODO: Rethink this?
    undef :insert, :replace, :flatten, :reject, :pack, :zip, :reverse, :sort, 
          :uniq, :shift, :unshift, :sort!, :pop, :delete_at
    
    def layer=(layer)
      @layer = layer
    end
    
    def <<(object)
      @layer.send(:__append_style__, object)
      super(object)
    end      
          
    alias :push :<<      
          
  end
  
  class Layer
    
    def styles
      styles = LayerStyleContainer.new(__style_list__)
      styles.layer = self
      styles
    end
    
    private :__style_list__, :__append_style__
    
  end
  
end
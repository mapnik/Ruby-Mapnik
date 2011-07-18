module Mapnik
  
  class LayerStyleContainer
    
    extend Forwardable
    
    def_delegators :@collection, :empty?, :any?, :length, :first, :count
    
    def initialize(collection)
      @collection = collection
    end
    
    def layer=(layer)
      @layer = layer
    end
    
    def <<(object)
      @layer.send(:__append_style__, object)
      @collection << object
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
module Mapnik
  
  class StyleRuleContainer
    
    extend Forwardable
    
    def_delegators :@collection, :empty?, :any?, :length, :first, :count
    
    def initialize(collection)
      @collection = collection
    end
    
    def style=(style)
      @style = style
    end
    
    def <<(object)
      @style.send(:__add_rule__, object)
      @collection << object
    end      
          
    alias :push :<<      
          
  end
  
  class Style
    
    def rules
      rules = StyleRuleContainer.new(__rules__)
      rules.style = self
      rules
    end
    
    private :__rules__, :__add_rule__
    
  end
  
end
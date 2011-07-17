module Mapnik
  
  class StyleRuleContainer < Array
    
    # TODO: Rethink this?
    undef :insert, :replace, :flatten, :reject, :pack, :zip, :reverse, :sort, 
          :uniq, :shift, :unshift, :sort!, :pop, :delete_at
    
    def style=(style)
      @style = style
    end
    
    def <<(object)
      @style.send(:__add_rule__, object)
      super(object)
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
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
    
    def rule(filter_string = 'true')
      rule = Mapnik::Rule.new
      rule.filter = Mapnik::Expression.parse(filter_string)
      yield rule
      self.rules << rule
    end
    
    def rules
      rules = StyleRuleContainer.new(__rules__)
      rules.style = self
      rules
    end
    
    private :__rules__, :__add_rule__
    
  end
  
end
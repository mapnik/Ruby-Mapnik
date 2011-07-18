module Mapnik

  class RuleSymbolContainer < Array
    
    extend Forwardable
    
    def_delegators :@collection, :empty?, :any?, :length, :first, :count
    
    def initialize(collection)
      @collection = collection
    end
    
    def rule=(rule)
      @rule = rule
    end
    
    def <<(object)
      symbolizer_object = Mapnik::Symbolizer.from_subtype(object)
      @rule.send(:__append_symbol__, symbolizer_object)
      @collection << symbolizer_object
    end
    
    alias :push :<<
    
    def delete_at(index)
      remove_object_at_index(index)
      @collection.delete_at(index)
    end
  
    def pop
      delete_at(length - 1) unless length.zero?
    end
    
    def clear
      (0..length-1).each{|index| remove_object_at_index(index)}
      @collection.clear
    end
    
    private
      
      def remove_object_at_index(index)
        @rule.send(:__remove_symbol__, index)
      end
    
  end

  class Rule
    
    def symbols
      symbol_container = RuleSymbolContainer.new(__symbols__)
      symbol_container.rule = self
      symbol_container
    end
    
    private :__symbols__, :__append_symbol__, :__remove_symbol__
    
  end
end


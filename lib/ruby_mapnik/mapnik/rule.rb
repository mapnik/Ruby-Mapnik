module Mapnik

  class RuleSymbolContainer < Array
    
    # TODO: Make sure these are complete and sane. I'd like to accomodate as many
    # as possible.
    undef :insert, :replace, :flatten, :reject, :pack, :zip, :reverse, :sort, 
          :uniq, :shift, :unshift, :sort!
    
    def rule=(rule)
      @rule = rule
    end
    
    def <<(object)
      symbolizer_object = Mapnik::Symbolizer.from_subtype(object)
      @rule.send(:__append_symbol__, symbolizer_object)
      super(symbolizer_object)
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


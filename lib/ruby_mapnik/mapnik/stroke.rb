module Mapnik
  
  class StrokeDashContainer
    
    extend Forwardable
    
    def_delegators :@collection, :empty?, :any?, :length, :first, :count, :[]
    
    def initialize(collection)
      @collection = collection.map{|x| {:length => x[0], :gap => x[1]}}
    end
    
    def stroke=(stroke)
      @stroke = stroke
    end
    
    def <<(dash_hash)
      @stroke.send(:__add_dash__, dash_hash[:length], dash_hash[:gap])
    end
    
    alias :push :<<
    
  end
  
  class Stroke
    
    def dashes
      dashes = StrokeDashContainer.new(__dashes__)
      dashes.stroke = self
      dashes
    end
    
    private :__dashes__, :__add_dash__
    
  end
  
end
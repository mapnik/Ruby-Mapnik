module Mapnik
  
  class ColorizerStopCollection
    
    extend Forwardable
    
    def_delegators :@collection, :empty?, :any?, :length, :first, :count
    
    def initialize(collection)
      @collection = collection
    end
    
    def delegate=(object)
      @delegate = object
    end
    
    def <<(stop)
      @delegate.__add_stop__(stop)
      @collection << stop
    end

  end
  
  class RasterColorizer
    
    def stops
      stops = ColorizerStopCollection.new(__stops__)
      stops.delegate = self
      stops
    end
    
  end
  
end
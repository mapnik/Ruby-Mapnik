=begin
Copyright (C) 2011 Elliot Laster

Permission is hereby granted, free of charge, to any person obtaining a copy of 
this software and associated documentation files (the ‘Software’), to deal in 
the Software without restriction, including without limitation the rights to 
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all 
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED ‘AS IS’, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
SOFTWARE.
=end
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
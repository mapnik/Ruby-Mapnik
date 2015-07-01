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

  end

end

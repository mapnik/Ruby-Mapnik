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

  class RuleSymbolContainer < Array

    extend Forwardable

    def_delegators :@collection, :empty?, :any?, :length, :first, :count, :[]

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

    def polygon
      polygon = Mapnik::PolygonSymbolizer.new
      yield polygon
      symbols << polygon
    end

    def fill=(color)
      polygon = Mapnik::PolygonSymbolizer.new
      polygon.fill = color
      symbols << polygon
    end

    def line
      stroke = Mapnik::Stroke.new(Mapnik::Color.new, 1.0)
      yield stroke
      line = Mapnik::LineSymbolizer.new
      line.stroke = stroke
      symbols << line
    end

    def text(expression_text)
      exp = Mapnik::Expression.parse(expression_text)
      text = Mapnik::TextSymbolizer.new(exp, 'DejaVu Sans Book', 10, Mapnik::Color.new)
      yield text
      symbols << text
    end

    def symbols
      symbol_container = RuleSymbolContainer.new(__symbols__)
      symbol_container.rule = self
      symbol_container
    end

  end
end

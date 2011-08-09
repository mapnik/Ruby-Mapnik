require "test_helper"

class TestMapnikLineSymbolizer < Test::Unit::TestCase
  
  def test_presence
    assert Mapnik::LineSymbolizer
  end
  
  def test_should_instantiate
    assert Mapnik::LineSymbolizer.new
  end
  
  def test_should_get_and_set_stroke
    line = Mapnik::LineSymbolizer.new
    stroke_before = line.stroke
    assert stroke_before.kind_of?(Mapnik::Stroke)
    
    new_stroke = Mapnik::Stroke.new(Mapnik::Color.new("#fff"), 1.0)
    line.stroke = new_stroke
    
    # Once Equality for strokes is established
    # assert_equal new_stroke, line.stroke
  end
  
end
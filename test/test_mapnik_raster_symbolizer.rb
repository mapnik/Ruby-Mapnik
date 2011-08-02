require "test_helper"

class TestMapnikRasterSymbolizer < Test::Unit::TestCase
  
  def setup
    @sym = Mapnik::RasterSymbolizer.new
  end
  
  def test_presence
    assert Mapnik::RasterSymbolizer
  end
  
  def test_should_get_and_set_mode
    possible_values = ["normal", "grain_merge", "grain_merge2", "multiply",
     "multiply2", "divide", "divide2", "screen", "hard_light"]
    possible_values.each do |value|
      @sym.mode = value
      assert_equal value, @sym.mode
    end
  end
  
  def test_should_get_and_set_scaling
    possible_values = [ "fast","bilinear","bilinear8"]
    possible_values.each do |value|
      @sym.scaling = value
      assert_equal value, @sym.scaling
    end
  end
  
  def test_should_get_and_set_opacity
    @sym.opacity = 0.5
    assert_equal 0.5, @sym.opacity
  end
  
  def test_should_get_and_set_filter_factor
    @sym.filter_factor = 0.5
    assert_equal 0.5, @sym.filter_factor
  end
  
end
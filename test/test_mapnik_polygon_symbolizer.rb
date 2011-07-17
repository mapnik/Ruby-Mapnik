require "test_helper"

class TestMapnikPolygonSymbolizer < Test::Unit::TestCase
  
  def test_presence
    assert Mapnik::PolygonSymbolizer
  end
  
  def test_should_instantiate
    assert Mapnik::PolygonSymbolizer.new
  end
  
  def test_should_get_and_set_fill_to_a_color
    polygon = Mapnik::PolygonSymbolizer.new
    color_before = polygon.fill
    assert color_before.kind_of?(Mapnik::Color)
    
    new_color = Mapnik::Color.new(50,40,13,1)
    polygon.fill = new_color
    
    assert [:red, :green, :blue, :alpha].all?{|x| polygon.fill.send(x) == new_color.send(x)}
  end
  
  def test_should_get_and_set_opacity
    polygon = Mapnik::PolygonSymbolizer.new
    opacity_before = polygon.opacity
    assert_equal 1, opacity_before
    
    new_opacity = 0.5
    polygon.opacity = new_opacity
    assert_equal new_opacity, polygon.opacity
  end
  
  def test_should_get_and_set_gamma
    polygon = Mapnik::PolygonSymbolizer.new
    gamma_before = polygon.gamma
    assert_equal 1, gamma_before
    
    new_gamma = 0.5
    polygon.gamma = new_gamma
    assert_equal new_gamma, polygon.gamma
  end
  
end
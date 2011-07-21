require "test_helper"

class TestMapnikStroke < Test::Unit::TestCase
  
  def test_presence
    assert Mapnik::Stroke
  end
  
  def test_should_instantiate
    color = Mapnik::Color.new(128, 128, 128, 1)
    assert Mapnik::Stroke.new(color, 1.0)
  end
  
  def test_should_get_and_set_color
    color = Mapnik::Color.new(128, 128, 128, 1)
    stroke = Mapnik::Stroke.new(color, 1.0)
    assert [:red, :green, :blue, :alpha].all?{|x| stroke.color.send(x) == color.send(x)}
    
    new_color = Mapnik::Color.new(255, 255, 255, 1)
    stroke.color = new_color
    assert [:red, :green, :blue, :alpha].all?{|x| stroke.color.send(x) == new_color.send(x)}
  end
  
  def test_should_get_and_set_opacity
    color = Mapnik::Color.new(128, 128, 128, 1)
    stroke = Mapnik::Stroke.new(color, 1.0)
    opacity_before = stroke.opacity
    assert_equal 1, opacity_before
    
    new_opacity = 0.5
    stroke.opacity = new_opacity
    assert_equal new_opacity, stroke.opacity
  end
  
  def test_should_get_and_set_gamma
    color = Mapnik::Color.new(128, 128, 128, 1)
    stroke = Mapnik::Stroke.new(color, 1.0)
    gamma_before = stroke.gamma
    assert_equal 1, gamma_before
    
    new_gamma = 0.5
    stroke.gamma = new_gamma
    assert_equal new_gamma, stroke.gamma
  end
  
  def test_should_get_and_set_width
    color = Mapnik::Color.new(128, 128, 128, 1)
    stroke = Mapnik::Stroke.new(color, 1.0)
    width_before = stroke.width
    assert_equal 1, width_before
    
    new_width = 0.5
    stroke.width = new_width
    assert_equal new_width, stroke.width
  end
  
  def test_should_have_line_caps
    assert Mapnik::LineCap
    assert Mapnik::LineCap::BUTT_CAP
    assert Mapnik::LineCap::SQUARE_CAP
    assert Mapnik::LineCap::ROUND_CAP
  end
  
  def test_should_have_line_joins
    assert Mapnik::LineJoin
    assert Mapnik::LineJoin::MITER_JOIN
    assert Mapnik::LineJoin::MITER_REVERT_JOIN
    assert Mapnik::LineJoin::ROUND_JOIN
    assert Mapnik::LineJoin::BEVEL_JOIN
  end
  
  def test_should_have_dashes
    color = Mapnik::Color.new(128, 128, 128, 1)
    stroke = Mapnik::Stroke.new(color, 1.0)
    assert_equal 0, stroke.dashes.length
    dash_hash = {:gap => 1, :length => 1.2}
    stroke.dashes << dash_hash
    assert_equal dash_hash, stroke.dashes.first
    assert_equal 1, stroke.dashes.length
  end
  
  def test_should_have_dash_offset
    color = Mapnik::Color.new(128, 128, 128, 1)
    stroke = Mapnik::Stroke.new(color, 1.0)
    assert_equal 0, stroke.dash_offset
    stroke.dash_offset = 1.4
    assert_equal 1.4, stroke.dash_offset 
  end
  
end
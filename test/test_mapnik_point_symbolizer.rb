require "test_helper"

class TestMapnikPointSymbolizer < Test::Unit::TestCase
  
  def setup
    @sym = Mapnik::PointSymbolizer.new
  end
  
  def test_presence
    assert Mapnik::PointSymbolizer
    assert Mapnik::PointPlacement::CENTROID
    assert Mapnik::PointPlacement::INTERIOR
  end
  
  def test_should_initialize
    assert @sym
  end
  
  def test_should_get_and_set_filename
    assert_equal "", @sym.filename
    new_filename = "/my/incredible/graphic.png"
    @sym.filename = new_filename
    assert_equal new_filename, @sym.filename
  end
  
  def test_should_get_and_set_allows_overlap
    assert !@sym.allows_overlap?
    @sym.allows_overlap = true
    assert @sym.allows_overlap?
    @sym.allows_overlap = false
    assert !@sym.allows_overlap?
  end
  
  def test_should_get_and_set_opacity
    assert_equal 1, @sym.opacity
    new_opacity = 0.5
    @sym.opacity = new_opacity
    assert_equal new_opacity, @sym.opacity
  end
  
  def test_should_get_and_set_ignore_placement
    assert !@sym.ignores_placement?
    @sym.ignores_placement = true
    assert @sym.ignores_placement?
  end
  
  def test_should_get_and_set_placement
    assert_equal Mapnik::PointPlacement::CENTROID, @sym.placement
    @sym.placement = Mapnik::PointPlacement::INTERIOR
    assert_equal Mapnik::PointPlacement::INTERIOR, @sym.placement
  end
  
end
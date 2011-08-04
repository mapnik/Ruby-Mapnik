require "test_helper"

class TestMarkersSymbolizer < Test::Unit::TestCase
  
  def setup
    @filename = "/my/file.png"
    path_expression = Mapnik::PathExpression.parse("/my/file.png")
    @sym = Mapnik::MarkersSymbolizer.new(path_expression)
  end
  
  def test_should_instantiate
    assert @sym
  end
  
  def test_should_get_and_set_filename
    assert_equal @filename, @sym.filename
    new_filename = "/something/else.png"
    @sym.filename = new_filename
    assert_equal new_filename, @sym.filename
  end
  
  def test_should_get_and_set_allow_overlap
    @sym.allow_overlap = true
    assert @sym.allow_overlap?
    @sym.allow_overlap = false
    assert !@sym.allow_overlap?
  end
  
  def test_should_get_and_set_spacing
    @sym.spacing = 90
    assert_equal 90, @sym.spacing
  end
  
  def test_should_get_and_set_max_error
    @sym.max_error = 90
    assert_equal 90, @sym.max_error
  end
  
  def test_should_get_and_set_opacity
    assert_equal 1, @sym.opacity
    # new_opacity = 0.5
    # @sym.opacity = new_opacity
    # assert_equal new_opacity, @sym.opacity
  end
  
end
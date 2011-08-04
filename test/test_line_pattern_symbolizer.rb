require "test_helper"

class TestLinePatternSymbolizer < Test::Unit::TestCase
  
  def setup
    @filename = "/my/file.png"
    path_expression = Mapnik::PathExpression.parse("/my/file.png")
    @sym = Mapnik::LinePatternSymbolizer.new(path_expression)
  end
  
  def test_presence
    assert Mapnik::LinePatternSymbolizer
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
  
end
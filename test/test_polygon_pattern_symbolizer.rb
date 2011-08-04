require "test_helper"

class TestPolygonPatternSymbolizer < Test::Unit::TestCase
  
  def setup
    @filename = "/my/file.png"
    path_expression = Mapnik::PathExpression.parse("/my/file.png")
    @sym = Mapnik::PolygonPatternSymbolizer.new(path_expression)
  end
  
  def test_presence
    assert Mapnik::PolygonPatternSymbolizer
    assert Mapnik::PatternAlignment::LOCAL
    assert Mapnik::PatternAlignment::GLOBAL
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
  
  def test_should_get_and_set_pattern_alignment
    assert_equal Mapnik::PatternAlignment::LOCAL, @sym.alignment
    @sym.alignment = Mapnik::PatternAlignment::GLOBAL
    assert_equal Mapnik::PatternAlignment::GLOBAL, @sym.alignment
  end
  
end
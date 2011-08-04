require "test_helper"

class TestMapnikExpression < Test::Unit::TestCase
  
  def test_presence
    assert Mapnik::Expression
    assert Mapnik::PathExpression
  end

  def test_should_evaluate
    expression = "([place]='town')"
    assert_equal expression, Mapnik::Expression.parse(expression).to_s
  end

  def test_should_parse_path
    assert Mapnik::PathExpression.parse("/my/path.png")
  end

end
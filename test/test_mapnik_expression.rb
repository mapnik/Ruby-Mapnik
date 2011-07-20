require "test_helper"

class TestMapnikExpression < Test::Unit::TestCase
  
  def test_presence
    assert Mapnik::Expression
  end

  def test_should_evaluate
    expression = "([place]='town')"
    assert_equal expression, Mapnik::Expression.parse(expression).to_s
  end
  
end
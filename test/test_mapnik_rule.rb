require "test_helper"

class TestMapnikRule < Test::Unit::TestCase

  def test_presence
    assert Mapnik::Rule
  end

  def test_should_instantiate
    assert Mapnik::Rule.new
  end

  def test_should_get_and_set_name
    rule = Mapnik::Rule.new
    assert_equal("", rule.name)

    new_name = "New name"
    rule.name = new_name
    assert_equal new_name, rule.name
  end

  def test_should_get_and_set_filter
    rule = Mapnik::Rule.new
    expression_string = "([place]='town')"
    expression = Mapnik::Expression.parse(expression_string)
    rule.filter = expression
    assert_equal expression_string, rule.filter.to_s
  end

  def test_should_append_and_remove_symbols
    rule = Mapnik::Rule.new
    assert_equal 0, rule.symbols.count
    rule.symbols << Mapnik::PolygonSymbolizer.new
    assert_equal 1, rule.symbols.count
    rule.symbols << Mapnik::LineSymbolizer.new
    assert_equal 2, rule.symbols.count

    obj = rule.symbols.delete_at(0)
    assert obj
    assert_equal 1, rule.symbols.count
    assert rule.symbols.pop
    assert_equal 0, rule.symbols.count
  end

end

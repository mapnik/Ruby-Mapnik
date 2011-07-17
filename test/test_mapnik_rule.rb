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
  
  def test_should_get_and_set_title
    rule = Mapnik::Rule.new
    assert_equal("", rule.title)
    
    new_title = "New title"
    rule.title = new_title
    assert_equal new_title, rule.title
  end
  
  def test_should_get_and_set_abstract
    rule = Mapnik::Rule.new
    assert_equal("", rule.abstract)
    
    new_abstract = "New abstract"
    rule.abstract = new_abstract
    assert_equal new_abstract, rule.abstract
  end
  
  def test_should_get_and_set_filter
    rule = Mapnik::Rule.new
    assert rule.filter.kind_of?(Mapnik::Expression)
    
    # assert_equal("", rule.filter)
    # 
    # new_filter = "New filter"
    # rule.filter = new_filter
    # assert_equal new_filter, rule.filter
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
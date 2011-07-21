require "test_helper"

class TestMapnikStyle < Test::Unit::TestCase
  
  def test_presence
    assert Mapnik::Style
  end
  
  def test_should_have_rules
    style = Mapnik::Style.new
    assert style.rules.empty?
    rule = Mapnik::Rule.new
    style.rules << rule
    assert !style.rules.empty?
  end
  
  def test_should_have_filter_types
    assert Mapnik::FilterMode::ALL
    assert Mapnik::FilterMode::FIRST
  end
  
  def test_should_get_and_set_filter
    style = Mapnik::Style.new
    style.filter_mode = Mapnik::FilterMode::ALL
    assert_equal Mapnik::FilterMode::ALL, style.filter_mode
  end
  
end
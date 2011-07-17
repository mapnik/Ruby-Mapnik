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
  
end
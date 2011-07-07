require 'test_helper'
class TestMapnikColor < Test::Unit::TestCase
  
  def test_should_instantiate_and_update_values
    values = {:red => 1, :green => 2, :blue => 3, :alpha => 0}
    color = Mapnik::Color.new(values[:red],  values[:green],
                              values[:blue], values[:alpha])
    
    values.each do |key, value|
      assert_equal(value, color.send("#{key}"))
      color.send("#{key}=", value + 1)
      assert_equal(value + 1, color.send("#{key}"))
    end
    
  end
  
end
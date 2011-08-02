require "test_helper"

class TestMapnikRasterColorizer < Test::Unit::TestCase
  
  def setup
    @colorizer = Mapnik::RasterColorizer.new
  end
  
  def test_presence
    assert Mapnik::RasterColorizer
    ["INHERIT","LINEAR","DISCRETE","EXACT"].each do |colorizer_mode|
        assert Mapnik::ColorizerMode.const_get(colorizer_mode)
    end
    assert Mapnik::ColorizerStop
  end
  
  def test_should_get_and_set_default_color
    r = 34
    g = 45
    b = 56
    a = 255
    color = Mapnik::Color.new(r,g,b,a)
    @colorizer.default_color = color
    assert_equal r, @colorizer.default_color.red
    assert_equal g, @colorizer.default_color.green
    assert_equal b, @colorizer.default_color.blue
    assert_equal a, @colorizer.default_color.alpha
  end
  
  def test_should_get_and_set_default_mode
    ["LINEAR", "DISCRETE","EXACT"].each do |mode_name|
      const = Mapnik::ColorizerMode.const_get(mode_name)
      @colorizer.default_mode = const
      assert_equal const, @colorizer.default_mode
    end
  end
  
  def test_should_get_and_set_epsilon
    @colorizer.epsilon = 5
    assert_equal 5, @colorizer.epsilon
  end
  
  def test_should_instantiate_a_stop
    value = 45.5
    mode = Mapnik::ColorizerMode::EXACT
    color = Mapnik::Color.new(255,255,255,255)
    assert stop = Mapnik::ColorizerStop.new(value,mode,color)
    assert_equal value, stop.value
    assert_equal mode, stop.mode
    # TODO: when there is color equality
    # assert_equal color, stop.color 
  end
  
  def test_should_get_and_add_stops
    assert @colorizer.stops.empty?
    stop = Mapnik::ColorizerStop.new(45.45, Mapnik::ColorizerMode::EXACT, Mapnik::Color.new(255,255,255,255))
    @colorizer.stops << stop
    assert_equal @colorizer.stops.first, stop
  end
  
end
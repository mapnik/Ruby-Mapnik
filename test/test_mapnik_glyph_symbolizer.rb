require "test_helper"

class TestMapnikGlyphSymbolizer < Test::Unit::TestCase
  
  def setup 
    expression = Mapnik::Expression.parse("[g]")
    @sym = Mapnik::GlyphSymbolizer.new("DejaVu Sans Book",expression)
  end
  
  def test_presence
    assert Mapnik::GlyphSymbolizer
    assert Mapnik::AngleMode::AZIMUTH
    assert Mapnik::AngleMode::TRIGONOMETRIC
  end
  
  def test_should_get_and_set_face_name
    assert_equal 'DejaVu Sans Book', @sym.face_name
    new_face_name = 'DejaVu Sans'
    @sym.face_name = new_face_name
    assert_equal new_face_name, @sym.face_name
  end
  
  def test_should_get_and_set_char
    assert @sym.char.instance_of?(Mapnik::Expression)
    @sym.char = Mapnik::Expression.parse("[t]")
  end
  
  def test_should_get_and_set_allow_overlap
    @sym.allow_overlap = true
    assert @sym.allow_overlap?
    @sym.allow_overlap = false
    assert !@sym.allow_overlap?
  end
  
  def test_should_get_and_set_avoid_edges
    @sym.avoid_edges = true
    assert @sym.avoid_edges?
    @sym.avoid_edges = false
    assert !@sym.avoid_edges?
  end
  
  def test_should_get_and_set_displacement
    assert @sym.displacement
    new_vals = [1,2]
    @sym.displacement = new_vals
    assert_equal new_vals, @sym.displacement
  end
  
  # TODO: When there is color equality
  def test_should_get_and_set_halo_fill
    assert @sym.halo_fill.instance_of?(Mapnik::Color)
    @sym.halo_fill = Mapnik::Color.new(255,255,255,255)
  end
  
  def test_should_get_and_set_halo_radius
    assert_equal 0, @sym.halo_radius
    @sym.halo_radius = 1
    assert_equal 1, @sym.halo_radius
  end
  
  def test_should_get_and_set_size
    @sym.size = Mapnik::Expression.parse("[12]")
    assert @sym.size.instance_of?(Mapnik::Expression)
  end
  
  def test_should_get_and_set_angle
    @sym.angle = Mapnik::Expression.parse("[90]")
    assert @sym.angle.instance_of?(Mapnik::Expression)
  end
  
  def test_should_get_and_set_angle_mode
    @sym.angle_mode = Mapnik::AngleMode::AZIMUTH
    assert_equal Mapnik::AngleMode::AZIMUTH, @sym.angle_mode
    @sym.angle_mode = Mapnik::AngleMode::TRIGONOMETRIC
    assert_equal Mapnik::AngleMode::TRIGONOMETRIC, @sym.angle_mode
  end
  
  def test_should_get_and_set_value
    @sym.value = Mapnik::Expression.parse("[town]")
    assert @sym.value.instance_of?(Mapnik::Expression)
  end
  
  # FIXME: Need Expression equality?
  def test_should_get_and_set_color
     @sym.color = Mapnik::Expression.parse("[90, 90, 90]")
     assert @sym.angle.instance_of?(Mapnik::Expression)
  end
  
  # TODO: Colorizer support
  # def test_should_get_and_set_colorizer
  #   colorizer = Mapnik::RasterColorizer.new
  #   @sym.colorizer = colorizer
  # end
  
end
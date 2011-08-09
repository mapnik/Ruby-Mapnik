require "test_helper"

class TestMapnikShieldSymbolizer < Test::Unit::TestCase
  
  def setup
    expression = Mapnik::Expression.parse("[place]")
    face_name = "DejaVu Sans Book"
    fill = Mapnik::Color.new("#fff")
    file = Mapnik::PathExpression.parse("myfile.png")
    @sym = Mapnik::ShieldSymbolizer.new(expression, face_name, 12, fill, file)
  end
    
  def test_should_instantiate
    assert @sym
  end

  def test_should_get_and_set_anchor
    assert @sym.anchor
    new_vals = [1,2]
    @sym.anchor = new_vals
    assert_equal new_vals, @sym.anchor
  end
  
  def test_should_get_and_set_allow_overlap
    @sym.allow_overlap = true
    assert @sym.allow_overlap?
    @sym.allow_overlap = false
    assert !@sym.allow_overlap?
  end

  def test_should_get_and_set_displacement
    assert @sym.displacement
    new_vals = [1,2]
    @sym.displacement = new_vals
    assert_equal new_vals, @sym.displacement
  end
  
  def test_should_get_and_set_shield_displacement
    assert @sym.shield_displacement
    new_vals = [1,2]
    @sym.shield_displacement = new_vals
    assert_equal new_vals, @sym.shield_displacement
  end
  
  def test_should_get_and_set_avoid_edges
    @sym.avoid_edges = true
    assert @sym.avoid_edges?
    @sym.avoid_edges = false
    assert !@sym.avoid_edges?
  end
  
  def test_should_get_and_set_character_spacing
    assert_equal 0, @sym.character_spacing
    @sym.character_spacing = 1
    assert_equal 1, @sym.character_spacing
  end
  
  def test_should_get_and_set_face_name
    assert_equal "DejaVu Sans Book", @sym.face_name
    @sym.face_name = "DejaVu Sans"
    assert_equal "DejaVu Sans", @sym.face_name
  end
  
  def test_should_get_and_set_fill
    assert @sym.fill.instance_of?(Mapnik::Color)
    white = Mapnik::Color.new("#fff")
    @sym.fill = white
    assert_equal white, @sym.fill
  end
  
  # TODO: Need fontset
  # def test_should_get_and_set_fontset
  #   raise @sym.fontset.inspect
  # end
  
  def test_should_get_and_set_force_odd_labels
    @sym.force_odd_labels = true
    assert @sym.force_odd_labels?
    @sym.force_odd_labels = false
    assert !@sym.force_odd_labels?  
  end
  
  def test_should_get_and_set_halo_fill
    assert @sym.halo_fill.instance_of?(Mapnik::Color)
    white = Mapnik::Color.new("#fff")
    @sym.halo_fill = white
    assert_equal white, @sym.halo_fill
  end
  
  def test_should_get_and_set_halo_radius
    assert_equal 0, @sym.halo_radius
    @sym.halo_radius = 1
    assert_equal 1, @sym.halo_radius
  end
  
  def test_should_get_and_set_horizontal_alignment
    @sym.horizontal_alignment = Mapnik::HORIZONTAL_ALIGNMENT::LEFT
    assert_equal Mapnik::HORIZONTAL_ALIGNMENT::LEFT, @sym.horizontal_alignment
    
    @sym.horizontal_alignment = Mapnik::HORIZONTAL_ALIGNMENT::MIDDLE
    assert_equal Mapnik::HORIZONTAL_ALIGNMENT::MIDDLE, @sym.horizontal_alignment
    
    @sym.horizontal_alignment = Mapnik::HORIZONTAL_ALIGNMENT::RIGHT
    assert_equal Mapnik::HORIZONTAL_ALIGNMENT::RIGHT, @sym.horizontal_alignment
  end
  
  def test_should_get_and_set_label_position_tolerance
    assert_equal 0, @sym.label_position_tolerance
    @sym.label_position_tolerance = 1
    assert_equal 1, @sym.label_position_tolerance
  end
  
  def test_should_get_and_set_label_spacing
    assert_equal 0, @sym.label_spacing
    @sym.label_spacing = 1
    assert_equal 1, @sym.label_spacing
  end
  
  def test_should_get_and_set_line_spacing
    assert_equal 0, @sym.line_spacing
    @sym.line_spacing = 1
    assert_equal 1, @sym.line_spacing
  end
  
  # TODO: failure here!
  def test_should_get_and_set_max_char_angle_delta
    @sym.max_char_angle_delta = 0.5
    assert_equal 0.5, @sym.max_char_angle_delta
    @sym.max_char_angle_delta = 0.7
    assert_equal 0.7, @sym.max_char_angle_delta
  end
  
  def test_should_get_and_set_minimum_distance
    assert_equal 0, @sym.minimum_distance
    @sym.minimum_distance = 1
    assert_equal 1, @sym.minimum_distance
  end
  
  def test_should_get_and_set_minimum_padding
    assert_equal 0, @sym.minimum_padding
    @sym.minimum_padding = 1
    assert_equal 1, @sym.minimum_padding
  end
  
  def test_should_get_and_set_name
    assert @sym.name.instance_of?(Mapnik::Expression)
    new_expression_string = "([place]='towns')"
    assert_not_equal new_expression_string, @sym.name.to_s
    new_expression = Mapnik::Expression.parse(new_expression_string)
    @sym.name = new_expression
    assert_equal new_expression_string, @sym.name.to_s
  end
  
  def test_should_get_and_set_opactiy
    assert_equal 1, @sym.opacity
    @sym.opacity = 0
    assert_equal 0, @sym.opacity
  end
  
  def test_should_get_and_set_text_ratio
    assert_equal 0, @sym.ratio
    @sym.ratio = 3
    assert_equal 3, @sym.ratio
  end
  
  def test_should_get_and_set_text_size
    assert_equal 12, @sym.size
    @sym.size = 0
    assert_equal 0, @sym.size
  end
  
  def test_should_get_and_set_wrap_width
    assert_equal 0, @sym.wrap_width
    @sym.wrap_width = 30
    assert_equal 30, @sym.wrap_width
  end
  
  def test_should_get_and_set_wrap_character
    @sym.wrap_character = '|'
    assert_equal '|', @sym.wrap_character
    @sym.wrap_character = '%'
    assert_equal '%', @sym.wrap_character
  end
  
  
  
  def test_should_get_and_set_wrap_before
    assert !@sym.wrap_before
    @sym.wrap_before = true
    assert @sym.wrap_before
  end
  
end
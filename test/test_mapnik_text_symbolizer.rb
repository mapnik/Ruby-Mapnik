require "test_helper"

class TestMapnikTextSymbolizer < Test::Unit::TestCase

  def setup
    expression = Mapnik::Expression.parse("([place]='town')")
    @symbolizer = Mapnik::TextSymbolizer.new(expression, "DejaVu Sans Book", 10, Mapnik::Color.new("#fff"))
  end

  def test_should_instantiate
    assert @symbolizer
  end

  def test_enums_should_exist
    assert Mapnik::LABEL_PLACEMENT::LINE_PLACEMENT
    assert Mapnik::LABEL_PLACEMENT::POINT_PLACEMENT
    assert Mapnik::LABEL_PLACEMENT::VERTEX_PLACEMENT
    assert Mapnik::LABEL_PLACEMENT::INTERIOR_PLACEMENT

    assert Mapnik::VERTICAL_ALIGNMENT::TOP
    assert Mapnik::VERTICAL_ALIGNMENT::MIDDLE
    assert Mapnik::VERTICAL_ALIGNMENT::BOTTOM
    assert Mapnik::VERTICAL_ALIGNMENT::AUTO

    assert Mapnik::HORIZONTAL_ALIGNMENT::LEFT
    assert Mapnik::HORIZONTAL_ALIGNMENT::MIDDLE
    assert Mapnik::HORIZONTAL_ALIGNMENT::RIGHT

    assert Mapnik::JUSTIFY_ALIGNMENT::LEFT
    assert Mapnik::JUSTIFY_ALIGNMENT::MIDDLE
    assert Mapnik::JUSTIFY_ALIGNMENT::RIGHT

    assert Mapnik::TEXT_TRANSFORM::NONE
    assert Mapnik::TEXT_TRANSFORM::UPPERCASE
    assert Mapnik::TEXT_TRANSFORM::LOWERCASE
    assert Mapnik::TEXT_TRANSFORM::CAPITALIZE
  end

  def test_should_get_and_set_allow_overlap
    @symbolizer.allow_overlap = true
    assert @symbolizer.allow_overlap?
    @symbolizer.allow_overlap = false
    assert !@symbolizer.allow_overlap?
  end

  def test_should_get_and_set_displacement
    assert @symbolizer.displacement
    new_vals = [1,2]
    @symbolizer.displacement = new_vals
    assert_equal new_vals, @symbolizer.displacement
  end

  def test_should_get_and_set_avoid_edges
    @symbolizer.avoid_edges = true
    assert @symbolizer.avoid_edges?
    @symbolizer.avoid_edges = false
    assert !@symbolizer.avoid_edges?
  end

  def test_should_get_and_set_character_spacing
    assert_equal 0, @symbolizer.character_spacing
    @symbolizer.character_spacing = 1
    assert_equal 1, @symbolizer.character_spacing
  end

  def test_should_get_and_set_face_name
    assert_equal "DejaVu Sans Book", @symbolizer.face_name
    @symbolizer.face_name = "DejaVu Sans"
    assert_equal "DejaVu Sans", @symbolizer.face_name
  end

  def test_should_get_and_set_fill
    assert @symbolizer.fill.instance_of?(Mapnik::Color)
    white = Mapnik::Color.new("#fff")
    @symbolizer.fill = white
    assert_equal white, @symbolizer.fill
  end

  # TODO: Need fontset
  # def test_should_get_and_set_fontset
  #   raise @symbolizer.fontset.inspect
  # end

  def test_should_get_and_set_force_odd_labels
    @symbolizer.force_odd_labels = true
    assert @symbolizer.force_odd_labels?
    @symbolizer.force_odd_labels = false
    assert !@symbolizer.force_odd_labels?
  end

  def test_should_get_and_set_halo_fill
    assert @symbolizer.halo_fill.instance_of?(Mapnik::Color)
    white = Mapnik::Color.new("#fff")
    @symbolizer.halo_fill = white
    assert_equal white, @symbolizer.halo_fill
  end

  def test_should_get_and_set_halo_radius
    assert_equal 0, @symbolizer.halo_radius
    @symbolizer.halo_radius = 1
    assert_equal 1, @symbolizer.halo_radius
  end

  def test_should_get_and_set_horizontal_alignment
    @symbolizer.horizontal_alignment = Mapnik::HORIZONTAL_ALIGNMENT::LEFT
    assert_equal Mapnik::HORIZONTAL_ALIGNMENT::LEFT, @symbolizer.horizontal_alignment

    @symbolizer.horizontal_alignment = Mapnik::HORIZONTAL_ALIGNMENT::MIDDLE
    assert_equal Mapnik::HORIZONTAL_ALIGNMENT::MIDDLE, @symbolizer.horizontal_alignment

    @symbolizer.horizontal_alignment = Mapnik::HORIZONTAL_ALIGNMENT::RIGHT
    assert_equal Mapnik::HORIZONTAL_ALIGNMENT::RIGHT, @symbolizer.horizontal_alignment
  end

  def test_should_get_and_set_justify_alignment
    check_constant_setting(Mapnik::JUSTIFY_ALIGNMENT, :justify_alignment)
  end

  def test_should_get_and_set_label_placement
    check_constant_setting(Mapnik::LABEL_PLACEMENT, :label_placement)
  end

  def test_should_get_and_set_label_position_tolerance
    assert_equal 0, @symbolizer.label_position_tolerance
    @symbolizer.label_position_tolerance = 1
    assert_equal 1, @symbolizer.label_position_tolerance
  end

  def test_should_get_and_set_label_spacing
    assert_equal 0, @symbolizer.label_spacing
    @symbolizer.label_spacing = 1
    assert_equal 1, @symbolizer.label_spacing
  end

  def test_should_get_and_set_line_spacing
    assert_equal 0, @symbolizer.line_spacing
    @symbolizer.line_spacing = 1
    assert_equal 1, @symbolizer.line_spacing
  end

  def test_should_get_and_set_max_char_angle_delta
    @symbolizer.max_char_angle_delta = 0.5
    assert_equal 0.5, @symbolizer.max_char_angle_delta
    @symbolizer.max_char_angle_delta = 0.7
    assert_equal 0.7, @symbolizer.max_char_angle_delta
  end

  def test_should_get_and_set_minimum_distance
    assert_equal 0, @symbolizer.minimum_distance
    @symbolizer.minimum_distance = 1
    assert_equal 1, @symbolizer.minimum_distance
  end

  def test_should_get_and_set_minimum_padding
    assert_equal 0, @symbolizer.minimum_padding
    @symbolizer.minimum_padding = 1
    assert_equal 1, @symbolizer.minimum_padding
  end

  def test_should_get_and_set_opactiy
    assert_equal 1, @symbolizer.opacity
    @symbolizer.opacity = 0
    assert_equal 0, @symbolizer.opacity
  end

  def test_should_get_and_set_text_transform
    check_constant_setting(Mapnik::TEXT_TRANSFORM, :text_transform)
  end

  def test_should_get_and_set_text_ratio
    assert_equal 0, @symbolizer.ratio
    @symbolizer.ratio = 3
    assert_equal 3, @symbolizer.ratio
  end

  def test_should_get_and_set_text_size
    assert_equal 10, @symbolizer.size
    @symbolizer.size = 0
    assert_equal 0, @symbolizer.size
  end

  def test_should_get_and_set_vertical_alignment
    check_constant_setting(Mapnik::VERTICAL_ALIGNMENT, :vertical_alignment)
  end

  def test_should_get_and_set_wrap_width
    assert_equal 0, @symbolizer.wrap_width
    @symbolizer.wrap_width = 30
    assert_equal 30, @symbolizer.wrap_width
  end

  def test_should_get_and_set_wrap_character
    @symbolizer.wrap_character = '|'
    assert_equal '|', @symbolizer.wrap_character
    @symbolizer.wrap_character = '%'
    assert_equal '%', @symbolizer.wrap_character
  end

  def test_should_get_and_set_wrap_before
    assert !@symbolizer.wrap_before
    @symbolizer.wrap_before = true
    assert @symbolizer.wrap_before
  end

private

  def check_constant_setting(enum, property)
    enum.constants.each do |const_name|
      const = enum.const_get(const_name)
      @symbolizer.send(property.to_s + '=', const)
      assert_equal const, @symbolizer.send(property)
    end
  end

end

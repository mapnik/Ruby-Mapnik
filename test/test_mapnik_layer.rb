require "test_helper"

class TestMapnikLayer < Test::Unit::TestCase

  def test_presence
    assert Mapnik::Layer
  end

  def test_should_initialize
    assert layer = Mapnik::Layer.new("My Layer", "+proj=latlong +datum=WGS84")
  end

  def test_should_have_datasource
    layer = build_layer
    assert layer.datasource.envelope
  end

  def test_should_have_same_enevelope_as_datasource
    layer = build_layer
    assert layer.envelope.kind_of?(Mapnik::Envelope)
    assert_equal layer.envelope, layer.datasource.envelope
  end

  def test_should_get_and_set_name
    layer = build_layer
    name_before = layer.name
    new_name = name_before + "BUT DIFFERENT"
    layer.name = new_name
    assert_equal new_name, layer.name
  end

  def test_should_get_and_set_srs
    layer = build_layer
    srs_before = layer.srs
    new_srs = '+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs'
    layer.srs = new_srs
    assert_equal new_srs, layer.srs
  end

  def test_should_get_and_set_min_zoom
    layer = build_layer
    min_zoom_before = layer.min_zoom
    new_min_zoom = min_zoom_before + 1.2
    layer.min_zoom = new_min_zoom
    assert_equal new_min_zoom, layer.min_zoom
  end

  def test_should_get_and_set_max_zoom
    layer = build_layer
    max_zoom_before = layer.max_zoom
    new_max_zoom = max_zoom_before + 1.2
    layer.max_zoom = new_max_zoom
    assert_equal new_max_zoom, layer.max_zoom
  end

  def test_should_know_if_it_is_visible_at_a_given_scale
    layer = build_layer
    layer.min_zoom = 0.0
    assert layer.visible_at_scale?(1.0/1000000)
    layer.min_zoom = 2.0
    assert !layer.visible_at_scale?(1.0/1000000)
  end

  def test_should_know_if_it_is_active
    layer = build_layer
    assert layer.active?
    layer.active = false
    assert !layer.active?
    layer.active = true
    assert layer.active?
  end

  def test_should_know_if_it_is_queryable
    layer = build_layer
    assert !layer.queryable?
    layer.queryable = true
    assert layer.queryable?
    layer.queryable = false
    assert !layer.queryable?
  end

  def test_should_know_if_it_should_cache_features
    layer = build_layer
    assert !layer.cache_features?
    layer.cache_features = true
    assert layer.cache_features?
    layer.cache_features = false
    assert !layer.cache_features?
  end

  def test_should_know_if_it_should_clear_its_label_cache
    layer = build_layer
    assert !layer.clear_label_cache?
    layer.clear_label_cache = true
    assert layer.clear_label_cache?
    layer.clear_label_cache = false
    assert !layer.clear_label_cache?
  end

  def test_should_have_styles
    layer = build_layer
    assert layer.styles.instance_of?(Mapnik::LayerStyleContainer)
    assert layer.styles.empty?
    style_name = 'My Style'
    layer.styles << style_name
    assert !layer.styles.empty?
    assert_equal style_name, layer.styles.first
  end

private

  def build_layer
    layer = Mapnik::Layer.new("My Layer", "+proj=latlong +datum=WGS84")
    layer.datasource = Mapnik::Datasource.create(
      :type => 'shape',
      :file => SHAPEFILE
    )
    layer
  end

end

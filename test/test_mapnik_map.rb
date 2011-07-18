require "test_helper"

class TestMapnikMap < Test::Unit::TestCase
  
  def test_presence
    assert Mapnik::Map
  end
  
  def test_should_initialize
    assert build_map
  end
  
  def test_should_have_envelope
    map = build_map
    assert map.envelope.kind_of?(Mapnik::Envelope)
  end
  
  def test_should_have_styles
    map = build_map
    assert map.styles.instance_of?(Mapnik::MapStyleContainer)
    assert map.styles.empty?
    
    key = "My Style"
    map.styles[key] = Mapnik::Style.new
    assert map.styles.any?
    assert map.styles[key].is_a?(Mapnik::Style)
    
    map.styles.delete(key)
    assert map.styles.empty?
  end
  
  def test_should_have_buffered_envelope
    map = build_map
    envelope_before = map.envelope
    assert_equal 0, map.buffer_size
    buffered_envelope_before = map.buffered_envelope
    assert_equal envelope_before, buffered_envelope_before
    
    map.buffer_size = 1
    
    assert_equal 1, map.buffer_size
    assert_equal envelope_before, map.envelope
    assert_not_equal buffered_envelope_before, map.buffered_envelope    
  end
  
  def test_should_pan
    map = build_map
    center_before = map.envelope.center
    map.pan(-1,-1)
    assert_not_equal center_before, map.envelope.center
  end
  
  def test_should_get_and_set_background
    map = build_map
    assert map.background.nil?
    
    color = Mapnik::Color.new(255, 255, 255, 1)
    map.background = color
    assert [:red, :green, :blue, :alpha].all?{|x| color.send(x) == map.background.send(x)}
  end
  
  def test_should_zoom
    map = build_map
    scale_before = map.scale
    map.zoom(2)    
  end
  
  def test_should_zoom_all
    map = build_map
    
    # Override since there are no layers
    map.maximum_extent = Mapnik::Envelope.new(-180,-90,180,90)
    map.zoom_all
  end
  
  def test_should_resize
    map = build_map
    assert_equal 600, map.width
    assert_equal 400, map.height
    
    new_width = 601
    new_height = 401
    map.resize(new_width, new_height)
    assert_equal(new_width, map.width)
    assert_equal(new_height, map.height)
  end
  
  def test_should_have_scale
    map = build_map
    assert map.scale.kind_of?(Float)
  end
  
  def test_should_zoom_to_box
    map = build_map
    box = Mapnik::Envelope.new(1,1,1,1)
    map.zoom_to_box(box)
  end
  
  def test_mapnik_base_path
    map = build_map
    assert map.base_path.kind_of?(String)
    assert_equal "", map.base_path
    new_base_path = "/some/path"
    map.base_path = new_base_path
    assert_equal new_base_path, map.base_path
  end
  
  def test_should_get_and_set_buffer_size
    map = build_map
    assert_equal 0, map.buffer_size
    new_buffer_size = 1
    map.buffer_size = new_buffer_size
    assert_equal new_buffer_size, map.buffer_size
  end
  
  def test_should_get_and_set_height
    map = build_map
    assert_equal 400, map.height
    new_height = 401
    map.height = new_height
    assert_equal new_height, map.height
  end
  
  def test_should_get_and_set_maximum_extent
    map = build_map
    assert_nil map.maximum_extent
    new_max_extent = Mapnik::Envelope.new(-180,-90,180,90)
    map.maximum_extent = new_max_extent
    assert_equal new_max_extent, map.maximum_extent
  end
  
  def test_should_get_and_set_srs
    map = build_map
    assert_equal "+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs", map.srs
    new_srs = "+proj=merc +a=6378137 +b=6378137 +lat_ts=0.0 +lon_0=0.0 +x_0=0.0 +y_0=0 +k=1.0 +units=m +nadgrids=@null +no_defs +over"
    map.srs = new_srs
    assert_equal new_srs, map.srs
  end
  
  def test_should_get_and_set_width
    map = build_map
    assert_equal 600, map.width
    new_width = 601
    map.width = new_width
    assert_equal new_width, map.width
  end
  
  def test_should_have_layers
    map = build_map
    assert map.layers.empty?
    layer = Mapnik::Layer.new("My Layer", "+proj=latlong +datum=WGS84")
    map.layers << layer
    assert map.layers.any?
    
    map.layers.clear
    assert map.layers.empty?
  end
  
  def test_big
    map = Mapnik::Map.new(600, 300, "+proj=latlong +datum=WGS84")
    map.background = Mapnik::Color.new(0, 0, 255, 255)
    style = Mapnik::Style.new
    rule = Mapnik::Rule.new
    poly = Mapnik::PolygonSymbolizer.new
    poly.fill = Mapnik::Color.new(255, 0, 0, 255)
    rule.symbols << poly
    style.rules << rule
    map.styles["My Style"]=style
    layer = Mapnik::Layer.new('world',"+proj=latlong +datum=WGS84")
    layer.datasource = Mapnik::Datasource.create(:type => "shape", :file => SHAPEFILE)
    layer.styles << "My Style"
    map.layers << layer
    map.zoom_to_box(layer.envelope)
    # raise map.__save_to_string__.inspect
    map.__render_to_file__("world.png", "png")
  end
  
private

  def build_map
    Mapnik::Map.new(600, 400, '+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs')
  end
  
end
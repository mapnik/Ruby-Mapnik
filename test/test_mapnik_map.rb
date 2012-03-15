require "test_helper"
require "chunky_png"

class TestMapnikMap < Test::Unit::TestCase
      
  def setup
    @map = Mapnik::Map.new
  end
  
  def test_should_initialize
    assert @map
  end
  
  def test_should_have_envelope
    assert @map.envelope.kind_of?(Mapnik::Envelope)
  end
  
  def test_should_have_styles
    assert @map.styles.instance_of?(Mapnik::MapStyleContainer)
    assert @map.styles.empty?
    
    key = "My Style"
    @map.styles[key] = Mapnik::Style.new
    assert @map.styles.any?
    assert @map.styles[key].is_a?(Mapnik::Style)
    
    @map.styles.delete(key)
    assert @map.styles.empty?
  end
  
  def test_should_have_buffered_envelope
    envelope_before = @map.envelope
    assert_equal 0, @map.buffer_size
    buffered_envelope_before = @map.buffered_envelope
    assert_equal envelope_before, buffered_envelope_before
    
    @map.buffer_size = 1
    
    assert_equal 1, @map.buffer_size
    assert_equal envelope_before, @map.envelope
    assert_not_equal buffered_envelope_before, @map.buffered_envelope    
  end
  
  def test_should_pan
    center_before = @map.envelope.center
    @map.pan(-1,-1)
    assert_not_equal center_before, @map.envelope.center
  end
  
  def test_should_get_and_set_background
    assert @map.background.nil?
    color = Mapnik::Color.new("#fff")
    @map.background = color
    assert_equal color, @map.background
  end
  
  def test_should_zoom
    scale_before = @map.scale
    @map.zoom(2)    
  end
  
  def test_should_zoom_all    
    # Override since there are no layers
    @map.maximum_extent = Mapnik::Envelope.new(-180,-90,180,90)
    @map.zoom_all
  end
  
  def test_should_resize    
    width_before = @map.width
    height_before = @map.height
    
    new_width = width_before + 1
    new_height = height_before + 1
    @map.resize(new_width, new_height)
    assert_equal(new_width, @map.width)
    assert_equal(new_height, @map.height)
  end
  
  def test_should_have_scale
    assert @map.scale.kind_of?(Float)
  end
  
  def test_should_zoom_to_box
    box = Mapnik::Envelope.new(1,1,1,1)
    @map.zoom_to_box(box)
  end
  
  def test_mapnik_base_path
    assert @map.base_path.kind_of?(String)
    assert_equal "", @map.base_path
    new_base_path = "/some/path"
    @map.base_path = new_base_path
    assert_equal new_base_path, @map.base_path
  end
  
  def test_should_get_and_set_buffer_size
    assert_equal 0, @map.buffer_size
    new_buffer_size = 1
    @map.buffer_size = new_buffer_size
    assert_equal new_buffer_size, @map.buffer_size
  end
  
  def test_should_get_and_set_height
    assert_equal 400, @map.height
    new_height = 401
    @map.height = new_height
    assert_equal new_height, @map.height
  end
  
  def test_should_get_and_set_maximum_extent
    assert_nil @map.maximum_extent
    new_max_extent = Mapnik::Envelope.new(-180,-90,180,90)
    @map.maximum_extent = new_max_extent
    assert_equal new_max_extent, @map.maximum_extent
  end
  
  def test_should_get_and_set_srs
    assert_equal "+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs", @map.srs
    new_srs = "+proj=merc +a=6378137 +b=6378137 +lat_ts=0.0 +lon_0=0.0 +x_0=0.0 +y_0=0 +k=1.0 +units=m +nadgrids=@null +no_defs +over"
    @map.srs = new_srs
    assert_equal new_srs, @map.srs
  end
  
  def test_should_get_and_set_width
    width_before = @map.width
    new_width = width_before + 1
    @map.width = new_width
    assert_equal new_width, @map.width
  end
  
  def test_should_have_layers
    assert @map.layers.empty?
    layer = Mapnik::Layer.new("My Layer", "+proj=latlong +datum=WGS84")
    @map.layers << layer
    assert @map.layers.any?
    
    @map.layers.clear
    assert @map.layers.empty?
  end
  
  def test_should_output_to_xml
    map = build_complete_map
    assert map.to_xml.instance_of?(String)
    assert map.to_xml.include?("<?xml")
  end

  def test_should_render_to_file
    map = build_complete_map
    filename = File.join(File.expand_path(File.dirname(__FILE__)), "../tmp/world.png")
    assert_equal 0, File.size(filename) if File.exists?(filename)
    assert map.render_to_file(filename)
    assert File.exists?(filename)
    File.delete(filename)
  end

  def test_should_render_to_file_with_explicit_format
    map = build_complete_map
    filename = File.join(File.expand_path(File.dirname(__FILE__)), "../tmp/world-256.png")
    assert_equal 0, File.size(filename) if File.exists?(filename)
    assert map.render_to_file(filename, "png256")
    assert File.exists?(filename)
    assert_not_nil ChunkyPNG::Datastream.from_file(filename).palette_chunk
    File.delete(filename)
  end

  def test_should_load_from_xml_string
    map_1 = build_complete_map
    map_2 = Mapnik::Map.from_xml(map_1.to_xml)
    assert_equal map_1.layers.count, map_2.layers.count
    assert_equal map_1.srs, map_2.srs
  end
  
  def test_should_load_from_file_path_string
    file_path = File.join(File.expand_path(File.dirname(__FILE__)), "data", "test_map.xml")
    map = Mapnik::Map.from_file(file_path)
    assert map.layers.any?
    assert map.styles['My Style']
  end
  
  def test_should_load_from_file
    file = File.open(File.join(File.expand_path(File.dirname(__FILE__)), "data", "test_map.xml"))
    map = Mapnik::Map.from_file(file)
    assert map.layers.any?
    assert map.styles['My Style']
  end
  

private

  def build_complete_map
    map = Mapnik::Map.new
    map.width = 600
    map.height = 300
    map.srs = "+proj=latlong +datum=WGS84"
    map.background = Mapnik::Color.new("#0000FF")
    style = Mapnik::Style.new
    rule = Mapnik::Rule.new
    poly = Mapnik::PolygonSymbolizer.new
    poly.fill = Mapnik::Color.new("#FF0088")
    rule.symbols << poly
    style.rules << rule
    map.styles["My Style"]=style
    layer = Mapnik::Layer.new('world',"+proj=latlong +datum=WGS84")
    layer.datasource = Mapnik::Datasource.create(:type => "shape", :file => SHAPEFILE)
    layer.styles << "My Style"
    map.layers << layer
    map.zoom_to_box(layer.envelope)
    map
  end
  
end
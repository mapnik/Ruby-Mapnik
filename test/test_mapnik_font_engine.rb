require "test_helper"

class TestMapnikFontEngine < Test::Unit::TestCase
  
  def test_presence
    assert Mapnik::FontEngine
  end
  
  def test_face_name
    assert Mapnik::FontEngine.face_names.instance_of?(Array)
  end
  
end
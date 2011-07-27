require "test_helper"

class TestMapnikFontEngine < Test::Unit::TestCase
  
  def test_presence
    assert Mapnik::FontEngine
    raise Mapnik::FontEngine.face_names.inspect
  end
  
end
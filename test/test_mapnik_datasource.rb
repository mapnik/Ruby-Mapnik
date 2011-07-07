require 'test_helper'
class TestMapnikDatasource < Test::Unit::TestCase
  
  def test_presence
    assert Mapnik::Datasource
  end
  
  def test_should_build
    # For Now...
    assert Mapnik::Datasource.respond_to?(:create)
  end
  
end
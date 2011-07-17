require "test_helper"

class TestMapnikFeature < Test::Unit::TestCase
  
  def test_presence
    assert Mapnik::Feature
  end
  
  def test_should_instantiate
    feature_id = 12
    assert feature = Mapnik::Feature.new(feature_id)
    assert_equal feature_id, feature.id
    assert_equal "feature (  id:#{feature_id})", feature.to_s.gsub("\n", '')
  end
  
  def test_should_return_number_of_geometries
    assert feature = Mapnik::Feature.new(1)
    assert_equal 0, feature.number_of_geometries
  end
  
  def test_should_return_its_envelope
    assert feature = Mapnik::Feature.new(1)
    assert feature.envelope.kind_of?(Mapnik::Envelope)
  end
  
  def test_should_add_a_geometry
    feature = Mapnik::Feature.new(1)
    assert_equal(0, feature.number_of_geometries)
    feature.add_geometry("POINT(30 10)")
    assert_equal(1, feature.number_of_geometries)
  end
  
end
require "test_helper"

class TestMapnikProjection < Test::Unit::TestCase

  PARAMS = '+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs'

  def test_presence
    assert Mapnik::Projection
  end

  def test_should_instantiate_and_return_params
    assert proj = Mapnik::Projection.new(PARAMS)
    assert_equal PARAMS, proj.params
  end

  def test_should_return_expanded_params
    assert proj = Mapnik::Projection.new(PARAMS)
    assert_not_equal PARAMS, proj.expanded_params
    assert proj.expanded_params.include?(PARAMS)
  end

  def test_should_respond_to_geographic
    assert Mapnik::Projection.new(PARAMS).geographic?
  end

  def test_should_inverse_points
    proj = Mapnik::Projection.new(PARAMS)
    assert proj.inverse(Mapnik::Coord2d.new(2,3))
  end

  def test_should_inverse_envelopes
    proj = Mapnik::Projection.new(PARAMS)
    assert proj.inverse(Mapnik::Envelope.new(2,3,4,5))
  end

  def test_should_forward_points
    proj = Mapnik::Projection.new(PARAMS)
    assert proj.forward(Mapnik::Coord2d.new(2,3))
  end

  def test_should_forward_envelopes
    proj = Mapnik::Projection.new(PARAMS)
    assert proj.forward(Mapnik::Envelope.new(2,3,4,5))
  end

end

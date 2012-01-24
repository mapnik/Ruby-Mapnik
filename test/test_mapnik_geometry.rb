require "test_helper"

class TestMapnikGeometry < Test::Unit::TestCase
  
  STATEMENT = "Geometry tests no longer valid. See https://github.com/mapnik/Ruby-Mapnik/issues/11"

  def test_presence
    assert Mapnik::GeometryType
    assert Mapnik::Geometry2d
    assert Mapnik::GeometryType::Point
    assert Mapnik::GeometryType::LineString
    assert Mapnik::GeometryType::Polygon
  end
  
  def test_should_make_point_from_wkt
    omit(STATEMENT)
    # point = Mapnik::Geometry2d.from_wkt("POINT(30 10)")
    # assert_equal Mapnik::GeometryType::Point, point.type
    # assert_equal 30, point.envelope.min_x
    # assert_equal 30, point.envelope.max_x
    # assert_equal 10, point.envelope.max_y
    # assert_equal 10, point.envelope.min_y
    # assert_equal 0, point.area
  end
  
  def test_should_make_linestring_from_wkt
    omit(STATEMENT)
    # linestring = Mapnik::Geometry2d.from_wkt("LINESTRING (29 11, 12 30, 41 40)")
    # assert_equal Mapnik::GeometryType::LineString, linestring.type
    # assert_equal 12, linestring.envelope.min_x
    # assert_equal 41, linestring.envelope.max_x
    # assert_equal 40, linestring.envelope.max_y
    # assert_equal 11, linestring.envelope.min_y
    # assert_equal 0, linestring.area -> Not sure what the correct value is here  
  end
  
  def test_should_make_polygon_from_wkt
    omit(STATEMENT)
    # polygon = Mapnik::Geometry2d.from_wkt("POLYGON ((30 10, 10 20, 20 40, 40 40, 30 10))")
    # assert_equal Mapnik::GeometryType::Polygon, polygon.type
    # assert_equal 10, polygon.envelope.min_x
    # assert_equal 40, polygon.envelope.max_x
    # assert_equal 40, polygon.envelope.max_y
    # assert_equal 10, polygon.envelope.min_y
    # assert_equal 0, polygon.area
  end
  
  def test_should_make_multipoint_from_wkt
    omit(STATEMENT)
    # multipoint = Mapnik::Geometry2d.from_wkt("MULTIPOINT (10 40, 40 30, 20 20, 30 10)")
    # assert_equal Mapnik::GeometryType::MultiPoint, multipoint.type
    # assert_equal 10, multipoint.envelope.min_x
    # assert_equal 40, multipoint.envelope.max_x
    # assert_equal 40, multipoint.envelope.max_y
    # assert_equal 10, multipoint.envelope.min_y
  end
  
  def test_should_make_multilinestring_from_wkt
    omit(STATEMENT)
    # multi_line = Mapnik::Geometry2d.from_wkt("MULTILINESTRING ((10 10, 20 20, 10 40), (40 40, 30 30, 40 20, 30 10))")
    # assert_equal Mapnik::GeometryType::MultiLineString, multi_line.type
    # assert_equal 10, multi_line.envelope.min_x
    # assert_equal 40, multi_line.envelope.max_x
    # assert_equal 40, multi_line.envelope.max_y
    # assert_equal 10, multi_line.envelope.min_y
  end
  
  def test_should_make_multipolygon_from_wkt
    omit(STATEMENT)
    # multi_polygon = Mapnik::Geometry2d.from_wkt("MULTIPOLYGON (((30 20, 10 40, 45 40, 30 20)), ((15 5, 40 10, 10 20, 5 10, 15 5)))")
    # assert_equal Mapnik::GeometryType::MultiPolygon, multi_polygon.type
    # assert_equal 5, multi_polygon.envelope.min_x
    # assert_equal 45, multi_polygon.envelope.max_x
    # assert_equal 40, multi_polygon.envelope.max_y
    # assert_equal 5, multi_polygon.envelope.min_y
  end

private
  
  def omit(str)
    puts str
  end

end
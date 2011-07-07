require 'test_helper'
class TestMapnikCoord < Test::Unit::TestCase
  
  def test_should_hang_onto_and_update_values
    coord2d = Mapnik::Coord2d.new(1, 2)
    assert_equal(1, coord2d.x)
    assert_equal(2, coord2d.y)
    
    coord2d.x = 2
    coord2d.y = 4
    assert_equal(2, coord2d.x)
    assert_equal(4, coord2d.y)
  end
  
  def test_should_be_equal_to_another_coord_if_the_x_and_ys_match
    coord2d = Mapnik::Coord2d.new(1,2)
    other_coord = Mapnik::Coord2d.new(coord2d.x, coord2d.y)
    assert other_coord.object_id != coord2d.object_id
    assert_equal(other_coord.x, coord2d.x)
    assert_equal(other_coord.y, coord2d.y)
    assert_equal(other_coord, coord2d)
    
    other_coord.x += 3
    assert_not_equal(other_coord, coord2d)
    other_coord.x = coord2d.x
    assert_equal(other_coord, coord2d)
    
    other_coord.y += 3
    assert_not_equal(other_coord, coord2d)
    other_coord.y = coord2d.y
    assert_equal(other_coord, coord2d)
    
    other_coord.x += 3
    other_coord.y += 3
    assert_not_equal(other_coord, coord2d)
  end
  
  # These could be refactored, I suppose...
  def test_should_return_a_new_coord_when_multiplied_by_a_number
    start_x = 1
    start_y = 2
    factor  = 3
    coord2d = Mapnik::Coord2d.new(start_x, start_y)
    multiplied_coord = coord2d * factor
    assert_not_equal(coord2d.object_id, multiplied_coord.object_id)
    assert_equal(coord2d.x * factor, multiplied_coord.x)
    assert_equal(coord2d.y * factor, multiplied_coord.y)
    assert_equal(coord2d.x, start_x)
    assert_equal(coord2d.y, start_y)
  end
  
  def test_should_return_a_new_coord_when_added_to_by_a_number
    start_x = 1
    start_y = 2
    factor  = 3
    coord2d = Mapnik::Coord2d.new(start_x, start_y)
    added_coord = coord2d + factor
    assert_not_equal(coord2d.object_id, added_coord.object_id)
    assert_equal(coord2d.x + factor, added_coord.x)
    assert_equal(coord2d.y + factor, added_coord.y)
    assert_equal(coord2d.x, start_x)
    assert_equal(coord2d.y, start_y)
  end
  
  def test_should_return_a_new_coord_when_subtracted_from_by_a_number
    start_x = 1
    start_y = 2
    factor  = 3
    coord2d = Mapnik::Coord2d.new(start_x, start_y)
    subtracted_coord = coord2d - factor
    assert_not_equal(coord2d.object_id, subtracted_coord.object_id)
    assert_equal(coord2d.x - factor, subtracted_coord.x)
    assert_equal(coord2d.y - factor, subtracted_coord.y)
    assert_equal(coord2d.x, start_x)
    assert_equal(coord2d.y, start_y)
  end
  
  def test_should_return_a_new_coord_when_divided_by_a_number
    start_x = 1
    start_y = 2
    factor  = 3
    coord2d = Mapnik::Coord2d.new(start_x, start_y)
    divided_coord = coord2d / factor
    assert_not_equal(coord2d.object_id, divided_coord.object_id)
    assert_equal(coord2d.x / factor, divided_coord.x)
    assert_equal(coord2d.y / factor, divided_coord.y)
    assert_equal(coord2d.x, start_x)
    assert_equal(coord2d.y, start_y)
  end
  
end
=begin
 ******************************************************************************
 *
 * Copyright (C) 2011 Elliot Laster
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 ******************************************************************************
=end
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
    coord_check_with_operator(:*)
  end

  def test_should_return_a_new_coord_when_added_to_by_a_number
    coord_check_with_operator(:+)
  end

  def test_should_return_a_new_coord_when_subtracted_from_by_a_number
    coord_check_with_operator(:-)
  end

  def test_should_return_a_new_coord_when_divided_by_a_number
    coord_check_with_operator(:/)
  end

private

  def coord_check_with_operator(operator)
    start_x = 1
    start_y = 2
    factor  = 3
    coord2d = Mapnik::Coord2d.new(start_x, start_y)
    updated_coord = coord2d.send(operator, factor)

    assert_not_equal(coord2d.object_id, updated_coord.object_id)
    assert_equal(coord2d.x.send(operator, factor), updated_coord.x)
    assert_equal(coord2d.y.send(operator, factor), updated_coord.y)
    assert_equal(coord2d.x, start_x)
    assert_equal(coord2d.y, start_y)
  end

end

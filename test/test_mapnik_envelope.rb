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
require "test_helper"

class TestMapnikEnvelope < Test::Unit::TestCase
  
  def test_presence
    assert Mapnik::Envelope
  end
  
  def test_should_instantiate
    assert Mapnik::Envelope.new(1,1,5,5)
  end
  
  def test_should_set_attributes_correctly
    min_x = 1
    min_y = 2
    max_x = 3
    max_y = 4
    envelope = Mapnik::Envelope.new(min_x, min_y, max_x, max_y)
    assert_equal(min_x, envelope.min_x)
    assert_equal(min_y, envelope.min_y)
    assert_equal(max_x, envelope.max_x)
    assert_equal(max_y, envelope.max_y)
  end
  
  def test_equality
    envelope1 = Mapnik::Envelope.new(0, 0, 10, 10)
    envelope2 = Mapnik::Envelope.new(0, 0, 10, 10)
    assert_equal(envelope1, envelope2)
    envelope1.re_center_to_xy!(7, 7)
    assert_not_equal(envelope1, envelope2)
    envelope1.re_center_to_coord!(envelope2.center)
    assert_equal(envelope1, envelope2)
  end
  
  def test_should_return_center
    envelope = Mapnik::Envelope.new(0, 0, 100, 50)
    assert center = envelope.center
    assert_equal 50, center.x
    assert_equal 25, center.y
  end
  
  def test_should_return_height
    envelope = Mapnik::Envelope.new(0,0,10,10)
    assert_equal(10, envelope.height)
  end
  
  def test_should_update_height
    envelope = Mapnik::Envelope.new(0,0,10,10)
    assert_equal(10, envelope.height)
    envelope.height = 20
    assert_equal 20, envelope.height
    assert_equal 15, envelope.max_y
    assert_equal -5, envelope.min_y
  end
  
  def test_should_return_width
    envelope = Mapnik::Envelope.new(0,0,10,10)
    assert_equal(10, envelope.width)
  end
  
  def test_should_update_width
    envelope = Mapnik::Envelope.new(0,0,10,10)
    assert_equal(10, envelope.width)
    envelope.width = 20
    assert_equal 20, envelope.width
    assert_equal 15, envelope.max_x
    assert_equal -5, envelope.min_x
  end
  
  def test_should_recenter_to_xy
    envelope = Mapnik::Envelope.new(0,0,10,10)
    assert_equal 5, envelope.center.x
    assert_equal 5, envelope.center.y
    height_before = envelope.height
    width_before = envelope.width
    
    envelope.re_center_to_xy!(7,6)
    
    assert_equal 7, envelope.center.x
    assert_equal 6, envelope.center.y
    assert_equal height_before, envelope.height 
    assert_equal width_before, envelope.width 
  end
  
  def test_should_recenter_to_coord
    envelope = Mapnik::Envelope.new(0,0,10,10)
    assert_equal 5, envelope.center.x
    assert_equal 5, envelope.center.y
    height_before = envelope.height
    width_before = envelope.width
    
    envelope.re_center_to_coord!(Mapnik::Coord2d.new(7,6))
    
    assert_equal 7, envelope.center.x
    assert_equal 6, envelope.center.y
    assert_equal height_before, envelope.height 
    assert_equal width_before, envelope.width 
  end
  
  def test_should_know_if_it_contains_an_xy
    envelope = Mapnik::Envelope.new(0,0,10,10)
    assert !envelope.contains_xy?(11, 11)
    assert envelope.contains_xy?(5, 5)
  end
  
  def test_should_know_if_it_contains_a_coord
    envelope = Mapnik::Envelope.new(0,0,10,10)
    assert !envelope.contains_coord?(Mapnik::Coord2d.new(11, 11))
    assert envelope.contains_coord?(Mapnik::Coord2d.new(5, 5))
  end
  
  def test_should_know_if_it_contains_another_envelope
    envelope = Mapnik::Envelope.new(0,0,10,10)
    assert !envelope.contains_envelope?(Mapnik::Envelope.new(20,20,30,30))
    assert !envelope.contains_envelope?(Mapnik::Envelope.new(9,9,12,12))
    assert envelope.contains_envelope?(Mapnik::Envelope.new(5,5,6,6))
  end
  
  def test_should_know_if_it_intersects_an_xy
    envelope = Mapnik::Envelope.new(0,0,10,10)
    assert !envelope.intersects_xy?(11, 11)
    assert envelope.intersects_xy?(5, 5)
  end
  
  def test_should_know_if_it_intersects_a_coord
    envelope = Mapnik::Envelope.new(0,0,10,10)
    assert !envelope.intersects_coord?(Mapnik::Coord2d.new(11, 11))
    assert envelope.intersects_coord?(Mapnik::Coord2d.new(5, 5))
  end
  
  def test_should_know_if_it_intersects_another_envelope
    envelope = Mapnik::Envelope.new(0,0,10,10)
    assert !envelope.intersects_envelope?(Mapnik::Envelope.new(20,20,30,30))
    assert envelope.intersects_envelope?(Mapnik::Envelope.new(9,9,12,12))
    assert envelope.intersects_envelope?(Mapnik::Envelope.new(5,5,6,6))
  end
  
  def test_should_expand_to_include_an_xy
    envelope = Mapnik::Envelope.new(0,0,10,10)
    assert !envelope.contains_xy?(11, 11)
    height_before = envelope.height
    width_before = envelope.width
    
    envelope.expand_to_include_xy!(11, 11)
    
    assert envelope.contains_xy?(11, 11)
    assert_equal height_before + 1, envelope.height 
    assert_equal width_before + 1, envelope.width
  end
  
  def test_should_expand_to_include_a_coord
    envelope = Mapnik::Envelope.new(0,0,10,10)
    coord = Mapnik::Coord2d.new(11, 11)
    assert !envelope.contains_coord?(coord)
    height_before = envelope.height
    width_before = envelope.width
    
    envelope.expand_to_include_coord!(coord)
    
    assert envelope.contains_coord?(coord)
    assert_equal height_before + 1, envelope.height 
    assert_equal width_before + 1, envelope.width
  end
  
  def test_should_expand_to_include_an_envelope
    envelope = Mapnik::Envelope.new(0,0,10,10)
    other_envelope = Mapnik::Envelope.new(11, 11, 12, 12)
    assert !envelope.contains_envelope?(other_envelope)
    height_before = envelope.height
    width_before = envelope.width
    
    envelope.expand_to_include_envelope!(other_envelope)
    
    assert envelope.contains_envelope?(other_envelope)
    assert_equal height_before + 2, envelope.height 
    assert_equal width_before + 2, envelope.width
  end
  
  def test_should_provide_an_intersection
    envelope = Mapnik::Envelope.new(0,0,10,10)
    other_envelope = Mapnik::Envelope.new(9,9,12,12)
    assert envelope.intersects_envelope?(other_envelope)
    
    intersection = envelope.intersection(other_envelope)
    
    assert_not_equal(intersection, envelope)
    assert_not_equal(other_envelope, intersection)
    assert envelope.contains_envelope?(intersection)
    assert other_envelope.contains_envelope?(intersection)
  end
  
  def test_should_clip
    envelope = Mapnik::Envelope.new(0,0,10,10)
    width_before = envelope.width
    other_envelope = Mapnik::Envelope.new(9,9,12,12)
    assert envelope.intersects_envelope?(other_envelope)
    
    envelope.clip!(other_envelope)
    
    assert envelope.intersects_envelope?(other_envelope)
    assert_not_equal(width_before, envelope.width)
  end
  
  def test_validity
    envelope = Mapnik::Envelope.new(0,0,-1,-1)
    assert envelope.min_x <= envelope.max_x
    assert envelope.min_y <= envelope.max_y
    assert envelope.valid?
  end
  
end
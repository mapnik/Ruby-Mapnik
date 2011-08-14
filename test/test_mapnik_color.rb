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
class TestMapnikColor < Test::Unit::TestCase
  
  def test_should_instantiate_and_update_values
    values = {:red => 0, :green => 0, :blue => 0, :alpha => 0}
    color = Mapnik::Color.new("#000")
    color.alpha = 0
    values.each do |key, value|
      assert_equal(value, color.send("#{key}"))
      color.send("#{key}=", value + 1)
      assert_equal(value + 1, color.send("#{key}"))
    end
    
  end
  
  def test_should_instantiate_with_a_css_hex_value
    color = Mapnik::Color.new("#ff0000")
    assert_equal 255, color.red
    assert_equal 0, color.green
    assert_equal 0, color.blue
  end
  
  def test_should_instantiate_with_a_rgb_value
    red = 34
    green = 120
    blue = 134
    color = Mapnik::Color.new(red, green, blue)
    assert_equal red, color.red
    assert_equal green, color.green
    assert_equal blue, color.blue
  end
  
  def test_should_instantiate_with_a_rgba_value
    red = 34
    green = 120
    blue = 134
    alpha = 0
    color = Mapnik::Color.new(red, green, blue, alpha)
    assert_equal red, color.red
    assert_equal green, color.green
    assert_equal blue, color.blue
    assert_equal alpha, color.alpha
  end
  
end
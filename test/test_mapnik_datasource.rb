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
class TestMapnikDatasource < Test::Unit::TestCase
  
  def setup
    @datasource_params = {
      :type => 'shape',
      :file => SHAPEFILE
    }
    @datasource = Mapnik::Datasource.create(@datasource_params)
  end
  
  def test_should_create_a_new_datasource
    assert @datasource
  end
  
  def test_should_have_an_envelope
    assert @datasource.envelope.kind_of?(Mapnik::Envelope)
  end

  # def test_should_have_a_descriptor
  #   raise @datasource.descriptor.inspect
  # end

  def test_should_get_params
    assert_equal @datasource_params, @datasource.params
  end

end
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
  
  PATH = File.expand_path(File.dirname(__FILE__))
  
  def test_presence
    assert Mapnik::Datasource
    assert Mapnik::DatasourceCache
  end
  
  def test_should_register_datasource_plugins
    assert Mapnik::DatasourceCache.available_plugins.any?
  end
  
  def test_should_create_a_new_datasource
    register_datasources
    d = Mapnik::Datasource.create(
      :type => 'shape',
      :file => "#{PATH}/data/TM_WORLD_BORDERS_SIMPL_0.3_MOD"
    )
  end
  
private
  
  def register_datasources
    # TODO: Improve this somehow (maybe when the library initializes)...
    ['/opt/local/lib', '/usr/local/lib', '/usr/lib'].each do |dir|
      Mapnik::DatasourceCache.register("#{dir}/mapnik2/input")
    end
  end
  
end
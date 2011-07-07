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
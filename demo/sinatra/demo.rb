CURRENT_PATH = File.expand_path(File.dirname(__FILE__))
require 'rubygems'
require 'sinatra'
require File.join(CURRENT_PATH, '..', '..', 'lib', 'ruby_mapnik')

PATH = File.expand_path(File.dirname(__FILE__))


map = Mapnik::Map.new do |m|
  
  m.background = Mapnik::Color.new('#777')
  
  m.srs =  Mapnik::Tile::DEFAULT_OUTPUT_PROJECTION
  
  m.layer 'countries' do |l|
    l.style do |s|
      s.rule do |default|
        default.fill = Mapnik::Color.new('#880000')
      end
    end
    l.srs = "+proj=latlong +datum=WGS84"
    l.datasource = Mapnik::Datasource.create :type => 'shape', :file => "#{PATH}/../data/TM_WORLD_BORDERS_SIMPL_0.3_MOD"
  end

end

get '/tiles/:zoom/:x/:y.png' do
  tile = Mapnik::Tile.new(params[:zoom], params[:x], params[:y])
  content_type 'image/png', :disposition => 'inline'
  tile.render_to_string(map)
end
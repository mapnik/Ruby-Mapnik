CURRENT_PATH = File.expand_path(File.dirname(__FILE__))
require File.join(CURRENT_PATH, '..', 'lib', 'ruby_mapnik')

map = Mapnik::Map.new do |m|

  m.width = 1024
  m.height = 768
  m.background = Mapnik::Color.new("#fff")
  m.srs = "+proj=merc +a=6378137 +b=6378137 +lat_ts=0.0 +lon_0=0.0 +x_0=0.0 +y_0=0 +k=1.0 +units=m +nadgrids=@null +no_defs"
  
  nd83_srs = "+proj=lcc +ellps=GRS80 +lat_0=49 +lon_0=-95 +lat+1=49 +lat_2=77 +datum=NAD83 +units=m +no_defs"
  
  m.layer "provinces", nd83_srs do |prov|
    prov.datasource = Mapnik::Datasource.create(:type => "shape", :file => File.join(CURRENT_PATH, 'data/boundaries'))
    prov.style do |s|
      s.rule "[NAME_EN] = 'Ontario'" do |ontario|
        ontario.fill = Mapnik::Color.new('#FABEB7')
      end
      
      s.rule "[NAME_EN] = 'Quebec'" do |quebec|
        quebec.fill = Mapnik::Color.new('#D9EBCB')
      end   
    end  
  end
    
  m.style 'drainage' do |style|
    style.rule '[HYC] = 8' do |drainage|
      drainage.fill = Mapnik::Color.new('#99CCFF')
    end
  end
  
  m.layer "quebec_hydro", nd83_srs do |q_hydro|
    q_hydro.datasource = Mapnik::Datasource.create(:type => "shape", :file => File.join(CURRENT_PATH, 'data/qcdrainage'))
    q_hydro.styles << 'drainage'
  end
  
  m.layer "ontario_hydro", nd83_srs do |o_hydro|
    o_hydro.datasource = Mapnik::Datasource.create(:type => "shape", :file => File.join(CURRENT_PATH, 'data/ontdrainage'))
    o_hydro.styles << 'drainage'
  end
  
  m.layer "provincial_borders", nd83_srs do |borders|
    borders.datasource = Mapnik::Datasource.create(:type => "shape", :file => File.join(CURRENT_PATH, 'data/boundaries_l'))
    borders.style do |s|
      s.rule do |default|
        default.line do |stroke|
          stroke.color = Mapnik::Color.new('#000')
          stroke.dashes << {:gap => 8, :length => 4}
          stroke.dashes << {:gap => 2, :length => 2}
          stroke.dashes << {:gap => 2, :length => 2}
        end
      end
    end
  end
  
  roads_datasource = Mapnik::Datasource.create(:type => "shape", :file => File.join(CURRENT_PATH, 'data/roads'))
  m.layer 'roads_3_and_4', nd83_srs do |layer|
    layer.datasource = roads_datasource
    layer.style do |s|
      s.rule '([CLASS] = 3) or ([CLASS] = 4)' do |road|
        road.line do |stroke|
          stroke.color = Mapnik::Color.new('#AB9E89')
          stroke.width = 2.0
        end
      end
    end
  end
  
  m.layer 'roads_2', nd83_srs do |layer|
    layer.datasource = roads_datasource
    
    layer.style 'road_fill' do |s|
      s.rule '[CLASS] = 2' do |road|
        road.line do |stroke|
          stroke.color = Mapnik::Color.new('#AB9E89')
          stroke.width = 4.0
        end
      end
    end
    
    layer.style 'road_border' do |s|
      s.rule '[CLASS] = 2' do |road|
        road.line do |stroke|
          stroke.color = Mapnik::Color.new('#FFFA73')
          stroke.width = 2.0
        end
      end
    end
    
  end
  
  m.layer 'roads_1', nd83_srs do |layer|
    layer.datasource = roads_datasource
    
    layer.style 'highway_fill' do |s|
      s.rule '[CLASS] = 1' do |road|
        road.line do |stroke|
          stroke.color = Mapnik::Color.new('#BC951C')
          stroke.width = 7.0
        end
      end
    end
    
    layer.style 'highway_border' do |s|
      s.rule '[CLASS] = 1' do |road|
        road.line do |stroke|
          stroke.color = Mapnik::Color.new('#F2BF24')
          stroke.width = 5.0
        end
      end
    end
  end
  
  m.layer 'populated_places', nd83_srs do |layer|
    layer.datasource = Mapnik::Datasource.create(:type => "shape", :file => File.join(CURRENT_PATH, 'data/popplaces'))
    layer.style do |style|
      style.rule do |default|
        color = Mapnik::Color.new('#000')
        default.text "[GEONAME]" do |text|
          text.label_placement = Mapnik::LABEL_PLACEMENT::POINT_PLACEMENT
          text.fill = Mapnik::Color.new('#000')
          text.halo_fill = Mapnik::Color.new("#fff")
          text.halo_radius = 1
          text.avoid_edges = true
        end
        
      end
    end
  end
  
end

# Rendering...
filename = File.join(CURRENT_PATH, '..', 'tmp', 'block_demo.png')
map.zoom_to_box(Mapnik::Envelope.new(-8024477.28459,5445190.38849,-7381388.20071,5662941.44855)) 
map.render_to_file(filename)
`open #{filename}`

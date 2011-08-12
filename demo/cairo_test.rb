CURRENT_PATH = File.expand_path(File.dirname(__FILE__))
require 'rubygems'
require 'cairo'
require File.join(CURRENT_PATH, '..', 'lib', 'ruby_mapnik')

width = 800
height = 600

# data = nil
# stride = nil

# Instantiate a map
map = Mapnik::Map.new(800,600,"+proj=merc +a=6378137 +b=6378137 +lat_ts=0.0 +lon_0=0.0 +x_0=0.0 +y_0=0 +k=1.0 +units=m +nadgrids=@null +no_defs")

# Set its background color
map.background = Mapnik::Color.new("#fff")

# Canadian Provinces (Polygons)
province_srs = "+proj=lcc +ellps=GRS80 +lat_0=49 +lon_0=-95 +lat+1=49 +lat_2=77 +datum=NAD83 +units=m +no_defs"
province_polygon_layer = Mapnik::Layer.new('Provinces', province_srs)

province_polygon_layer.datasource = Mapnik::Datasource.create(:type => "shape", :file => File.join(CURRENT_PATH, 'data/boundaries'))

province_polygon_style = Mapnik::Style.new

province_polygon_rule_on = Mapnik::Rule.new

province_polygon_rule_on.filter = Mapnik::Expression.parse("[NAME_EN] = 'Ontario'")

province_polygon_symbolizer = Mapnik::PolygonSymbolizer.new
province_polygon_symbolizer.fill = Mapnik::Color.new('#FABEB7')
province_polygon_rule_on.symbols << province_polygon_symbolizer
province_polygon_style.rules << province_polygon_rule_on

province_polygon_rule_qc = Mapnik::Rule.new
province_polygon_rule_qc.filter = Mapnik::Expression.parse("[NAME_EN] = 'Quebec'")
province_polygon_symbolizer_qc = Mapnik::PolygonSymbolizer.new
province_polygon_symbolizer_qc.fill = Mapnik::Color.new('#D9EBCB')
province_polygon_rule_qc.symbols << province_polygon_symbolizer_qc
province_polygon_style.rules << province_polygon_rule_qc

map.styles["provinces"] = province_polygon_style
province_polygon_layer.styles << 'provinces'
map.layers << province_polygon_layer

# Drainage

# A simple example ...
qcdrain_srs = "+proj=lcc +ellps=GRS80 +lat_0=49 +lon_0=-95 +lat+1=49 +lat_2=77 +datum=NAD83 +units=m +no_defs"
qcdrain_layer = Mapnik::Layer.new('Quebec Hydrography', qcdrain_srs)
qcdrain_layer.datasource = Mapnik::Datasource.create(:type => "shape", :file => File.join(CURRENT_PATH, 'data/qcdrainage'))
qcdrain_style = Mapnik::Style.new
qcdrain_rule = Mapnik::Rule.new
qcdrain_rule.filter = Mapnik::Expression.parse('[HYC] = 8')
qcdrain_polygon = Mapnik::PolygonSymbolizer.new
qcdrain_polygon.fill = Mapnik::Color.new('#99CCFF')
qcdrain_rule.symbols << qcdrain_polygon
qcdrain_style.rules << qcdrain_rule

map.styles['drainage'] = qcdrain_style
qcdrain_layer.styles << 'drainage'
map.layers << qcdrain_layer


ondrain_srs = "+proj=lcc +ellps=GRS80 +lat_0=49 +lon_0=-95 +lat+1=49 +lat_2=77 +datum=NAD83 +units=m +no_defs"
ondrain_lyr = Mapnik::Layer.new('Ontario Hydrography', ondrain_srs)
ondrain_lyr.datasource = Mapnik::Datasource.create(:type => "shape", :file => File.join(CURRENT_PATH, 'data/ontdrainage'))
ondrain_lyr.styles << 'drainage'
map.layers << ondrain_lyr

provlines_srs = "+proj=lcc +ellps=GRS80 +lat_0=49 +lon_0=-95 +lat+1=49 +lat_2=77 +datum=NAD83 +units=m +no_defs"
provlines_layer = Mapnik::Layer.new('Provincial Borders', provlines_srs)
provlines_layer.datasource = Mapnik::Datasource.create(:type => "shape", :file => File.join(CURRENT_PATH, 'data/boundaries_l'))

provlines_color = Mapnik::Color.new("#fff")
provlines_stroke = Mapnik::Stroke.new(provlines_color, 1.0)
provlines_stroke.dashes << {:gap => 8, :length => 4}
provlines_stroke.dashes << {:gap => 2, :length => 2}
provlines_stroke.dashes << {:gap => 2, :length => 2}

provlines_style = Mapnik::Style.new
provlines_rule = Mapnik::Rule.new
provlines_symbolizer = Mapnik::LineSymbolizer.new
provlines_symbolizer.stroke = provlines_stroke
provlines_rule.symbols << provlines_symbolizer
provlines_style.rules << provlines_rule
map.styles['provlines'] = provlines_style
provlines_layer.styles << 'provlines'
map.layers << provlines_layer


roads_datasource = Mapnik::Datasource.create(:type => "shape", :file => File.join(CURRENT_PATH, 'data/roads'))
roads_srs = "+proj=lcc +ellps=GRS80 +lat_0=49 +lon_0=-95 +lat+1=49 +lat_2=77 +datum=NAD83 +units=m +no_defs"
# Roads 3 and 4 (The "grey" roads)
roads34_layer = Mapnik::Layer.new('Roads', roads_srs)
roads34_layer.srs = roads_srs
roads34_layer.datasource = roads_datasource
roads34_style = Mapnik::Style.new
roads34_rule = Mapnik::Rule.new
roads34_rule.filter = Mapnik::Expression.parse('([CLASS] = 3) or ([CLASS] = 4)')

roads34_rule_stk = Mapnik::Stroke.new(Mapnik::Color.new('#AB9E89'), 2.0)
#roads34_rule_stk.line_cap = Mapnik::LineCap::ROUND_CAP
roads34_symbolizer = Mapnik::LineSymbolizer.new
roads34_symbolizer.stroke = roads34_rule_stk
roads34_rule.symbols << roads34_symbolizer
roads34_style.rules << roads34_rule

map.styles['smallroads'] = roads34_style
roads34_layer.styles << 'smallroads'
map.layers << roads34_layer

# Roads 2 (The thin yellow ones)

roads2_layer = Mapnik::Layer.new('Roads', roads_srs)
roads2_layer.datasource = roads_datasource 

roads2_style_1 = Mapnik::Style.new
roads2_rule_1 = Mapnik::Rule.new
roads2_rule_1.filter = Mapnik::Expression.parse('[CLASS] = 2')
roads2_rule_stk_1 = Mapnik::Stroke.new(Mapnik::Color.new('#AB9E89'), 4.0)
#roads2_rule_stk_1.line_cap = Mapnik::LineCap::ROUND_CAP
roads2_symbolizer1 = Mapnik::LineSymbolizer.new
roads2_symbolizer1.stroke = roads2_rule_stk_1
roads2_rule_1.symbols << roads2_symbolizer1
roads2_style_1.rules << roads2_rule_1

map.styles['road-border'] = roads2_style_1

roads2_style_2 = Mapnik::Style.new
roads2_rule_2 = Mapnik::Rule.new
roads2_rule_2.filter = Mapnik::Expression.parse('[CLASS] = 2')
roads2_rule_stk_2 = Mapnik::Stroke.new(Mapnik::Color.new('#FFFA73'), 2.0)
#roads2_rule_stk_2.line_cap = Mapnik::LineCap::ROUND_CAP
roads2_rule_2_symbolizer = Mapnik::LineSymbolizer.new
roads2_rule_2_symbolizer.stroke = roads2_rule_stk_2
roads2_rule_2.symbols << roads2_rule_2_symbolizer
roads2_style_2.rules << roads2_rule_2

map.styles['road-fill'] = roads2_style_2

roads2_layer.styles << 'road-border'
roads2_layer.styles << 'road-fill'

map.layers << roads2_layer

# Roads 1 (The big orange ones, the highways)

roads1_layer = Mapnik::Layer.new('Roads', roads_srs)
roads1_layer.datasource = roads_datasource

roads1_style_1 = Mapnik::Style.new
roads1_rule_1 = Mapnik::Rule.new
roads1_rule_1.filter = Mapnik::Expression.parse('[CLASS] = 1')
roads1_rule_stk_1 = Mapnik::Stroke.new(Mapnik::Color.new('#BC951C'), 7.0) 
#roads1_rule_stk_1.line_cap = Mapnik::LineCap::ROUND_CAP
roads1_rule1_symbolizer = Mapnik::LineSymbolizer.new
roads1_rule1_symbolizer.stroke = roads1_rule_stk_1
roads1_rule_1.symbols << roads1_rule1_symbolizer
roads1_style_1.rules << roads1_rule_1
map.styles['highway-border'] = roads1_style_1

roads1_style_2 = Mapnik::Style.new
roads1_rule_2 = Mapnik::Rule.new
roads1_rule_2.filter = Mapnik::Expression.parse('[CLASS] = 1')
roads1_rule_stk_2 = Mapnik::Stroke.new(Mapnik::Color.new('#F2BF24'), 5.0)
##roads1_rule_stk_2.line_cap = Mapnik::LineCap::ROUND_CAP
roads1_rule2_symbolizer = Mapnik::LineSymbolizer.new
roads1_rule2_symbolizer.stroke = roads1_rule_stk_2 
roads1_rule_2.symbols << roads1_rule2_symbolizer
roads1_style_2.rules << roads1_rule_2

map.styles['highway-fill'] = roads1_style_2

roads1_layer.styles << 'highway-border'
roads1_layer.styles << 'highway-fill'

map.layers << roads1_layer

# Populated Places

popplaces_lyr = Mapnik::Layer.new('Populated Places', roads_srs)
popplaces_lyr.datasource = Mapnik::Datasource.create(:type => "shape", :file => File.join(CURRENT_PATH, 'data/popplaces'))

popplaces_style = Mapnik::Style.new
popplaces_rule = Mapnik::Rule.new

# And here we have a TextSymbolizer, used for labeling.
# The first parameter is the name of the attribute to use as the source of the
# text to label with.  Then there is font size in points (I think?), and colour.
text_color = Mapnik::Color.new("#000")
text_expression = Mapnik::Expression.parse("[GEONAME]")
popplaces_text_symbolizer = Mapnik::TextSymbolizer.new(text_expression,
                                           'DejaVu Sans Book',
                                           10, text_color)

# We set a "halo" around the text, which looks like an outline if thin enough,
# or an outright background if large enough.
popplaces_text_symbolizer.label_placement= Mapnik::LABEL_PLACEMENT::POINT_PLACEMENT
popplaces_text_symbolizer.halo_fill = Mapnik::Color.new("#fff")
popplaces_text_symbolizer.halo_radius = 1
popplaces_text_symbolizer.avoid_edges = true
#popplaces_text_symbolizer.minimum_padding = 30

popplaces_rule.symbols << popplaces_text_symbolizer

popplaces_style.rules << popplaces_rule

map.styles['popplaces'] = popplaces_style
popplaces_lyr.styles << 'popplaces'
map.layers << popplaces_lyr

map.zoom_to_box(Mapnik::Envelope.new(-8024477.28459,5445190.38849,-7381388.20071,5662941.44855)) 

Cairo::ImageSurface.new(width, height) do |surface|
  cr = Cairo::Context.new(surface)
  map.render_to_cairo_context(cr, 0, 0)
  cr.target.write_to_png("test.png")
end

`open test.png`
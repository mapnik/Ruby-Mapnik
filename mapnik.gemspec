# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = "mapnik"
  s.version = "0.2.0"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = ["Andy Allan"]
  s.date = "2015-07-01"
  s.description = "A set of bindings between Ruby and Mapnik. Supports many of the common uses for \nMapnik, and one day, might support all of them. Rendering is available using\nthe standard AGG library, or additionally via Cairo, if the rcairo gem is \ninstalled and Mapnik has been compiled with Cairo support."
  s.email = ["info@gravitystorm.co.uk"]
  s.extensions = ["ext/ruby_mapnik/extconf.rb"]
  s.extra_rdoc_files = ["Manifest.txt", "README.rdoc", "demo/data/COPYRIGHT.txt", "demo/data/test/readme.txt"]
  s.files = [".autotest", ".yardopts", "Gemfile", "LICENSE", "Manifest.txt", "README.rdoc", "Rakefile", "demo/data/COPYRIGHT.txt", "demo/data/TM_WORLD_BORDERS_SIMPL_0.3_MOD.dbf", "demo/data/TM_WORLD_BORDERS_SIMPL_0.3_MOD.prj", "demo/data/TM_WORLD_BORDERS_SIMPL_0.3_MOD.shp", "demo/data/TM_WORLD_BORDERS_SIMPL_0.3_MOD.shx", "demo/data/boundaries.dbf", "demo/data/boundaries.prj", "demo/data/boundaries.sbx", "demo/data/boundaries.shp", "demo/data/boundaries.shx", "demo/data/boundaries_l.dbf", "demo/data/boundaries_l.prj", "demo/data/boundaries_l.sbx", "demo/data/boundaries_l.shp", "demo/data/boundaries_l.shx", "demo/data/ontdrainage.dbf", "demo/data/ontdrainage.prj", "demo/data/ontdrainage.sbx", "demo/data/ontdrainage.shp", "demo/data/ontdrainage.shx", "demo/data/popplaces.dbf", "demo/data/popplaces.prj", "demo/data/popplaces.sbx", "demo/data/popplaces.shp", "demo/data/popplaces.shx", "demo/data/qcdrainage.dbf", "demo/data/qcdrainage.prj", "demo/data/qcdrainage.sbx", "demo/data/qcdrainage.shp", "demo/data/qcdrainage.shx", "demo/data/roads.dbf", "demo/data/roads.prj", "demo/data/roads.sbx", "demo/data/roads.shp", "demo/data/roads.shx", "demo/data/test/charplacement.dbf", "demo/data/test/charplacement.shp", "demo/data/test/charplacement.shx", "demo/data/test/displacement.dbf", "demo/data/test/displacement.shp", "demo/data/test/displacement.shx", "demo/data/test/overlap.dbf", "demo/data/test/overlap.shp", "demo/data/test/overlap.shx", "demo/data/test/raw/charplacement.gfs", "demo/data/test/raw/charplacement.gml", "demo/data/test/raw/charplacement.xsd", "demo/data/test/raw/displacement.gfs", "demo/data/test/raw/displacement.gml", "demo/data/test/raw/displacement.xsd", "demo/data/test/raw/overlap.gfs", "demo/data/test/raw/overlap.gml", "demo/data/test/raw/overlap.xsd", "demo/data/test/raw/textspacing.gfs", "demo/data/test/raw/textspacing.gml", "demo/data/test/raw/textspacing.xsd", "demo/data/test/readme.txt", "demo/data/test/regenerate.sh", "demo/data/test/textspacing.dbf", "demo/data/test/textspacing.shp", "demo/data/test/textspacing.shx", "demo/rundemo.rb", "demo/sinatra/demo.rb", "demo/sinatra/public/css/demo_map.css", "demo/sinatra/public/index.html", "demo/sinatra/public/javascripts/demo_map.js", "ext/ruby_mapnik/_mapnik.cpp", "ext/ruby_mapnik/_mapnik.h", "ext/ruby_mapnik/_mapnik_color.rb.cpp", "ext/ruby_mapnik/_mapnik_color.rb.h", "ext/ruby_mapnik/_mapnik_coord.rb.cpp", "ext/ruby_mapnik/_mapnik_coord.rb.h", "ext/ruby_mapnik/_mapnik_datasource.rb.cpp", "ext/ruby_mapnik/_mapnik_datasource.rb.h", "ext/ruby_mapnik/_mapnik_datasource_cache.rb.cpp", "ext/ruby_mapnik/_mapnik_datasource_cache.rb.h", "ext/ruby_mapnik/_mapnik_envelope.rb.cpp", "ext/ruby_mapnik/_mapnik_envelope.rb.h", "ext/ruby_mapnik/_mapnik_expression.rb.cpp", "ext/ruby_mapnik/_mapnik_expression.rb.h", "ext/ruby_mapnik/_mapnik_feature.rb.cpp", "ext/ruby_mapnik/_mapnik_feature.rb.h", "ext/ruby_mapnik/_mapnik_font_engine.rb.cpp", "ext/ruby_mapnik/_mapnik_font_engine.rb.h", "ext/ruby_mapnik/_mapnik_layer.rb.cpp", "ext/ruby_mapnik/_mapnik_layer.rb.h", "ext/ruby_mapnik/_mapnik_line_pattern_symbolizer.rb.cpp", "ext/ruby_mapnik/_mapnik_line_pattern_symbolizer.rb.h", "ext/ruby_mapnik/_mapnik_line_symbolizer.rb.cpp", "ext/ruby_mapnik/_mapnik_line_symbolizer.rb.h", "ext/ruby_mapnik/_mapnik_map.rb.cpp", "ext/ruby_mapnik/_mapnik_map.rb.h", "ext/ruby_mapnik/_mapnik_markers_symbolizer.rb.cpp", "ext/ruby_mapnik/_mapnik_markers_symbolizer.rb.h", "ext/ruby_mapnik/_mapnik_point_symbolizer.rb.cpp", "ext/ruby_mapnik/_mapnik_point_symbolizer.rb.h", "ext/ruby_mapnik/_mapnik_polygon_pattern_symbolizer.rb.cpp", "ext/ruby_mapnik/_mapnik_polygon_pattern_symbolizer.rb.h", "ext/ruby_mapnik/_mapnik_polygon_symbolizer.rb.cpp", "ext/ruby_mapnik/_mapnik_polygon_symbolizer.rb.h", "ext/ruby_mapnik/_mapnik_projection.rb.cpp", "ext/ruby_mapnik/_mapnik_projection.rb.h", "ext/ruby_mapnik/_mapnik_raster_colorizer.rb.cpp", "ext/ruby_mapnik/_mapnik_raster_colorizer.rb.h", "ext/ruby_mapnik/_mapnik_raster_symbolizer.rb.cpp", "ext/ruby_mapnik/_mapnik_raster_symbolizer.rb.h", "ext/ruby_mapnik/_mapnik_rule.rb.cpp", "ext/ruby_mapnik/_mapnik_rule.rb.h", "ext/ruby_mapnik/_mapnik_shield_symbolizer.rb.cpp", "ext/ruby_mapnik/_mapnik_shield_symbolizer.rb.h", "ext/ruby_mapnik/_mapnik_stroke.rb.cpp", "ext/ruby_mapnik/_mapnik_stroke.rb.h", "ext/ruby_mapnik/_mapnik_style.rb.cpp", "ext/ruby_mapnik/_mapnik_style.rb.h", "ext/ruby_mapnik/_mapnik_symbolizer.rb.cpp", "ext/ruby_mapnik/_mapnik_symbolizer.rb.h", "ext/ruby_mapnik/_mapnik_text_symbolizer.rb.cpp", "ext/ruby_mapnik/_mapnik_text_symbolizer.rb.h", "ext/ruby_mapnik/extconf.rb", "ext/ruby_mapnik/ruby_mapnik.cpp", "lib/mapnik.rb", "lib/ruby_mapnik.rb", "lib/ruby_mapnik/mapnik/font_engine.rb", "lib/ruby_mapnik/mapnik/layer.rb", "lib/ruby_mapnik/mapnik/map.rb", "lib/ruby_mapnik/mapnik/projection.rb", "lib/ruby_mapnik/mapnik/raster_colorizer.rb", "lib/ruby_mapnik/mapnik/rule.rb", "lib/ruby_mapnik/mapnik/stroke.rb", "lib/ruby_mapnik/mapnik/style.rb", "lib/ruby_mapnik/mapnik/tile.rb", "script/console", "test/data/TM_WORLD_BORDERS_SIMPL_0.3_MOD.dbf", "test/data/TM_WORLD_BORDERS_SIMPL_0.3_MOD.prj", "test/data/TM_WORLD_BORDERS_SIMPL_0.3_MOD.shp", "test/data/TM_WORLD_BORDERS_SIMPL_0.3_MOD.shx", "test/data/test_map.xml", "test/test_helper.rb", "test/test_line_pattern_symbolizer.rb", "test/test_mapnik_color.rb", "test/test_mapnik_coord.rb", "test/test_mapnik_datasource.rb", "test/test_mapnik_envelope.rb", "test/test_mapnik_expression.rb", "test/test_mapnik_feature.rb", "test/test_mapnik_font_engine.rb", "test/test_mapnik_layer.rb", "test/test_mapnik_line_symbolizer.rb", "test/test_mapnik_map.rb", "test/test_mapnik_markers_symbolizer.rb", "test/test_mapnik_point_symbolizer.rb", "test/test_mapnik_polygon_symbolizer.rb", "test/test_mapnik_projection.rb", "test/test_mapnik_raster_colorizer.rb", "test/test_mapnik_raster_symbolizer.rb", "test/test_mapnik_rule.rb", "test/test_mapnik_shield_symbolizer.rb", "test/test_mapnik_stroke.rb", "test/test_mapnik_style.rb", "test/test_mapnik_symbolizer.rb", "test/test_mapnik_text_symbolizer.rb", "test/test_polygon_pattern_symbolizer.rb", "test/test_ruby_mapnik.rb", "yard/lib/yard/parser/generic_parser.rb", "yard/lib/yard_generic.rb", ".gemtest"]
  s.homepage = "https://github.com/mapnik/Ruby-Mapnik"
  s.rdoc_options = ["--main", "README.rdoc"]
  s.require_paths = ["lib"]
  s.rubyforge_project = "mapnik"
  s.rubygems_version = "1.8.23"
  s.summary = "A set of bindings between Ruby and Mapnik"
  s.test_files = ["test/test_mapnik_rule.rb", "test/test_line_pattern_symbolizer.rb", "test/test_ruby_mapnik.rb", "test/test_mapnik_point_symbolizer.rb", "test/test_mapnik_stroke.rb", "test/test_mapnik_expression.rb", "test/test_mapnik_layer.rb", "test/test_mapnik_text_symbolizer.rb", "test/test_mapnik_polygon_symbolizer.rb", "test/test_mapnik_projection.rb", "test/test_mapnik_datasource.rb", "test/test_mapnik_coord.rb", "test/test_mapnik_raster_symbolizer.rb", "test/test_mapnik_feature.rb", "test/test_mapnik_symbolizer.rb", "test/test_polygon_pattern_symbolizer.rb", "test/test_mapnik_font_engine.rb", "test/test_mapnik_markers_symbolizer.rb", "test/test_mapnik_raster_colorizer.rb", "test/test_helper.rb", "test/test_mapnik_shield_symbolizer.rb", "test/test_mapnik_color.rb", "test/test_mapnik_map.rb", "test/test_mapnik_style.rb", "test/test_mapnik_envelope.rb", "test/test_mapnik_line_symbolizer.rb"]

  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_runtime_dependency(%q<rice>, [">= 1.4.2"])
      s.add_development_dependency(%q<rdoc>, ["~> 3.10"])
      s.add_development_dependency(%q<rake-compiler>, [">= 0"])
      s.add_development_dependency(%q<chunky_png>, [">= 0"])
      s.add_development_dependency(%q<hoe>, ["~> 3.5"])
    else
      s.add_dependency(%q<rice>, [">= 1.4.2"])
      s.add_dependency(%q<rdoc>, ["~> 3.10"])
      s.add_dependency(%q<rake-compiler>, [">= 0"])
      s.add_dependency(%q<chunky_png>, [">= 0"])
      s.add_dependency(%q<hoe>, ["~> 3.5"])
    end
  else
    s.add_dependency(%q<rice>, [">= 1.4.2"])
    s.add_dependency(%q<rdoc>, ["~> 3.10"])
    s.add_dependency(%q<rake-compiler>, [">= 0"])
    s.add_dependency(%q<chunky_png>, [">= 0"])
    s.add_dependency(%q<hoe>, ["~> 3.5"])
  end
end

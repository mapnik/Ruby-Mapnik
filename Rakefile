require 'rubygems'
require 'hoe'
require "rake/extensiontask"
# Hoe.plugin :compiler
# Hoe.plugin :compiler
# Hoe.plugin :gem_prelude_sucks
# Hoe.plugin :gem_prelude_sucks
# Hoe.plugin :inline
# Hoe.plugin :inline
# Hoe.plugin :racc
# Hoe.plugin :racc
# Hoe.plugin :rubyforge
# Hoe.plugin :rubyforge

Hoe.spec 'ruby_mapnik' do
  developer('Elliot Laster', 'elliotlaster@gmail.com')
  # self.readme_file   = 'README.rdoc'
  # self.history_file  = 'CHANGELOG.rdoc'
  # self.extra_rdoc_files  = FileList['*.rdoc']
  self.extra_dev_deps << ['rake-compiler', '>= 0']
  self.spec_extras = { :extensions => ["ext/ruby_mapnik/extconf.rb"] }

  Rake::ExtensionTask.new('ruby_mapnik', spec) do |ext|
    ext.lib_dir = File.join('lib', 'ruby_mapnik')
  end
end

Rake::Task[:test].prerequisites << :compile
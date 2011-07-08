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
require 'rubygems'
require 'hoe'
require "rake/extensiontask"

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
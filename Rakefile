=begin 
*******************************************************************************
Permission is hereby granted, free of charge, to any person obtaining a copy of 
this software and associated documentation files (the ‘Software’), to deal in 
the Software without restriction, including without limitation the rights to 
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all 
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED ‘AS IS’, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
SOFTWARE.
*******************************************************************************
=end
require 'rubygems'
require 'hoe'
require 'rake/extensiontask'

Hoe.plugin :bundler, :rubygems, :doofus, :git

Hoe.spec 'ruby_mapnik' do
  developer('Elliot Laster', 'elliotlaster@gmail.com')
  self.readme_file   = 'README.rdoc'
  # self.history_file  = 'CHANGELOG.rdoc'
  self.extra_deps << ['rice', '>= 1.4.2']
  self.extra_dev_deps << ['rake-compiler', '>= 0']


  self.spec_extras = { :extensions => ["ext/ruby_mapnik/extconf.rb"] }

  Rake::ExtensionTask.new('ruby_mapnik', spec) do |ext|
    ext.lib_dir = File.join('lib', 'ruby_mapnik')
  end
end

Rake::Task[:test].prerequisites << :compile

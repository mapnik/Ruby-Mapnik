# -*- encoding: utf-8 -*-

Gem::Specification.new do |s|
  s.name = %q{ruby_mapnik}
  s.version = "0.1.2"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = ["Elliot Laster"]
  s.date = %q{2011-09-09}
  s.description = %q{}
  s.email = ["elliotlaster@gmail.com"]
  s.extensions = ["ext/ruby_mapnik/extconf.rb"]
  s.extra_rdoc_files = ["Manifest.txt", "demo/data/COPYRIGHT.txt", "demo/data/test/readme.txt"]
  s.rdoc_options = ["--main", "README.rdoc"]
  s.require_paths = ["lib"]
  s.rubyforge_project = %q{ruby_mapnik}
  s.rubygems_version = %q{1.4.2}
  s.summary = nil
  s.files         = `git ls-files`.split($\)
  s.executables   = s.files.grep(%r{^bin/}).map{ |f| File.basename(f) }
  s.test_files    = s.files.grep(%r{^(test|spec|features)/})

  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_runtime_dependency(%q<rice>, [">= 1.4.2"])
      s.add_development_dependency(%q<rake-compiler>, [">= 0"])
      s.add_development_dependency(%q<hoe>, ["~> 2.12"])
    else
      s.add_dependency(%q<rice>, [">= 1.4.2"])
      s.add_dependency(%q<rake-compiler>, [">= 0"])
      s.add_dependency(%q<hoe>, ["~> 2.12"])
    end
  else
    s.add_dependency(%q<rice>, [">= 1.4.2"])
    s.add_dependency(%q<rake-compiler>, [">= 0"])
    s.add_dependency(%q<hoe>, ["~> 2.12"])
  end
end

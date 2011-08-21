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

# Compile with Rice rather than straight mkmf
require 'rubygems'
require 'mkmf-rice'

# Add the arguments to the linker flags.
def append_ld_flags(flags) 
    flags = [flags] unless flags.is_a?(Array)
    with_ldflags("#{$LDFLAGS} #{flags.join(' ')}") { true }
end

LIBDIR = Config::CONFIG['libdir'] #:nodoc:
INCLUDEDIR = Config::CONFIG['includedir'] #:nodoc:

HEADER_DIRS = [

# Then search /usr/local for people that installed from source
'/usr/local/include/',
# '/usr/local/include/cairomm-1.0',
# '/usr/local/include/cairo',
# '/usr/local/include/sigc++-2.0',
# '/usr/local/include/sigc++-2.0/sigc++',
'/opt/local/include/',

# Check the ruby install locations
INCLUDEDIR,

# Finally fall back to /usr
'/usr/include/',
'/usr/X11/include',
'/usr/include/mapnik/'
] #:nodoc:

LIB_DIRS = [
# First search /usr/local for people that installed from source
'/usr/local/lib',  
  
# Then search /opt/local for macports
'/opt/local/lib',

# Check the ruby install locations
LIBDIR,

# X11 
'/usr/X11/lib',

# Finally fall back to /usr
'/usr/lib',
]

FREETYPE2_HEADER_DIRS = HEADER_DIRS.map{|x| File.join(x, 'freetype2')} + HEADER_DIRS
CAIROMM_HEADER_DIRS = HEADER_DIRS.map{|x| File.join(x, 'cairomm')} + HEADER_DIRS
CAIRO_HEADER_DIRS = HEADER_DIRS.map{|x| File.join(x, 'cairo')} + HEADER_DIRS
SIGC_HEADER_DIRS = HEADER_DIRS.map{|x| File.join(x, 'sigc++')} + HEADER_DIRS
SIGC_CONFIG_HEADER_DIRS = HEADER_DIRS.map{|x| File.join(x, 'sigc++', 'sigc++')} + HEADER_DIRS


dir_config('freetype2', FREETYPE2_HEADER_DIRS, LIB_DIRS)
dir_config("cairomm", CAIROMM_HEADER_DIRS, LIB_DIRS)
dir_config("cairo", CAIRO_HEADER_DIRS, LIB_DIRS)
dir_config("sigc++", SIGC_HEADER_DIRS, LIB_DIRS)
dir_config("sigc++config", SIGC_CONFIG_HEADER_DIRS, LIB_DIRS)

# Thanks, nokogiri!
def asplode(lib)
  abort "---\n#{lib} is missing!"
end

asplode "freetype2" unless find_header('freetype/config/ftheader.h')
asplode "cairomm" unless find_header('cairomm/types.h')
asplode "cairo" unless find_header('cairo/cairo.h')
asplode "sigc++" unless find_header('sigc++/sigc++config.h')
asplode "sigc++config.h" unless find_header('sigc++config.h')

$LDFLAGS += " -lmapnik2 "

if RUBY_PLATFORM =~ /darwin/
    # In order to link the shared library into our bundle with GCC 4.x on OSX, we have to work around a bug:
    #   GCC redefines symbols - which the -fno-common prohibits.  In order to keep the -fno-common, we
    #   remove the flat_namespace (we now have two namespaces, which fixes the GCC clash).  Also, we now lookup
    #   symbols in both the namespaces (dynamic_lookup).
    
    $LDSHARED_CXX.gsub!('suppress', 'dynamic_lookup')
    $LDSHARED_CXX.gsub!('-flat_namespace', '')
    
    append_ld_flags '-all_load'
end

create_makefile("ruby_mapnik")

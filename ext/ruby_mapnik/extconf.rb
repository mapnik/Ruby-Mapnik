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

LIBDIR = Config::CONFIG['libdir']
INCLUDEDIR = Config::CONFIG['includedir'] 

$LDFLAGS += " -lmapnik2 "
$CFLAGS += `mapnik-config --cflags`

dir_config('freetype2')
dir_config("cairomm")
dir_config("cairo")
dir_config("sigc++")
dir_config("sigc++config")


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

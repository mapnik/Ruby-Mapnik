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

HEADER_DIRS = [

# Then search /usr/local for people that installed from source
'/usr/local/include/',

'/opt/local/include/',

# Check the ruby install locations
INCLUDEDIR,

# Finally fall back to /usr
'/usr/include/',
'/usr/X11/include',
'/usr/include/mapnik/',
]

LIB_DIRS = [
# First search /opt/local for macports
'/opt/local/lib',

# Then search /usr/local for people that installed from source
'/usr/local/lib',

# Check the ruby install locations
LIBDIR,

# X11 
'/usr/X11/lib',

# Finally fall back to /usr
'/usr/lib',
]

dir_config('freetype2', [
           '/opt/local/include/freetype2',
           '/usr/local/include/freetype2',
           '/usr/X11/include/freetype2',
           File.join(INCLUDEDIR, "freetype2")] + HEADER_DIRS, LIB_DIRS)

# ruby extconf.rb --with_mapnik_include=/usr/local/mapnik/include --with_boost_include=/usr/local/include/boost --with_freetype_include=/opt/local/include/freetype2 --with_opt_include=/opt/local/include

$LDFLAGS += "  -lmapnik2 "

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

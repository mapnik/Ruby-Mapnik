
SHELL = /bin/sh

#### Start of system configuration section. ####

srcdir = ext/ruby_mapnik
topdir = /System/Library/Frameworks/Ruby.framework/Versions/1.8/usr/lib/ruby/1.8/universal-darwin10.0
hdrdir = $(topdir)
VPATH = $(srcdir):$(topdir):$(hdrdir)
exec_prefix = $(prefix)
prefix = $(DESTDIR)/System/Library/Frameworks/Ruby.framework/Versions/1.8/usr
sharedstatedir = $(prefix)/com
mandir = $(DESTDIR)/usr/share/man
psdir = $(docdir)
oldincludedir = $(DESTDIR)/usr/include
localedir = $(datarootdir)/locale
bindir = $(exec_prefix)/bin
libexecdir = $(exec_prefix)/libexec
sitedir = $(DESTDIR)/Library/Ruby/Site
htmldir = $(docdir)
vendorarchdir = $(vendorlibdir)/$(sitearch)
includedir = $(prefix)/include
infodir = $(DESTDIR)/usr/share/info
vendorlibdir = $(vendordir)/$(ruby_version)
sysconfdir = $(prefix)/etc
libdir = $(exec_prefix)/lib
sbindir = $(exec_prefix)/sbin
rubylibdir = $(libdir)/ruby/$(ruby_version)
docdir = $(datarootdir)/doc/$(PACKAGE)
dvidir = $(docdir)
vendordir = $(libdir)/ruby/vendor_ruby
datarootdir = $(prefix)/share
pdfdir = $(docdir)
archdir = $(rubylibdir)/$(arch)
sitearchdir = $(sitelibdir)/$(sitearch)
datadir = $(datarootdir)
localstatedir = $(prefix)/var
sitelibdir = $(sitedir)/$(ruby_version)

CC = gcc
LIBRUBY = $(LIBRUBY_SO)
LIBRUBY_A = lib$(RUBY_SO_NAME)-static.a
LIBRUBYARG_SHARED = -l$(RUBY_SO_NAME)
LIBRUBYARG_STATIC = -lruby

RUBY_EXTCONF_H = 
CFLAGS   =  -fno-common -arch i386 -arch x86_64 -g -Os -pipe -fno-common -DENABLE_DTRACE  -fno-common  -pipe -fno-common $(cflags) 
INCFLAGS = -I. -I. -I/System/Library/Frameworks/Ruby.framework/Versions/1.8/usr/lib/ruby/1.8/universal-darwin10.0 -Iext/ruby_mapnik
DEFS     = 
CPPFLAGS =  -I/opt/local/include/freetype2 -I/usr/local/include/freetype2 -I/usr/X11/include/freetype2 -I/System/Library/Frameworks/Ruby.framework/Versions/1.8/usr/include/freetype2 -I/usr/local/include/ -I/opt/local/include/ -I/System/Library/Frameworks/Ruby.framework/Versions/1.8/usr/include -I/usr/include/ -I/usr/X11/include -I/usr/include/mapnik/  -D_XOPEN_SOURCE -D_DARWIN_C_SOURCE   -arch x86_64 -I/Library/Ruby/Gems/1.8/gems/rice-1.4.2/ruby/lib/include
CXXFLAGS = $(CFLAGS)  -Wall -g
ldflags  = -L. -arch i386 -arch x86_64   -L/Library/Ruby/Gems/1.8/gems/rice-1.4.2/ruby/lib/lib  -lmapnik2  -all_load
dldflags = 
archflag = 
DLDFLAGS = $(ldflags) $(dldflags) $(archflag)
LDSHARED = g++ -arch i386 -arch x86_64 -pipe -bundle -undefined dynamic_lookup
AR = ar
EXEEXT = 

RUBY_INSTALL_NAME = ruby
RUBY_SO_NAME = ruby
arch = universal-darwin10.0
sitearch = universal-darwin10.0
ruby_version = 1.8
ruby = /System/Library/Frameworks/Ruby.framework/Versions/1.8/usr/bin/ruby
RUBY = $(ruby)
RM = rm -f
MAKEDIRS = mkdir -p
INSTALL = /usr/bin/install -c
INSTALL_PROG = $(INSTALL) -m 0755
INSTALL_DATA = $(INSTALL) -m 644
COPY = cp

#### End of system configuration section. ####

preload = 

CXX = g++
libpath = . $(libdir) /opt/local/lib /usr/local/lib /System/Library/Frameworks/Ruby.framework/Versions/1.8/usr/lib /usr/X11/lib /usr/lib
LIBPATH =  -L. -L$(libdir) -L/opt/local/lib -L/usr/local/lib -L/System/Library/Frameworks/Ruby.framework/Versions/1.8/usr/lib -L/usr/X11/lib -L/usr/lib
DEFFILE = 

CLEANFILES = mkmf.log
DISTCLEANFILES = 

extout = 
extout_prefix = 
target_prefix = 
LOCAL_LIBS = 
LIBS = -lrice -lruby -lpthread -ldl  
SRCS = _mapnik.cpp _mapnik_color.rb.cpp _mapnik_coord.rb.cpp _mapnik_datasource.rb.cpp _mapnik_datasource_cache.rb.cpp _mapnik_envelope.rb.cpp _mapnik_expression.rb.cpp _mapnik_feature.rb.cpp _mapnik_font_engine.rb.cpp _mapnik_geometry.rb.cpp _mapnik_layer.rb.cpp _mapnik_line_symbolizer.rb.cpp _mapnik_map.rb.cpp _mapnik_polygon_symbolizer.rb.cpp _mapnik_projection.rb.cpp _mapnik_rule.rb.cpp _mapnik_stroke.rb.cpp _mapnik_style.rb.cpp _mapnik_symbolizer.rb.cpp _mapnik_text_symbolizer.rb.cpp ruby_mapnik.cpp
OBJS = _mapnik.o _mapnik_color.rb.o _mapnik_coord.rb.o _mapnik_datasource.rb.o _mapnik_datasource_cache.rb.o _mapnik_envelope.rb.o _mapnik_expression.rb.o _mapnik_feature.rb.o _mapnik_font_engine.rb.o _mapnik_geometry.rb.o _mapnik_layer.rb.o _mapnik_line_symbolizer.rb.o _mapnik_map.rb.o _mapnik_polygon_symbolizer.rb.o _mapnik_projection.rb.o _mapnik_rule.rb.o _mapnik_stroke.rb.o _mapnik_style.rb.o _mapnik_symbolizer.rb.o _mapnik_text_symbolizer.rb.o ruby_mapnik.o
TARGET = ruby_mapnik
DLLIB = $(TARGET).bundle
EXTSTATIC = 
STATIC_LIB = 

BINDIR        = $(bindir)
RUBYCOMMONDIR = $(sitedir)$(target_prefix)
RUBYLIBDIR    = $(sitelibdir)$(target_prefix)
RUBYARCHDIR   = $(sitearchdir)$(target_prefix)

TARGET_SO     = $(DLLIB)
CLEANLIBS     = $(TARGET).bundle $(TARGET).il? $(TARGET).tds $(TARGET).map
CLEANOBJS     = *.o *.a *.s[ol] *.pdb *.exp *.bak

all:		$(DLLIB)
static:		$(STATIC_LIB)

clean:
		@-$(RM) $(CLEANLIBS) $(CLEANOBJS) $(CLEANFILES)

distclean:	clean
		@-$(RM) Makefile $(RUBY_EXTCONF_H) conftest.* mkmf.log
		@-$(RM) core ruby$(EXEEXT) *~ $(DISTCLEANFILES)

realclean:	distclean
install: install-so install-rb

install-so: $(RUBYARCHDIR)
install-so: $(RUBYARCHDIR)/$(DLLIB)
$(RUBYARCHDIR)/$(DLLIB): $(DLLIB)
	$(INSTALL_PROG) $(DLLIB) $(RUBYARCHDIR)
install-rb: pre-install-rb install-rb-default
install-rb-default: pre-install-rb-default
pre-install-rb: Makefile
pre-install-rb-default: Makefile
$(RUBYARCHDIR):
	$(MAKEDIRS) $@

site-install: site-install-so site-install-rb
site-install-so: install-so
site-install-rb: install-rb

.SUFFIXES: .c .m .cc .cxx .cpp .C .o

.cc.o:
	$(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) -c $<

.cxx.o:
	$(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) -c $<

.cpp.o:
	$(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) -c $<

.C.o:
	$(CXX) $(INCFLAGS) $(CPPFLAGS) $(CXXFLAGS) -c $<

.c.o:
	$(CC) $(INCFLAGS) $(CPPFLAGS) $(CFLAGS) -c $<

$(DLLIB): $(OBJS) Makefile
	@-$(RM) $@
	$(LDSHARED) -o $@ $(OBJS) $(LIBPATH) $(DLDFLAGS) $(LOCAL_LIBS) $(LIBS)



$(OBJS): ruby.h defines.h

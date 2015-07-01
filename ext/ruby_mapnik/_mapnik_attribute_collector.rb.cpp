/*****************************************************************************
Copyright (C) 2011 Elliot Laster

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
 *****************************************************************************/
#include "_mapnik_attribute_collector.rb.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>

// Mapnik
#include <mapnik/attribute_collector.hpp>

// stl
#include <set>


void register_attribute_collector(Rice::Module rb_mapnik){

  Rice::Data_Type< mapnik::attribute_collector > rb_cattribute_collector = Rice::define_class_under< mapnik::attribute_collector >(rb_mapnik, "AttributeCollector");

  //rb_cattribute_collector.define_constructor(Rice::Constructor< mapnik::attribute_collector,std::set<std::string> >());

  //rb_cattribute_collector.define_method("add_rule", &mapnik::attribute_collector::operator());

}
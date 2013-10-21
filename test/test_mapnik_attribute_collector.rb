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
require "test_helper"

class TestMapnikAttributeCollector < Test::Unit::TestCase

  def test_presence
    assert Mapnik::AttributeCollector
  end

  def test_should_instantiate
    assert Mapnik::AttributeCollector.new
  end

  def test_should_accept_rules
    attribute_collector = Mapnik::AttributeCollector.new
    assert attribute_collector.add_rule(Mapnik::Rule.new)
  end

  def test_should_give_attributes
    rule = Mapnik::Rule.new
    expression_string = "([place]='town')"
    expression = Mapnik::Expression.parse(expression_string)
    rule.filter = expression

    attribute_collector = Mapnik::AttributeCollector.new
    attribute_collector.add_rule(rule)

    assert_equal attribute_collector.attributes, ['place']
  end
end

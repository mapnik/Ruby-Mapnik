module YARD
  module Parser
    class GenericParser < CParser
      
      def initialize(source, file = '(stdin)')
        @file = file
        @namespaces = {}
        @content = clean_source(source)
      end
      
      def parse
        parse_modules
        parse_classes
        parse_methods
        # parse_constants
        # parse_includes
      end
      
      def parse_modules
        @content.scan(/@@Module_var\s*(\w+) = \s*(\w+)/) do |var_name, module_name|
          handle_module(var_name, module_name)
        end
      end
      
      def parse_classes
        @content.scan(/Data_Type< .+ >\s*(\w+)\s*=\s*.+define_class_under<.+>\(\s*(\w+),\s*"(\w+)"/) do |var_name, in_module, class_name|
          handle_class(var_name, class_name, nil, in_module)
        end
      end
      
      def parse_methods
        @content.scan(/(\w+)\.define_(method|singleton_method)\(\s*"(.+)",.+\)/) do |var_name, type, name|
          handle_method(type, var_name, name, nil, nil) unless nodoc?(name)
        end

        @content.scan(/(\w+)\.define_constructor\(.+\)/) do |var_name|
          handle_method("singleton_method", var_name.first, "new" , nil, nil)
        end
      end
      
      def nodoc?(name, content=@content)
        name == 'initialize' || content =~ %r{Dont-Document-method:\s#{name}}m
      end
      
      def find_method_body(object, func_name, content = @content)        
        # No body, but might still have an override comment
        comment = find_override_comment(object)
        object.docstring = parse_comments(object, comment) if comment
      end
      
      def find_override_comment(object, content = @content)
        name = Regexp.escape(object.name.to_s)
        class_name = object.parent.path
        if content =~ %r{Document-method:\s+#{class_name}(?:\.|::|#)#{name}\s*?\n((?>.*?\*/))}m then
          $1
        elsif content =~ %r{Document-method:\s#{name}\s*?\n((?>.*?\*/))}m then
          $1
        else
          nil
        end
      end
      
      # def clean_source(source)
      #   # source = handle_ifdefs_in(source)
      #   # source = handle_tab_width(source)
      #   # source = remove_commented_out_lines(source)
      #   source
      # end
      
    end
  end
end
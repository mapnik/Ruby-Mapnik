module YARD
  module Parser
    autoload :GenericParser, File.join(File.dirname(File.expand_path(__FILE__)), 'yard', 'parser', 'generic_parser')
    SourceParser.register_parser_type :generic, GenericParser, '*'

    # Highjack cpp to use the generic parser.
    class SourceParser
      def self.parser_type_for_extension(extension)
        if extension == 'cpp'
          :generic
        elsif extension == 'rb'
          validated_parser_type(:ruby)
        end
      end
    end
  end

end

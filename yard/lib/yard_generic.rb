module YARD
  module Parser
    autoload :GenericParser, File.join(File.dirname(File.expand_path(__FILE__)), 'yard', 'parser', 'generic_parser')
    SourceParser.register_parser_type :generic, GenericParser, '*'
    
    # Highjack everything!
    class SourceParser
      def self.parser_type_for_extension(extension)
        :generic
      end
    end
  end
    
end
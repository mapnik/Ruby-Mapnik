module Mapnik
  
  class FontEngine
    
    DEFAULT_VALID_EXTENSIONS = ['ttf','otf','ttc','pfa','pfb','ttc','dfont']
    
    def self.register_fonts(path, valid_extensions = DEFAULT_VALID_EXTENSIONS)
      file_names = Dir.glob(File.join("#{path}", "*.{#{valid_extensions.join(',')}}"))
      file_names.each{|filename| register_font(filename)} 
    end
    
  end
  
end
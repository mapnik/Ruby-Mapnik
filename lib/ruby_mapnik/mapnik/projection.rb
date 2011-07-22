module Mapnik
  class Projection
    
    def forward(obj)
      case
      when obj.class == Mapnik::Envelope
        __forward_env__(obj)
      when obj.class == Mapnik::Coord2d
        __forward_pt__(obj)
      end
    end
    
    def inverse(obj)
      case
      when obj.class == Mapnik::Envelope
        __inverse_env__(obj)
      when obj.class == Mapnik::Coord2d
        __inverse_pt__(obj)
      end
    end
    
    private :__forward_pt__, :__forward_env__, :__inverse_pt__, :__inverse_env__
    
  end
end
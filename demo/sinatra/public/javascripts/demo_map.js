function CoordMapType() {
}

CoordMapType.prototype.tileSize = new google.maps.Size(256,256);
CoordMapType.prototype.maxZoom = 19;

CoordMapType.prototype.getTile = function(coord, zoom, ownerDocument) {
  var div = ownerDocument.createElement('DIV');
  div.style.width = this.tileSize.width + 'px';
  div.style.height = this.tileSize.height + 'px';
  div.style.opacity = '1';
  div.style.backgroundImage = 'url(http://localhost:4567/tiles/' + zoom + '/' + coord.x + '/' + coord.y + '.png)';
  return div;
};

CoordMapType.prototype.name = "Tile #s";
CoordMapType.prototype.alt = "Tile Coordinate Map Type";

var map;
var chicago = new google.maps.LatLng(41.850033,-87.6500523);
var coordinateMapType = new CoordMapType();

function initialize() {
  var mapOptions = {
    zoom: 10,
    center: chicago// ,
    //     mapTypeId: google.maps.MapTypeId.ROADMAP
  };
  
  map = new google.maps.Map(document.getElementById("map_canvas"),
      mapOptions);
      
  // Now attach the coordinate map type to the map's registry
  map.mapTypes.set('coordinate', coordinateMapType);

  map.setMapTypeId('coordinate');

  // We can now set the map to use the 'coordinate' map type
  // map.overlayMapTypes.insertAt(0, new CoordMapType());
}

initialize();
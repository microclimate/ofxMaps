// =============================================================================
//
// Copyright (c) 2014 Christopher Baker <http://christopherbaker.net>
// Copyright (c) -2014 Tom Carden <https://github.com/RandomEtc>
// Created by Brad Rocheleau on 2/3/15.

//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================

#include "BaseMapProvider.h"
#include "MercatorProjection.h"

class MapBoxProvider: public BaseMapProvider
{
public:
    typedef std::shared_ptr<MapBoxProvider> SharedPtr;
    
    MapBoxProvider():
    
    BaseMapProvider(BaseProjection::SharedPtr(new MercatorProjection()))
    {
    }
    
    MapBoxProvider(string _access_token, string _mapId):
    
    BaseMapProvider(BaseProjection::SharedPtr(new MercatorProjection()))
    {
        access_token = _access_token;
        mapId = _mapId;
    }
    
    int getTileWidth() const
    {
        return 256;
    }
    
    int getTileHeight() const
    {
        return 256;
    }
    
    int getMinZoom() const
    {
        return 0;
    }
    
    int getMaxZoom() const
    {
        return 19;
    }
    
    std::vector<std::string> getTileUrls(const TileCoordinate& rawCoordinate) const
    {
        std::vector<std::string> urls;
        
        if (rawCoordinate.getRow() >= 0 && rawCoordinate.getRow() < pow(2, rawCoordinate.getZoom()))
        {
            TileCoordinate coordinate = TileCoordinate::normalizeTileCoordinate(rawCoordinate);
            
            std::stringstream url;
            
            if (mapId == "") {
                
                url << "https://api.tiles.mapbox.com/v4/mapbox.streets/";
                url << (int)coordinate.getZoom() << "/" << (int)coordinate.getColumn();
                url << "/" << (int)coordinate.getRow() << ".png";
                url << "?access_token=" << access_token << "&amp;update=i5pys";
                
            } else {
            
                url << "https://api.tiles.mapbox.com/v4/" << mapId << "/";
                url << (int)coordinate.getZoom() << "/" << (int)coordinate.getColumn();
                url << "/" << (int)coordinate.getRow() << ".png";
                url << "?access_token=" << access_token << "&amp;update=i5pys";
            
            }

            urls.push_back(url.str());
            
        }
        
        return urls;
    }
    
    static SharedPtr makeShared()
    {
        return SharedPtr(new MapBoxProvider());
    }
    
protected:
    
    string access_token = "pk.eyJ1IjoibWFwYm94IiwiYSI6IlhHVkZmaW8ifQ.hAMX5hSW-QnTeRCMAy9A8Q&update=i5shw";
    string mapId = "";
    
    
};

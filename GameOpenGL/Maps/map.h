#ifndef MAP_H
#define MAP_H
#include <GL/gl.h>
#include <GL/glu.h>
#include "Texture/texture.h"
#include <QString>
class Map
{
public:
    Map();
    void initMap();
    void paintMap();
    void setMap();
private:
    Texture m_textures;
};

#endif // MAP_H

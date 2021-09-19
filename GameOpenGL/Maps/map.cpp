#include "map.h"

Map::Map()
{
    initMap();
}

void Map::initMap()
{
    m_textures.setTexture(":/resources/texture/grass.png");
}

void Map::paintMap()
{
    //glTexCoord2f的第一个参数是X坐标。0.0是纹理的左侧。0.5是纹理的中点，1.0是纹理的右侧。
    //glTexCoord2f的第二个参数是Y坐标。0.0是纹理的底部。0.5是纹理的中点，1.0是纹理的顶部。
    glEnable(GL_STENCIL_TEST);
    glStencilOp(GL_KEEP, GL_REPLACE, GL_REPLACE);
    glStencilFunc(GL_ALWAYS, 1, 0xFF);

    glBindTexture(GL_TEXTURE_2D, m_textures.getTexture(2));
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f,0.5f);
    glVertex3f(-100.0f,-1.5f,-100.0f);
    glTexCoord2f(0.0f,0.5f);
    glVertex3f(-100.0f,-1.5f,100.0f);
    glTexCoord2f(1.0f,0.5f);
    glVertex3f(100.0f,-1.5f,-100.0f);
    glTexCoord2f(1.0f,0.5f);
    glVertex3f(100.0f,-1.5f,100.0f);

    glTexCoord2f(0.0f,0.5f);
    glVertex3f(-100.0f,-1.5f,-100.0f);
    glTexCoord2f(0.0f,0.5f);
    glVertex3f(-100.0f,-1.5f,0.0f);
    glTexCoord2f(1.0f,0.5f);
    glVertex3f(100.0f,-1.5f,-100.0f);
    glTexCoord2f(1.0f,0.5f);
    glVertex3f(100.0f,-1.5f,0.0f);

    glTexCoord2f(0.0f,0.5f);
    glVertex3f(-100.0f,-1.5f,-100.0f);
    glTexCoord2f(0.0f,0.5f);
    glVertex3f(-100.0f,-1.5f,50.0f);
    glTexCoord2f(1.0f,0.5f);
    glVertex3f(100.0f,-1.5f,-100.0f);
    glTexCoord2f(1.0f,0.5f);
    glVertex3f(100.0f,-1.5f,50.0f);

    glEnd();
}

void Map::setMap()
{

}

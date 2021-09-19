#ifndef TEXTURE_H
#define TEXTURE_H
#include <QString>
#include <qgl.h>
#include <QtOpenGL/QtOpenGL>
#include <gl/glu.h>
class Texture
{
public:
    Texture();
    void setTexture(const QString ImagePath);
    GLuint getTexture(int index);
private:
    GLuint texture[4];
};

#endif // TEXTURE_H

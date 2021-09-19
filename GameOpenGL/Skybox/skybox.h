#ifndef SKYBOX_H
#define SKYBOX_H

#include <GL/gl.h>
#include <GL/glu.h>
#include "Texture/texture.h"
#include <QString>
class QImage;

class SkyBox
{
public:
    SkyBox();
    void draw();
    void Init();
protected:
    GLuint CreateTexture2DFromBMP(const char*bmpPath);
    unsigned char * LoadFileContent(const char *path, int &filesize);
    unsigned char *DecodeBMP(unsigned char*bmpFileData, int&width, int&height);

    GLuint createTexture2D(unsigned char *piexlData, int width, int height, GLenum type);
private:
    Texture m_textures[6];

};

#endif // SKYBOX_H

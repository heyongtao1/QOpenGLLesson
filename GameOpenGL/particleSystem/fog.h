#ifndef FOG_H
#define FOG_H

#include <qgl.h>
#include <QtOpenGL/QtOpenGL>
#include <gl/glu.h>
class Fog
{
public:
    Fog();
    void initFog();
    void setFogFilter(GLuint fogFilter);
    GLuint getFogFilter();
    GLuint getFogMode(int index);
    //设置雾的密度
    void setFogDensity(GLfloat fogdensity);
private:
    GLuint mfogFilter;
    GLfloat mfogdensity;
    //雾到视口的距离
    GLfloat mfogdistance;
    GLuint fogMode[3] = { GL_EXP, GL_EXP2, GL_LINEAR };
    GLfloat fogColor[4] = { 0.5, 0.5, 0.5, 1.0 };
};

#endif // FOG_H

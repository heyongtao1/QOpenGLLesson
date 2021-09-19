#ifndef LIGHT_H
#define LIGHT_H

#include <qgl.h>
#include <QtOpenGL/QtOpenGL>
#include <gl/glu.h>

class Light
{
public:
    Light();
    void setLightEnable(bool enable);
    void initLight();
    bool getLight();
private:
    bool light;
};

#endif // LIGHT_H

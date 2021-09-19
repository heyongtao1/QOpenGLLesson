#include "light.h"
GLfloat lightAmbient[4] = { 0.2, 0.4, 0.6, 1.0 };//环境光
GLfloat lightDiffuse[4] = { 1.0, 1.0, 1.0, 1.0 };//漫射光
GLfloat lightPosition[4] = { 0.0, 0.0, 2.0, 1.0 };//光的位置
Light::Light()
{
    light = false;
}

void Light::setLightEnable(bool enable)
{
    light = enable;
}

void Light::initLight()
{
    glLightfv( GL_LIGHT1, GL_AMBIENT, lightAmbient );
    glLightfv( GL_LIGHT1, GL_DIFFUSE, lightDiffuse );
    glLightfv( GL_LIGHT1, GL_POSITION, lightPosition );
    glEnable( GL_LIGHT1 );
}

bool Light::getLight()
{
    return light;
}

#include "fog.h"
Fog::Fog()
{
    mfogFilter = 0;
    mfogdistance = 1.0;
}

void Fog::initFog()
{
    glFogi( GL_FOG_MODE, fogMode[mfogFilter] );
    glFogfv( GL_FOG_COLOR, fogColor );
    //密度
    glFogf( GL_FOG_DENSITY, mfogdensity );
    glHint( GL_FOG_HINT, GL_DONT_CARE );
    //距离
    glFogf( GL_FOG_START, mfogdistance );
    glFogf( GL_FOG_END, 5.0 );
    glEnable( GL_FOG );
}

void Fog::setFogFilter(GLuint fogFilter)
{
    mfogFilter = fogFilter;
}

GLuint Fog::getFogFilter()
{
    return mfogFilter;
}

GLuint Fog::getFogMode(int index)
{
    return fogMode[index];
}

void Fog::setFogDensity(GLfloat fogdensity)
{
    mfogdensity = fogdensity;
}

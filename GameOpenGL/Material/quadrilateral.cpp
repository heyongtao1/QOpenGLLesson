#include "quadrilateral.h"

OrdinaryQuadrilateral::OrdinaryQuadrilateral()
{
    mTexture = 0;
}

void OrdinaryQuadrilateral::paintMaterial()
{
    //setglTranslatef();
    //绑定纹理
    bindTexture();
    glBegin( GL_QUADS );
    setQuadrilateralCube();
    glEnd();
}

void OrdinaryQuadrilateral::setQuadrilateralCube()
{
    //glTexCoord2f( 0.0, 0.0 )渲染纹理
    glTexCoord2f( 0.0, 0.0 );setVertexPos( -1.0, -1.0,  1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 1.0, 0.0 );setVertexPos(  1.0, -1.0,  1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 1.0, 1.0 );setVertexPos(  1.0,  1.0,  1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 0.0, 1.0 );setVertexPos( -1.0,  1.0,  1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);

    glTexCoord2f( 1.0, 0.0 );setVertexPos( -1.0, -1.0, -1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 1.0, 1.0 );setVertexPos( -1.0,  1.0, -1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 0.0, 1.0 );setVertexPos(  1.0,  1.0, -1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 0.0, 0.0 );setVertexPos(  1.0, -1.0, -1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);

    glTexCoord2f( 0.0, 1.0 );setVertexPos( -1.0,  1.0, -1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 0.0, 0.0 );setVertexPos( -1.0,  1.0,  1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 1.0, 0.0 );setVertexPos(  1.0,  1.0,  1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 1.0, 1.0 );setVertexPos(  1.0,  1.0, -1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);

    glTexCoord2f( 1.0, 1.0 );setVertexPos( -1.0, -1.0, -1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 0.0, 1.0 );setVertexPos(  1.0, -1.0, -1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 0.0, 0.0 );setVertexPos(  1.0, -1.0,  1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 1.0, 0.0 );setVertexPos( -1.0, -1.0,  1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);

    glTexCoord2f( 1.0, 0.0 );setVertexPos(  1.0, -1.0, -1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 1.0, 1.0 );setVertexPos(  1.0,  1.0, -1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 0.0, 1.0 );setVertexPos(  1.0,  1.0,  1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 0.0, 0.0 );setVertexPos(  1.0, -1.0,  1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);

    glTexCoord2f( 0.0, 0.0 );setVertexPos( -1.0, -1.0, -1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 1.0, 0.0 );setVertexPos( -1.0, -1.0,  1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 1.0, 1.0 );setVertexPos( -1.0,  1.0,  1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
    glTexCoord2f( 0.0, 1.0 );setVertexPos( -1.0,  1.0, -1.0 ); glVertex3f(mfloat.x,  mfloat.y, mfloat.z);
}

void OrdinaryQuadrilateral::setScalingFactor(float scalingfactor)
{
    mScalingFactor = scalingfactor;
}

void OrdinaryQuadrilateral::setglTranslatef()
{
    glTranslatef(mCenterPos.x,mCenterPos.y,mCenterPos.z);
}

void OrdinaryQuadrilateral::setCenterPos(GLfloat x, GLfloat y, GLfloat z)
{
    mCenterPos.x = x;
    mCenterPos.y = y;
    mCenterPos.z = z;
}

void OrdinaryQuadrilateral::setVertexPos(GLfloat x, GLfloat y, GLfloat z)
{
    mfloat.x = x*mScalingFactor;
    mfloat.y = y*mScalingFactor;
    mfloat.z = z*mScalingFactor;
}

void OrdinaryQuadrilateral::setTexture(GLuint gltexture)
{
    mTexture = gltexture;
}

void OrdinaryQuadrilateral::bindTexture()
{
    if(mTexture){
        qDebug()<<"quad " << mTexture;
        glBindTexture( GL_TEXTURE_2D, mTexture);
    }
}

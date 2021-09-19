#include "triangle.h"

OrdinaryTriangle::OrdinaryTriangle()
{
    mTexture = 0;
}

void OrdinaryTriangle::paintMaterial()
{
    //原点坐标的转换
    setglTranslatef();
    //绑定纹理
    bindTexture();
    //开始绘制三角形立方体
    glBegin( GL_TRIANGLES );
    setTriangleCube();
    //绘制结束
    glEnd();
}

void OrdinaryTriangle::setTriangleCube()
{
    //glTexCoord2f的第一个参数是X坐标。0.0是纹理的左侧。0.5是纹理的中点，1.0是纹理的右侧。
    //glTexCoord2f的第二个参数是Y坐标。0.0是纹理的底部。0.5是纹理的中点，1.0是纹理的顶部。
    glTexCoord2f( 0.5, 1.0 );setVertexPos(  0.0,  1.0,  0.0 );glVertex3f(mfloat.x,mfloat.y,mfloat.z);
    glTexCoord2f( 0.5, 1.0 );setVertexPos(  -1.0, -1.0, 1.0 );glVertex3f(mfloat.x,mfloat.y,mfloat.z);
    glTexCoord2f( 1.0, 0.0 );setVertexPos(  1.0, -1.0,  1.0 );glVertex3f(mfloat.x,mfloat.y,mfloat.z);

    glTexCoord2f( 0.5, 1.0 );setVertexPos(  0.0,  1.0,  0.0 );glVertex3f(mfloat.x,mfloat.y,mfloat.z);
    glTexCoord2f( 1.0, 0.0 );setVertexPos(  1.0, -1.0,  1.0 );glVertex3f(mfloat.x,mfloat.y,mfloat.z);
    glTexCoord2f( 1.0, 0.0 );setVertexPos(  1.0, -1.0, -1.0 );glVertex3f(mfloat.x,mfloat.y,mfloat.z);


    glTexCoord2f( 0.5, 1.0 );setVertexPos(  0.0,  1.0,  0.0 );glVertex3f(mfloat.x,mfloat.y,mfloat.z);
    glTexCoord2f( 1.0, 0.0 );setVertexPos(  1.0, -1.0, -1.0 );glVertex3f(mfloat.x,mfloat.y,mfloat.z);
    glTexCoord2f( 0.0, 0.0 );setVertexPos( -1.0, -1.0, -1.0 );glVertex3f(mfloat.x,mfloat.y,mfloat.z);


    glTexCoord2f( 0.5, 1.0 );setVertexPos(  0.0,  1.0,  0.0 );glVertex3f(mfloat.x,mfloat.y,mfloat.z);
    glTexCoord2f( 0.0, 0.0 );setVertexPos( -1.0, -1.0, -1.0 );glVertex3f(mfloat.x,mfloat.y,mfloat.z);
    glTexCoord2f( 0.0, 0.0 );setVertexPos( -1.0, -1.0,  1.0 );glVertex3f(mfloat.x,mfloat.y,mfloat.z);
}

void OrdinaryTriangle::setScalingFactor(float scalingfactor)
{
    mScalingFactor = scalingfactor;
}

void OrdinaryTriangle::setglTranslatef()
{
    glTranslatef(mCenterPos.x,mCenterPos.y,mCenterPos.z);
}

void OrdinaryTriangle::setCenterPos(GLfloat x,GLfloat y,GLfloat z)
{
    mCenterPos.x = x;
    mCenterPos.y = y;
    mCenterPos.z = z;
}

void OrdinaryTriangle::setVertexPos(GLfloat x, GLfloat y, GLfloat z)
{
    mfloat.x = x*mScalingFactor;
    mfloat.y = y*mScalingFactor;
    mfloat.z = z*mScalingFactor;
}

void OrdinaryTriangle::setTexture(GLuint gltexture)
{
    mTexture = gltexture;
}

void OrdinaryTriangle::bindTexture()
{
    if(mTexture)
    glBindTexture( GL_TEXTURE_2D, mTexture);
}

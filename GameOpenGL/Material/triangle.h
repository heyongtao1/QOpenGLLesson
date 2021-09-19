#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "material.h"

class Triangle : public Material
{
public:
    virtual void paintMaterial()=0;
    virtual void setTriangleCube()=0;
    virtual void setScalingFactor(float scalingfactor)=0;
    virtual void setglTranslatef()=0;
    virtual void setCenterPos(GLfloat x,GLfloat y,GLfloat z)=0;
    virtual void setVertexPos(GLfloat x,GLfloat y,GLfloat z)=0;
    virtual void setTexture(GLuint gltexture)=0;
    virtual void bindTexture()=0;
};

class OrdinaryTriangle : public Triangle
{
public:
    OrdinaryTriangle();
    void paintMaterial();
    void setTriangleCube();
    void setScalingFactor(float scalingfactor);
    void setglTranslatef();
    void setCenterPos(GLfloat x,GLfloat y,GLfloat z);
    void setVertexPos(GLfloat x,GLfloat y,GLfloat z);
    void setTexture(GLuint gltexture);
    void bindTexture();
private:
    float mScalingFactor;
    MGLfloat mfloat;
};

#endif // TRIANGLE_H

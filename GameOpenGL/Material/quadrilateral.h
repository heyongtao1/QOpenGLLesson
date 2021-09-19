#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H
#include "material.h"

class Quadrilateral : public Material
{
public:
    virtual void paintMaterial()=0;
    virtual void setQuadrilateralCube()=0;
    virtual void setScalingFactor(float scalingfactor)=0;
    virtual void setglTranslatef()=0;
    virtual void setCenterPos(GLfloat x,GLfloat y,GLfloat z)=0;
    virtual void setVertexPos(GLfloat x,GLfloat y,GLfloat z)=0;
    virtual void setTexture(GLuint gltexture)=0;
    virtual void bindTexture()=0;
};

class OrdinaryQuadrilateral : public Quadrilateral
{
public:
     OrdinaryQuadrilateral();
     void paintMaterial();
     void setQuadrilateralCube();
     void setScalingFactor(float scalingfactor);
     void setglTranslatef();
     void setCenterPos(GLfloat x,GLfloat y,GLfloat z);
     void setVertexPos(GLfloat x,GLfloat y,GLfloat z);
     void setTexture(GLuint gltexture);
     void bindTexture();
};

#endif // QUADRILATERAL_H

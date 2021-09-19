#ifndef MATERIAL_H
#define MATERIAL_H
#include <qgl.h>
#include <QtOpenGL/QtOpenGL>
#include <gl/glu.h>

typedef struct{
    GLfloat x;
    GLfloat y;
    GLfloat z;
}CenterPos;

typedef struct{
    GLfloat x;
    GLfloat y;
    GLfloat z;
}MGLfloat;
class Material
{
public:
    Material();
    //绘制材质
    virtual void paintMaterial()=0;
    //设置缩放系数
    virtual void setScalingFactor(float scalingfactor)=0;
    //设置中心位置
    virtual void setCenterPos(GLfloat x,GLfloat y,GLfloat z)=0;
    //设置坐标转换
    virtual void setglTranslatef()=0;
    //设置顶点坐标
    virtual void setVertexPos(GLfloat x,GLfloat y,GLfloat z)=0;
    //设置纹理
    virtual void setTexture(GLuint gltexture)=0;
    //绑定纹理
    virtual void bindTexture()=0;
public:
    //缩放系数
    float mScalingFactor;
    //自定义坐标结构体
    MGLfloat mfloat;
    //中心坐标
    CenterPos mCenterPos;
    //纹理
    GLuint mTexture;
};

#endif // MATERIAL_H

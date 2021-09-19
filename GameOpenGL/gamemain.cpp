/*

    Qt OpenGL Tutorial - Lesson 01

    GameMain.cpp
    v 1.00
    2002/12/05

    Copyright (C) 2002 Cavendish
                       cavendish@qiliang.net
                       http://www.qiliang.net/nehe_qt

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

*/

#include "gamemain.h"
#include <QKeyEvent>
#include <QVector3D>
//摄像头参数
QVector3D cameraPos(0.0f, 0.0f,  2.0f);//摄像头位置
QVector3D cameraFront(0.0f, 0.0f, -1.0f);//观察者的位置
QVector3D cameraUp(0.0f, 1.0f,  0.0f);//向上向量

float deltaTime = 0.0f; // 当前帧与上一帧的时间差
float lastFrame = 0.0f; // 上一帧的时间

GameMain::GameMain( QWidget* parent, const char* name, bool fs )
    : QGLWidget( parent)
    , yaw(0)
    , pitch(0)
    , sensitivity(0.002f)
{

  fullscreen = fs;
  setGeometry( 100, 100, 640, 480 );
  //setCaption( "NeHe's OpenGL Framework" );
  if ( fullscreen )
    showFullScreen();
}

GameMain::~GameMain()
{
}

void GameMain::initializeGL()
{
  //设置纹理
  mtexture.setTexture(":/resources/texture/grass.png");
  moodtexture.setTexture(":/resources/texture/grass.png");
  //启用纹理
  glEnable( GL_TEXTURE_2D );

  glShadeModel( GL_SMOOTH );//启用阴影平滑
  glClearColor( 0.5, 0.5, 0.5, 1.0 );
  glClearDepth( 1.0 );      //设置深度缓存
  glEnable( GL_DEPTH_TEST );//启用深度测试
  glDepthFunc( GL_LEQUAL ); //所作深度测试的类型
  glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );//告诉系统对透视进行修正

  mskybox.Init();
  mmap.initMap();
  mlight.initLight();
  mfog.setFogDensity(0.35);
  mfog.initFog();
}
void GameMain::lookAt(QVector3D mcameraPos, QVector3D posFront, QVector3D cameraUp)
{
    gluLookAt(mcameraPos.x(), mcameraPos.y(), mcameraPos.z(), posFront.x(), posFront.y(), posFront.z(), cameraUp.x(), cameraUp.y(), cameraUp.z());
}

void GameMain::paintGL()
{
  glLoadIdentity();
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  //绘制天空盒
  mskybox.draw();

  glClearDepth( 1.0 );      //设置深度缓存
  glEnable( GL_DEPTH_TEST );//启用深度测试
  glDepthFunc( GL_LEQUAL ); //所作深度测试比较的类型
  //更新摄像头转向
  lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
  //绘制简单地图
  mmap.paintMap();

  mtriangle.setCenterPos(-1.5,0.0,-3.0);
  mtriangle.setTexture(moodtexture.getTexture(2));
  mtriangle.setScalingFactor(1.0);
  mtriangle.paintMaterial();

  glLoadIdentity();
  lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

  mquad.setCenterPos(1.5,0.0,-4.0);
  mquad.setTexture(mtexture.getTexture(2));
  mquad.setScalingFactor(1.0);
  mquad.paintMaterial();
}
//重置OpenGL窗口的大小
void GameMain::resizeGL( int width, int height )
{
  if ( height == 0 )
  {
    height = 1;
  }
  glViewport( 0, 0, (GLint)width, (GLint)height );//重置当前的视口
  glMatrixMode( GL_PROJECTION );//选择投影矩阵
  glLoadIdentity();//重置投影矩阵
  gluPerspective( 45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0 );//设置视口的大小
  glMatrixMode( GL_MODELVIEW );//选择模型观察矩阵
  glLoadIdentity();//重置模型观察矩阵
}

void GameMain::keyPressEvent( QKeyEvent *e )
{
  float cameraSpeed = 0.1f;
  switch ( e->key() )
  {
  case Qt::Key_F2:
    fullscreen = !fullscreen;
    if ( fullscreen )
    {
      showFullScreen();
    }
    else
    {
      showNormal();
      setGeometry( 0, 0, 640, 480 );
    }
    updateGL();
    break;
  case Qt::Key_L:
    mlight.setLightEnable(!mlight.getLight());
    if (!mlight.getLight())
    {
      glDisable( GL_LIGHTING );
    }
    else
    {
      glEnable( GL_LIGHTING );
    }
    updateGL();
    break;
  case Qt::Key_G:
    mfog.setFogFilter(mfog.getFogFilter()+1);;
    if ( mfog.getFogFilter() > 2 )
    {
      mfog.setFogFilter(0);
    }
    glFogi( GL_FOG_MODE, mfog.getFogMode(mfog.getFogFilter()));
    updateGL();
    break;
  case Qt::Key_Escape:
    close();
  case Qt::Key_A:
    //mdirection.LR++;updateGL();break;
      cameraPos -= QVector3D::crossProduct(cameraFront,cameraUp)*cameraSpeed;;updateGL();break;
  case Qt::Key_D:
    //mdirection.LR--;updateGL();break;
      cameraPos += QVector3D::crossProduct(cameraFront, cameraUp) * cameraSpeed;updateGL();break;
  case Qt::Key_W:
    //mdirection.UD--;updateGL();break;
      cameraPos += cameraSpeed * cameraFront;updateGL();break;
  case Qt::Key_S:
    //mdirection.UD++;updateGL();break;
      cameraPos -= cameraSpeed * cameraFront;updateGL();break;
  case Qt::Key_Up:

      updateGL();break;
  case Qt::Key_Left:

      updateGL();break;
  case Qt::Key_Right:

      updateGL();break;
  case Qt::Key_Down:

      updateGL();break;
  }
}

void GameMain::mouseMoveEvent(QMouseEvent *e)
{
    qDebug()<<"move";
    float xoffset = e->pos().x() - this->rect().center().x();
    float yoffset = this->rect().center().y() - e->pos().y(); // 注意这里是相反的，因为y坐标是从底部往顶部依次增大的
    xoffset *= sensitivity;
    yoffset *= sensitivity;
    yaw   += xoffset;
    pitch += yoffset;
    if(pitch > 1.55)         //将俯视角限制到[-89°,89°]，89°约等于1.55
        pitch =  1.55;
    if(pitch < -1.55)
        pitch = -1.55;
    cameraFront.setX(cos(yaw)*cos(pitch));
    cameraFront.setY(sin(pitch));
    cameraFront.setZ(sin(yaw)*cos(pitch));
    QCursor::setPos(this->geometry().center());
    updateGL();
}

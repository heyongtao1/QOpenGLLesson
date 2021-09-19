/*

    Qt OpenGL Tutorial - Lesson 01

    nehewidget.h
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

#ifndef NEHEWIDGET_H
#define NEHEWIDGET_H

#include "Material/triangle.h"
#include "Material/quadrilateral.h"
#include "Texture/texture.h"
#include "particleSystem/light.h"
#include "particleSystem/fog.h"
#include "Skybox/skybox.h"
#include "Maps/map.h"
class GameMain : public QGLWidget
{
    Q_OBJECT

public:

  GameMain( QWidget* parent = 0, const char* name = 0, bool fs = false );
  ~GameMain();
  void lookAt(QVector3D mcameraPos, QVector3D posFront,QVector3D cameraUp);
protected:
  void initializeGL();
  void paintGL();
  void resizeGL( int width, int height );
  void keyPressEvent( QKeyEvent *e );
  void mouseMoveEvent(QMouseEvent *e);
  //virtual bool event(QEvent *e) override;
protected:

  bool fullscreen;
private:
  OrdinaryTriangle mtriangle;
  OrdinaryQuadrilateral mquad;
  Texture mtexture;
  Texture moodtexture;
  Light mlight;
  Fog mfog;
  SkyBox mskybox;
  Map mmap;
  //摄像头参数
  float yaw;                  //偏航角
  float pitch;                //俯视角
  float sensitivity;          //鼠标灵敏度
};

#endif//NEHEWIDGET_H

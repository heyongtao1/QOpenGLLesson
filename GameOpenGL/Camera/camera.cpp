
#include "camera.h"
#include <QDebug>
Camera::Camera(QGLWidget *widget)
    : widget(widget)
    , yaw(0)
    , pitch(0)
    , sensitivity(0.005f)
    , cameraPos(-5.0f,0.0f,0.0f)
    , cameraDirection(cos(yaw)*cos(pitch), sin(pitch), sin(yaw)*cos(pitch))
    , cameraRight(QVector3D::crossProduct({0.0f,1.0f,0.0f},cameraDirection))
    , cameraUp(QVector3D::crossProduct(cameraDirection,cameraRight))
    , moveSpeed(0.1f)
    , timeId(0)
    , deltaTime(1.0)
{
}

float Camera::getMoveSpeed() const
{
    return moveSpeed;
}

void Camera::setMoveSpeed(float value)
{
    moveSpeed = value;
}

float Camera::getSensitivity() const
{
    return sensitivity;
}

void Camera::setSensitivity(float value)
{
    sensitivity = value;
}

float Camera::getYaw() const
{
    return yaw;
}

void Camera::setYaw(float value)
{
    yaw = value;
}

float Camera::getPitch() const
{
    return pitch;
}

void Camera::setPitch(float value)
{
    pitch = value;
}

QVector3D Camera::getCameraPos() const
{
    return cameraPos;
}

void Camera::setCameraPos(const QVector3D &value)
{
    cameraPos = value;
}

QVector3D Camera::getCameraDirection() const
{
    return cameraDirection;
}

QVector3D Camera::getCameraUp() const
{
    return cameraUp;
}

void Camera::handle(QEvent *e)
{
    if(e->type()==QEvent::MouseMove){
        QMouseEvent *event=static_cast<QMouseEvent*>(e);
        float xoffset = event->x() - widget->rect().center().x();
        float yoffset = widget->rect().center().y() - event->y(); // 注意这里是相反的，因为y坐标是从底部往顶部依次增大的
        xoffset *= sensitivity;
        yoffset *= sensitivity;
        yaw   += xoffset;
        pitch += yoffset;
        if(pitch > 1.55)         //将俯视角限制到[-89°,89°]，89°约等于1.55
            pitch =  1.55;
        if(pitch < -1.55)
            pitch = -1.55;
        cameraDirection.setX(cos(yaw)*cos(pitch));
        cameraDirection.setY(sin(pitch));
        cameraDirection.setZ(sin(yaw)*cos(pitch));
        //QCursor::setPos(widget->geometry().center());       //将鼠标移动窗口中央
        widget->updateGL();
    }
    else if(e->type()==QEvent::KeyPress){
        qDebug()<<"keypress";
        float cameraSpeed = moveSpeed;
        QKeyEvent *event=static_cast<QKeyEvent*>(e);
        if (event->key() == Qt::Key_W)                             //前
            cameraPos+=cameraSpeed * cameraDirection;
        if (event->key() == Qt::Key_S)                           //后
            cameraPos -= cameraSpeed * cameraDirection;
        if (event->key() == Qt::Key_A)                           //左
            cameraPos-=QVector3D::crossProduct(cameraDirection,cameraUp)*cameraSpeed;
        if (event->key() == Qt::Key_D)                           //右
            cameraPos+=QVector3D::crossProduct(cameraDirection,cameraUp)*cameraSpeed;
        if (event->key() == Qt::Key_Space)                       //上浮
            cameraPos.setY(cameraPos.y()+cameraSpeed);
        if (event->key() == Qt::Key_Shift)                       //下沉
            cameraPos.setY(cameraPos.y()-cameraSpeed);
        widget->updateGL();
    }

}

void Camera::init()
{
    //view.lookAt(cameraPos,cameraPos+cameraDirection,cameraUp);
    //widget->activateWindow();                 //激活窗口
    //widget->setFocus();

}

#include "texture.h"

Texture::Texture()
{

}

void Texture::setTexture(const QString ImagePath)
{
    QImage tex, buf;
    if ( !buf.load(ImagePath) )
    {
      qWarning( "Could not read image file, using single-color instead." );
      QImage dummy;
      dummy.fill( Qt::green );
      buf = dummy;
    }
    tex = QGLWidget::convertToGLFormat( buf );
    //创建3个纹理
    glGenTextures( 4, texture );
    //第一种纹理放在texture[0]
    glBindTexture( GL_TEXTURE_2D, texture[0] );
    glTexImage2D( GL_TEXTURE_2D, 0, 3, tex.width(), tex.height(), 0,
        GL_RGBA, GL_UNSIGNED_BYTE, tex.bits() );

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    //第二种纹理
    glBindTexture( GL_TEXTURE_2D, texture[1] );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexImage2D( GL_TEXTURE_2D, 0, 3, tex.width(), tex.height(), 0,
        GL_RGBA, GL_UNSIGNED_BYTE, tex.bits() );

    //第三种纹理：高质量纹理
    glBindTexture( GL_TEXTURE_2D, texture[2] );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );
    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, tex.width(), tex.height(), GL_RGBA, GL_UNSIGNED_BYTE, tex.bits() );

    //第四种纹理
    glBindTexture( GL_TEXTURE_2D, texture[3] );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    /** 创建纹理 */
    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, tex.width(), tex.height(), GL_RGBA, GL_UNSIGNED_BYTE, tex.bits() );
}

GLuint Texture::getTexture(int index)
{
    return texture[index];
}

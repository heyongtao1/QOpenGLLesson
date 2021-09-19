#include "skybox.h"
#include <QImage>
#include <QDebug>
#include <QFile>

SkyBox::SkyBox()
{

}

void SkyBox::draw()
{
    //glTexCoord2f的第一个参数是X坐标。0.0是纹理的左侧。0.5是纹理的中点，1.0是纹理的右侧。
    //glTexCoord2f的第二个参数是Y坐标。0.0是纹理的底部。0.5是纹理的中点，1.0是纹理的顶部。
    //关闭深度测试
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, m_textures[0].getTexture(3));
    glBegin(GL_QUADS);
    glColor4ub(255,255,255,255);
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(-0.1f,-0.1f,-0.1f);
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(0.1f,-0.1f,-0.1f);
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(0.1f,0.1f,-0.1f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(-0.1f,0.1f,-0.1f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, m_textures[1].getTexture(3));
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(1.5f,-1.5f,1.5f);
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(-1.5f,-1.5f,1.5f);
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(-1.5f,1.5f,1.5f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(1.5f,1.5f,1.5f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, m_textures[2].getTexture(2));
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(-1.5f,-1.5f,1.5f);
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(-1.5f,-1.5f,-1.5f);
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(-1.5f,1.5f,-1.5f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(-1.5f,1.5f,1.5f);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, m_textures[3].getTexture(2));
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(1.5f,-1.5f,-1.5f);
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(1.5f,-1.5f,1.5f);
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(1.5f,1.5f, 1.5f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(1.5f,1.5f,-1.5f);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, m_textures[4].getTexture(2));
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(-1.5f,1.5f,-1.5f);
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(1.5f,1.5f,-1.5f);
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(1.5f,1.5f,1.5f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(-1.5f,1.5f,1.5f);
    glEnd();
    glBindTexture(GL_TEXTURE_2D,m_textures[5].getTexture(2));
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(-1.5f,-1.5f,1.5f);
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(1.5f,-1.5f,1.5f);
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(1.5f,-1.5f,-1.5f);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(-1.5f,-1.5f,-1.5f);
    glEnd();
}

void SkyBox::Init()
{

    m_textures[0].setTexture(":/resources/Skybox/01.tif");
    m_textures[1].setTexture(":/resources/Skybox/02.tif");
    m_textures[2].setTexture(":/resources/Skybox/03.tif");
    m_textures[3].setTexture(":/resources/Skybox/04.tif");
    m_textures[4].setTexture(":/resources/Skybox/05.jpg");
    m_textures[5].setTexture(":/resources/Skybox/06.jpg");
    /*
    m_textures[0]=CreateTexture2DFromBMP(":/resources/Skybox/01.tif");
    m_textures[1]=CreateTexture2DFromBMP(":/resources/Skybox/02.tif");
    m_textures[2]=CreateTexture2DFromBMP(":/resources/Skybox/03.tif");
    m_textures[3]=CreateTexture2DFromBMP(":/resources/Skybox/04.tif");
    m_textures[4]=CreateTexture2DFromBMP(":/resources/Skybox/05.jpg");
    m_textures[5]=CreateTexture2DFromBMP(":/resources/Skybox/06.jpg");
    */
}

GLuint SkyBox::CreateTexture2DFromBMP(const char *bmpPath)
{
    int nFileSize=0;
    unsigned char *bmpFileContent=LoadFileContent(bmpPath,nFileSize);
    if (bmpFileContent==nullptr){
        return 0;
    }
    int bmpWidth=0,bmpHeight=0;
    unsigned char*pixelData=DecodeBMP(bmpFileContent,bmpWidth,bmpHeight);
    if (bmpWidth==0){
        delete bmpFileContent;
        return 0;
    }
    GLuint texture=createTexture2D(pixelData,bmpWidth,bmpHeight,GL_RGB);
    delete bmpFileContent;
    return texture;
}

unsigned char *SkyBox::LoadFileContent(const char *path,int &filesize)
{
    unsigned char*fileContent=nullptr;
    filesize=0;
    FILE*pFile=fopen(path,"rb");
    if(pFile){
        fseek(pFile,0,SEEK_END);
        int nLen=ftell(pFile);
        if(nLen>0){
            rewind(pFile);
            fileContent=new unsigned char[nLen + 1];
            fread(fileContent,sizeof(unsigned char),nLen,pFile);
            fileContent[nLen] ='\0';
            filesize=nLen;
        }
        fclose(pFile);
    }
    return fileContent;
}

unsigned char *SkyBox::DecodeBMP(unsigned char *bmpFileData,int &width,int &height)
{
    if (0x4D42==*((unsigned short*)bmpFileData)){
        int pixelDataOffset=*((int*)(bmpFileData+10));
        width=*((int*)(bmpFileData+18));
        height=*((int*)(bmpFileData+22));
        unsigned char*pixelData=bmpFileData+pixelDataOffset;
        for (int i=0;i<width*height*3;i+=3){
            unsigned char temp=pixelData[i];
            pixelData[i]=pixelData[i+2];
            pixelData[i+2]=temp;
        }
        return pixelData;
    }
    return nullptr;
}

GLuint SkyBox::createTexture2D(unsigned char *piexlData, int width, int height, GLenum type)
{
    GLuint texture;
    glGenTextures(1,&texture);
    glBindTexture(GL_TEXTURE_2D,texture);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D,0,type,width,height,0,type,GL_UNSIGNED_BYTE,piexlData);
    return texture;
}

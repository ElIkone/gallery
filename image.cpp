/*******************************************************************************
**                                                                            **
**                                                                            **
**                                 Ikone                                      **
**                            copyright (C) %YEAR%                            **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
*******************************************************************************/


#include "image.h"

Image::Image(QObject *parent) : QObject(parent){
}

Image::Image(const QString &path,QObject *parent) : QObject(parent), m_path(path){
}

QString Image::path() const
{
    return m_path;
}

void Image::setPath(const QString &path)
{
    if (path != m_path) {
        m_path = path;
        emit pathChanged();
    }
}

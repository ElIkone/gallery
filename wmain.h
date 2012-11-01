/*******************************************************************************
**                                                                            **
**                                                                            **
**                                 By Ikone                                   **
**                            copyright (C) %YEAR%                            **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
*******************************************************************************/
#ifndef WMAIN_H
#define WMAIN_H

#include <QDeclarativeItem>
#include <QApplication>
#include <QDeclarativeEngine>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QImageReader>

#include <QFile>
#include <QDir>

#include "image.h"

class WMain : public QDeclarativeView
{
    Q_OBJECT
public:
    explicit WMain(QWidget *parent = 0);
    void updateImagesModel();

private:
   QDeclarativeContext *root_context;
   QList<QObject*> imagesModel;

};

#endif // WMAIN_H

#include "wmain.h"

WMain::WMain(QWidget *parent) : QDeclarativeView(parent){
    root_context = rootContext();
    root_context->setContextProperty("wMain", this);
    setSource(QUrl("qrc:/qml/main.qml"));

    updateImagesModel();
}

void WMain::updateImagesModel(){
    for (int i = 0; i < imagesModel.count(); ++i) {
        imagesModel.at(i)->deleteLater();
    }

    imagesModel.clear();

    //Read folder and then files
    QDir dir;
    dir.setPath("pictures/");

    QStringList directories = dir.entryList(QDir::AllDirs);
    QStringList files = dir.entryList(QDir::Files);

    directories.removeAt(directories.indexOf("."));
    directories.removeAt(directories.indexOf(".."));

    for (int i = 0; i < directories.count(); ++i) {
        directories[i] = dir.path() + "/" + directories.at(i);
    }

    for (int i = 0; i < files.count(); ++i) {
        files[i] = dir.path() + "/" + files.at(i);
    }

    while (!(directories.isEmpty() && files.isEmpty())){

        //qDebug() << "******** INSIDE " << dir.path() <<  " **********";

        while(!files.isEmpty()){

            QImageReader reader;
            QImage *img = new QImage;
            reader.setFileName(files.first());

            if (reader.read(img)){
                imagesModel.append(new Image(files.first()));
            }

            delete img;

            qDebug () << files.takeFirst();
        }

        if (directories.isEmpty()){
            break;
        }

        dir.setPath(directories.takeFirst());

        files = dir.entryList(QDir::Files);

        QStringList directoriesToApennd = dir.entryList(QDir::AllDirs);
        directoriesToApennd.removeAt(directoriesToApennd.indexOf("."));
        directoriesToApennd.removeAt(directoriesToApennd.indexOf(".."));

        for (int i = 0; i < directoriesToApennd.count(); ++i) {
            directoriesToApennd[i] = dir.path() + "/" + directoriesToApennd.at(i);
        }

        for (int i = 0; i < files.count(); ++i) {
                    files[i] = dir.path() + "/" + files.at(i);
                }

        for (int i = 0; i < directoriesToApennd.count(); ++i) {
            directories.append(directoriesToApennd.at(i));
        }

        directoriesToApennd.clear();
    }

    rootContext()->setContextProperty("imagesModel",QVariant::fromValue(imagesModel));
}

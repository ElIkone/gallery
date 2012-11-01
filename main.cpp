/*******************************************************************************
**                                                                            **
**                                                                            **
**                                    Ikone                                   **
**                            copyright (C) %YEAR%                            **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
*******************************************************************************/


#include <QApplication>
#include "wmain.h"

Q_DECL_EXPORT int main(int argc, char *argv[]){

    QApplication app(argc, argv);

    QCoreApplication::setOrganizationName("ikone");
    QCoreApplication::setOrganizationDomain("ikone.com");
    QCoreApplication::setApplicationName("Gallery");

    WMain w;
    w.show();

    return app.exec();
}

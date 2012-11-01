/*******************************************************************************
**                                                                            **
**                                                                            **
**                                 By Ikone                                   **
**                            %YEAR%                                          **
**                                                                            **
**                                                                            **
**                                                                            **
**                                                                            **
*******************************************************************************/
#ifndef IMAGE_H
#define IMAGE_H

#include <QObject>

class Image : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)

public:
    explicit Image(QObject *parent = 0);
    explicit Image(const QString &path, QObject *parent = 0);

    QString path() const;
    void setPath(const QString &path);
    
signals:
    void pathChanged();

private:
    QString m_path;
    
};

#endif // IMAGE_H

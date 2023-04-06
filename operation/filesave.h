#ifndef FILESAVE_H
#define FILESAVE_H

#include <QObject>
#include <QString>

class FileSave : public QObject
{
    Q_OBJECT
public:
    explicit FileSave(const QString& filename);

public slots:
    void saveDataToFile(const QVector<QString>& dataToSave);

private:
    QString fileName_;

signals:
    void sendFileError(QString);
};

#endif // FILESAVE_H

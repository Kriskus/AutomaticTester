#ifndef FILEREAD_H
#define FILEREAD_H

#include <QObject>
#include <QFile>
#include <QVector>
#include <QString>

class FileRead : public QObject
{
    Q_OBJECT
public:
    explicit FileRead(const QString& fileName);

    QVector<QString> readFile();

private:
    QString fileName_;
    QVector<QString> readedData_{};

signals:
    void sendReadedData(QVector<QString>);
    void sendFileError(QString);
};

#endif // FILEREAD_H

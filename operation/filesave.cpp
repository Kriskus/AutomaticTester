#include "filesave.h"

#include <QFile>
#include <QTextStream>

FileSave::FileSave(const QString &filename)
    : fileName_(filename)
{

}

void FileSave::saveDataToFile(const QVector<QString>& dataToSave) {
    QFile fileToSave(fileName_);
    if(fileToSave.open(QIODevice::WriteOnly)) {
        QTextStream stream(&fileToSave);
        stream.setCodec("UTF-8");
        for(const auto& el: dataToSave) {
            stream << el + "\n";
        }
        fileToSave.close();
    } else {
        emit sendFileError(fileToSave.errorString());
    }
}

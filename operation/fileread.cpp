#include "fileread.h"

FileRead::FileRead(const QString &fileName)
    : fileName_(fileName)
{

}

QVector<QString> FileRead::readFile() {
    QFile configFile(fileName_);
    if(configFile.open(QIODevice::ReadOnly)) {
        while(!configFile.atEnd()) {
            readedData_.push_back(configFile.readLine());
        }
        return readedData_;
    } else {
        emit sendFileError(configFile.errorString());
        return {"Error"};
    }
}

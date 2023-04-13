#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <QString>

class Sequence {
public:
    Sequence(unsigned int id, const QString& name)
        : id_(id)
        , name_(name)
    {}
    ~Sequence() {}

    unsigned int getId() const { return id_; }
    QString getName() { return name_; }

private:
    unsigned int id_{};
    QString name_{};
};

#endif // SEQUENCE_H

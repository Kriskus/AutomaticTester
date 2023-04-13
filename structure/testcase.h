#ifndef TESTCASE_H
#define TESTCASE_H

#include <QString>

class Testcase {
public:
    Testcase(unsigned int id, unsigned int idScenario, unsigned int idUserCreator, unsigned int idUserConfirmer, const QString& name)
        : id_(id)
        , idScenario_(idSequence)
        , idUserCreator_(idUserCreator)
        , idUserConfirmer_(idUserConfirmer)
        , name_(name)
    {}
    ~Testcase() {}

    unsigned int getId() const { return id_; }
    unsigned int getIdScenario() const { return idScenario_; }
    unsigned int getIdUserCreator() const { return idUserCreator_; }
    unsigned int getIdUserConfirmer() const { return idUserConfirmer_; }
    QString getName() { return name_; }

private:
    unsigned int id_{};
    unsigned int idScenario_{};
    unsigned int idUserCreator_{};
    unsigned int idUserConfirmer_{};
    QString name_{};
};

#endif // TESTCASE_H

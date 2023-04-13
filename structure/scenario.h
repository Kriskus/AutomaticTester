#ifndef SCENARIO_H
#define SCENARIO_H

#include <QString>

class Scenario {
public:
    Scenario(unsigned int id, unsigned int idSequence, unsigned int idUserCreator, unsigned int idUserConfirmer, const QString& name)
        : id_(id)
        , idSequence_(idSequence)
        , idUserCreator_(idUserCreator)
        , idUserConfirmer_(idUserConfirmer)
        , name_(name)
    {}
    ~Scenario() {}

    unsigned int getId() const { return id_; }
    unsigned int getIdSequence() const { return idSequence_; }
    unsigned int getIdUserCreator() const { return idUserCreator_; }
    unsigned int getIdUserConfirmer() const { return idUserConfirmer_; }
    QString getName() { return name_; }

private:
    unsigned int id_{};
    unsigned int idSequence_{};
    unsigned int idUserCreator_{};
    unsigned int idUserConfirmer_{};
    QString name_{};
};

#endif // SCENARIO_H

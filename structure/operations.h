#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <QString>

class Operation {
public:
    Operation(unsigned int id, unsigned int idTestcase, unsigned int idOrder, unsigned int queue, const QString& name)
        : id_(id)
        , idTestcase_(idTestcase)
        , idOrder_(idOrder)
        , queue_(queue)
        , name_(name)
    {}
    ~Operation() {}

    unsigned int getId() const { return id_; }
    unsigned int getIdTestcase() const { return idTestcase_; }
    unsigned int getIdOrder() const { return idOrder_; }
    unsigned int getqueue() const { return queue_; }
    QString getName() { return name_; }

private:
    unsigned int id_{};
    unsigned int idTestcase_{};
    unsigned int idOrder_{};
    unsigned int queue_{};
    QString name_{};
};

#endif // OPERATIONS_H

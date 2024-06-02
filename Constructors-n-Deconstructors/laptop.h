#ifndef LAPTOP_H
#define LAPTOP_H

#include <QObject>
#include <QDebug>
#include <QString>
class Laptop : public QObject
{
    Q_OBJECT
public:
    explicit Laptop(QObject *parent = nullptr, QString name = "");

    ~Laptop();
    Laptop(const Laptop&);

    QString name;
    double weightInPounds;
    void test();
    double convToKilos();



signals:
};

#endif // LAPTOP_H

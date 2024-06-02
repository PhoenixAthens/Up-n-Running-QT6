#include "laptop.h"

Laptop::Laptop(QObject *parent, QString name)
    : QObject{parent}{
    this->name = name;
    qInfo()<< this << "with name "<<this->name<< "has been created";
}
Laptop::~Laptop(){
    qInfo() << this << "has not been deconstructed!!";
}
Laptop::Laptop(const Laptop& copy){
    this->name= copy.name;
    this->weightInPounds = copy.weightInPounds;

}

void Laptop::test(){
    qInfo()<< this << "with name: " << this->name << "and weight" << this->weightInPounds << "has now been tested!!";
    qInfo()<< "In kilos" << this->weightInPounds << "becomes" << this->convToKilos();
}
double Laptop::convToKilos(){
    return this->weightInPounds * 0.4532;
}


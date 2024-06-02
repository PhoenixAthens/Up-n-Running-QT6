#include <QCoreApplication>
#include "laptop.h"

//test method implemented like so, works fine (if we have defined
//a copy-constructor in src/header file)
void test_2(Laptop laptop){
    laptop.test();
}
//output:
/*
Laptop(0x16f4f7530) with name  "Dell" has been created
Laptop(0x16f4f74d8) with name  "Vaio" has been created
Laptop(0x16f4f7490) with name:  "Dell" and weight 12 has now been tested!!
In kilos 12 becomes 5.4384
Laptop(0x16f4f7490) has not been deconstructed!!
Laptop(0x16f4f7460) with name:  "Vaio" and weight 5 has now been tested!!
In kilos 5 becomes 2.266
Laptop(0x16f4f7460) has not been deconstructed!!
Laptop(0x16f4f74d8) has not been deconstructed!!
Laptop(0x16f4f7530) has not been deconstructed!!
*/

//otherwise, it's better to use this mechanism
void test(Laptop& laptop){
    laptop.test();
}

void createObj(){
    Laptop l1{nullptr,"Dell"};
    l1.weightInPounds = 12;

    Laptop l2{nullptr,"Vaio"};
    l2.weightInPounds = 5;

    test(l1);
    test(l2);

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    createObj();

    return a.exec();
}

//Output
/*
Laptop(0x16f017540) with name  "Dell" has been created
Laptop(0x16f0174e8) with name  "Vaio" has been created
Laptop(0x16f017540) with name:  "Dell" and weight 12 has now been tested!!
In kilos 12 becomes 5.4384
Laptop(0x16f0174e8) with name:  "Vaio" and weight 5 has now been tested!!
In kilos 5 becomes 2.266
Laptop(0x16f0174e8) has not been deconstructed!!
Laptop(0x16f017540) has not been deconstructed!!
*/

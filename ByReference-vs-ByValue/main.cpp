#include <QCoreApplication>
#include <QDebug>

void testVal(int x){
    x*=20;
    qInfo() << "The value of x: "<< x;
}
void testRef(int& x){
    x*=25;
    qInfo() << "The address of x in memory is "<<&x;
    //The address of x in memory is  0x16f933584
    qInfo() << "The value of x: "<< x;
}

// QObject getMeQobj(QString name){
//     static QObject a;
//     a.setObjectName(name);
//     return a; //error saying object has been explicitly marked deleted here
// }

QObject& getMeObj2(QString name){
    QObject a;
    a.setObjectName(name);
    return a; //error saying "reference to stack memory"
}
QObject& getMeObj3(QString name){
    static QObject a;
    a.setObjectName(name);
    return a; //error saying "reference to stack memory"
}
QObject* getMeObj4(QString name){
    QObject* obj = new QObject(); //new allocates the object on heap, and returns a pointer to that object on the heap, manually managed memory!!
    obj->setObjectName(name);
    return obj; //returning the pointer to object
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int x = 5;
    qInfo() << "The value of x is "<<x; //5
    testVal(x); //100
    qInfo() << "The value of x is "<<x; //5

    int y = x;
    qInfo() << "The value of x is "<<y; //5
    testRef(y); //125
    qInfo() << "The value of x is "<<y; //125

    qInfo()<<"The address of y in memory is "<<&y;
    //The address of y in memory is  0x16f933584

    //calling getMeObj2
    //qInfo() << getMeObj2(QString("jonek")).objectName();
    //09:42:00: /Users/anmolkhanna/Downloads/Programming_Savings_2024/QT/ByReference-vs-ByValue/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/ByReference-vs-ByValue crashed.

    //calling getMeObj3
    qInfo() << getMeObj3(QString("ionek")).objectName();
    //"ionek"

    //This works
    QObject& obj_some = getMeObj3("hathy");
    qInfo() << obj_some.objectName();
    //hathy

    //but this doesn't
    //QObject obj_som = getMeObj3("hathy");
    //Error: Call to deleted constructor of 'QObject' 'QObject' has been explicitly marked deleted here!

    //Some experimentation
    int i = 23;
    int& toI = i;
    int j = toI;
    j = 24;
    qInfo() << "Value of i is "<<i<<", toI is "<<toI<<", j is "<<j;
    //Value of i is  23 , toI is  23 , j is  24
    toI = 28;
    qInfo() << "Value of i is "<<i<<", toI is "<<toI<<", j is "<<j;
    //Value of i is  28 , toI is  28 , j is  24

    QObject* objPointer = getMeObj4("Janki");
    qInfo() << objPointer->objectName(); // "Janki"
    qInfo() << objPointer;  // QObject(0x600000b140b0, name = "Janki")
    qInfo() << &objPointer; //0x16b93f3e0 //this is the address of objPointer variable in memory ---(a)
    //Why is that so (at ---(a)
    //because when `&` operator is used on a pointer variable, the `&` operator gives the address of the pointer variable itself, not the address it points to
    //on the other hand when you use `&` operator on a object allocated on a heap, referred to by a normal variable, you get the address of the obejct itself

    QObject testObj;
    testObj.setObjectName("longMeow");
    qInfo() << &testObj; //QObject(0x16f9bb320, name = "longMeow")
    //the statement above gives the address of object referred to by 'testObj' on the stack

    //To delete the object form heap
    delete objPointer;
    int x_val = 23;
    int* into = &x_val ;
    qInfo() << &into; //0x16f2c32d0, address of pointer variable
    qInfo() << &x_val; //0x16f2c32dc, address of value in memory
    qInfo() << &(*into); //0x16f2c32dc, address of value referred to by pointer variable in memory


    return a.exec();
}

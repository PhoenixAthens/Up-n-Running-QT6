#include <QCoreApplication>
#include "animal.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Animal dog;
    Animal cat;
    Animal jaguar;
    // Animal(0x16bc875b0) Constructed!
    // Animal(0x16bc87590) Constructed!
    // Animal(0x16bc87580) Constructed!

    dog.Speak("Bark Bark!!");
    cat.Speak("Meoww!!");
    jaguar.Speak("purrr!");
    // Animal(0x16f16f5b0) "Bark Bark!!"
    // Animal(0x16f16f590) "Meoww!!"
    // Animal(0x16f16f580) "purrr!"

    dog.setObjectName("Rory");
    cat.setObjectName("scarlett");
    jaguar.setObjectName("Tigerr");
    dog.Speak("Bark Bark!!");
    cat.Speak("Meoww!!");
    jaguar.Speak("purrr!");
    // Animal(0x16f33f5a0, name = "Rory") "Bark Bark!!"
    // Animal(0x16f33f580, name = "scarlett") "Meoww!!"
    // Animal(0x16f33f570, name = "Tigerr") "purrr!"

    return a.exec();
}

//
// main.cpp
// 2023-05-01
// Ivan Konishchev
//

#include <iostream>
#include "Human.h"
#include <string>

int main(int argc, const char *argv[])
{
    People oleg = People("Олег");
    People nikita = People("Никита");
    People nasty = People("Настя");
    People ivan = People("Ваня");
    People jeny = People("Женя");
    People denis = People("Денис");
    Human<People> hum;
    hum.addPeople(oleg);
    hum.addPeople(nikita);
    hum.addPeople(nasty);
    hum.addPeople(ivan);
    hum.addPeople(jeny);
    hum.addPeople(denis);
    hum.addCommunoicationWithThreeHandshakes();
    hum.printCommunication();
    return 0;
}
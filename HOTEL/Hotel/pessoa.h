#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include "room.h"

using namespace std;

class Pessoa{
private:
    int id;
    string name;
    int age;
    Room room;

public:
    Pessoa(int id, string name, int age){
        this->id = id;
        this->name = name;
        this->age = age;
    }

    void addRoom(Room room){
        this->room = room;
    }

    void removeRoom(){
        this->room.changeStatus();

        this->room = NULL;
    }

    int getRoomNumber(){
        return this->room.getNumber();
    }

};


#endif // PESSOA_H

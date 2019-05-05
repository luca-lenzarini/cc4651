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

    Pessoa(int id){
        this->id = id;
    }

    void addRoom(Room room){
        this->room = room;
    }

    void removeRoom(){
        this->room.changeStatus();
    }

    int getRoomNumber(){
        return this->room.getNumber();
    }

    int getId(){
        return this->id;
    }

};


#endif // PESSOA_H

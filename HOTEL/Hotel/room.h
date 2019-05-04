#ifndef ROOM_H
#define ROOM_H


class Room{
private:
    int number;
    int beds;
    bool isOccupied;


public:
    Room(){
        this->number = 0;
        this->beds = 0;
        this->isOccupied = false;
    }

    Room(int number, int beds){
        this->number = number;
        this->beds = beds;
        this->isOccupied = false;
    }

    void changeStatus(){
        this->isOccupied = !this->isOccupied;
    }

    void setNumberOfBeds(int beds){
        this->beds = beds;
    }

    int getNumber(){
        return this->number;
    }

    int getBeds(){
        return this->beds;
    }

    int getIsOccupied(){
        return this->isOccupied;
    }

    bool isGreaterThan(Room roomToCompare){
        if(this->getNumber() > roomToCompare.getNumber()){
            return true;
        }
        return false;
    }
};

#endif // ROOM_H


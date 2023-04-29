#include "../Headers/City.h"
City::City(int number,int num_of_city) {
    redWarriors=new Red_warriors();
    blueWarriors=new Blue_warriors();
    this->number=number;
    this->num_of_city=num_of_city;
}
//
// Created by 50207 on 29/4/2023.
//

#include <cstdio>
#include "vector"
#include "deque"
#include "Warriors.h"
#ifndef PROJECT_SPRING_2023_CITY_H
#define PROJECT_SPRING_2023_CITY_H
struct Blue_warriors{
    Dragon *dragon;
    Ninja *ninja;
    Iceman *iceman;
    Lion *lion;
    Wolf *wolf;
    Blue_warriors(){
        dragon= nullptr;
        ninja= nullptr;
        iceman= nullptr;
        lion= nullptr;
        wolf= nullptr;
    }
};
struct Red_warriors{
    Dragon *dragon;
    Ninja *ninja;
    Iceman *iceman;
    Lion *lion;
    Wolf *wolf;
    Red_warriors(){
        dragon= nullptr;
        ninja= nullptr;
        iceman= nullptr;
        lion= nullptr;
        wolf= nullptr;
    }
};
class City{
public:
    int number;
    int num_of_city;
    Blue_warriors *blueWarriors;
    Red_warriors *redWarriors;
    City(int number,int num_of_city);
};
#endif //PROJECT_SPRING_2023_CITY_H

//
// Created by 50207 on 29/4/2023.
//

#include <cstdio>
#include "vector"
#include "deque"
#include "Warriors.h"
#include "Weapons.h"
#ifndef PROJECT_SPRING_2023_CITY_H
#define PROJECT_SPRING_2023_CITY_H
class City{
public:
    int number;
    int num_of_city;
    Warrior *red= nullptr;
    Warrior *blue= nullptr;
    City(int number,int num_of_city);
    void steal(int time);
    void fight(int time);
};
#endif //PROJECT_SPRING_2023_CITY_H

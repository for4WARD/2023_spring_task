//
// Created by 50207 on 29/4/2023.
//

#include <cstdio>
#include "City.h"
#ifndef PROJECT_SPRING_2023_MAP_H
#define PROJECT_SPRING_2023_MAP_H
class Map{
public:
    City* red_cities[42];
    City* blue_cities[42];
    int num_of_city;
    Map(int num_of_city);
    void forge();
};
#endif //PROJECT_SPRING_2023_MAP_H

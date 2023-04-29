//
// Created by 50207 on 29/4/2023.
//

#include <cstdio>
#include "City.h"
#ifndef PROJECT_SPRING_2023_MAP_H
#define PROJECT_SPRING_2023_MAP_H
class Map{
    City* red_cities[22];
    City* blue_cities[22];
    int num_of_city;
    Map(int num_of_city);
};
#endif //PROJECT_SPRING_2023_MAP_H

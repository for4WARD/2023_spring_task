//
// Created by 50207 on 25/4/2023.
//

#include <iostream>
#include <vector>
#include "Warriors.h"
#include "Map.h"
#ifndef PROJECT_2023_SPRING_TASK_HEADQUARTERS_H
#define PROJECT_2023_SPRING_TASK_HEADQUARTERS_H
class Headquarter{
public:
    int order[5],life[5],attack[5],number[5];
    int stop;
    int M;
    int construct=0;
    int serial_number=0;
    std::vector<Dragon*>Vector_dragon;
    std::vector<Ninja*>Vector_ninja;
    std::vector<Iceman*>Vector_iceman;
    std::vector<Lion*>Vector_lion;
    std::vector<Wolf*>Vector_wolf;
    bool on;

};
class Blue_headquarter:public Headquarter{
public:
    Blue_headquarter(const int Life_value[],int m,const int attack_value[]);
    ~Blue_headquarter();
    void generate();
};
class Red_headquarter:public Headquarter{
public:
    Red_headquarter(const int Life_value[],int m,const int attack_value[]);
    ~Red_headquarter();
    void generate();
};
#endif //PROJECT_2023_SPRING_TASK_HEADQUARTERS_H

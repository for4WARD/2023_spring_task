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
    bool update=true;
    int order[5],life[5],attack[5],number[5];
    int stop;
    int M,K;
    int construct=0;
    int serial_number=0;
    std::vector<Warrior*>vector_warrior;
    bool on;

};
class Blue_headquarter:public Headquarter{
public:
    Blue_headquarter(const int Life_value[],int m,const int attack_value[],int K);
    ~Blue_headquarter();
    int generate();
};
class Red_headquarter:public Headquarter{
public:
    Red_headquarter(const int Life_value[],int m,const int attack_value[],int K);
    ~Red_headquarter();
    int generate();
};
#endif //PROJECT_2023_SPRING_TASK_HEADQUARTERS_H

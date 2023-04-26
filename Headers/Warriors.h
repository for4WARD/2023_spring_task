//
// Created by 50207 on 25/4/2023.
//

#include <iostream>

#ifndef PROJECT_2023_SPRING_TASK_WARRIORS_H
#define PROJECT_2023_SPRING_TASK_WARRIORS_H
class Warrior{
public:
    int number,life,attack;
    bool dead= false;
    std::string weapons[3]={"sword","bomb","arrow"};
};
class Dragon:public Warrior{
public:
    std::string weapon;
    double morale;
    Dragon(int Number,int Attack,int Life){
        number=Number;
        attack=Attack;
        life=Life;
        weapon=weapons[number%3];
    }
    Dragon(int Number,int Attack,int Life,double Morale){
        auto *weapons=new std::string[3]{"sword","bomb","arrow"};
        number=Number;
        attack=Attack;
        life=Life;
        weapon=weapons[number%3];
        morale=Morale;
    }

};
class Ninja:public Warrior{
public:
    std::string weapon1;
    std::string weapon2;
    Ninja(int Number,int Attack,int Life){
        number=Number;
        attack=Attack;
        life=Life;
        weapon1=weapons[number%3];
        weapon2=weapons[(number+1)%3];
    }
};
class Iceman:public Warrior{
public:
    std::string weapon;
    Iceman(int Number,int Attack,int Life){

        number=Number;
        attack=Attack;
        life=Life;
        weapon=weapons[number%3];
    }
};
class Lion:public Warrior{
public:
    int loyalty;
    Lion(int Number,int Attack,int Life){
        number=Number;
        attack=Attack;
        life=Life;
    }
    Lion(int Number,int Attack,int Life,int Loyalty){
        number=Number;
        attack=Attack;
        life=Life;
        loyalty=Loyalty;
    }

};
class Wolf:public Warrior{
public:
    Wolf(int Number,int Attack,int Life){
        number=Number;
        attack=Attack;
        life=Life;
    }
};
#endif //PROJECT_2023_SPRING_TASK_WARRIORS_H

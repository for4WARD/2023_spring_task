//
// Created by 50207 on 25/4/2023.
//

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include "Weapons.h"
#ifndef PROJECT_2023_SPRING_TASK_WARRIORS_H
#define PROJECT_2023_SPRING_TASK_WARRIORS_H
class Warrior{
public:
    int number,life,attack;
    bool dead= false;
    int sword_attack,bomb_attack,bomb_self_attack,arrow_attack;
    std::string name;
    std::deque<Sword*>deque_sword;
    std::deque<Bomb*>deque_bomb;
    std::deque<Arrow*>deque_arrow;
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
        name="dragon";
        auto *weapons=new std::string[3]{"sword","bomb","arrow"};
        number=Number;
        attack=Attack;
        life=Life;
        weapon=weapons[number%3];
        morale=Morale;
        sword_attack=floor(attack*2.0/10);
        bomb_attack= floor(attack*4.0/10);
        bomb_self_attack= floor(bomb_attack*5.0/10);
        arrow_attack= floor(attack*3.0/10);
        if (number%3==0){
            Sword *sword=new Sword();
            deque_sword.push_back(sword);
        }else if (number%3==1){
            Bomb *bomb=new Bomb();
            deque_bomb.push_back(bomb);
        }else{
            Arrow *arrow=new Arrow();
            deque_arrow.push_back(arrow);
        }
    }
    ~Dragon(){
        for (auto &item: deque_arrow){
            delete item;
        }
        for (auto &item:deque_bomb) {
            delete item;
        }
        for(auto item:deque_sword){
            delete item;
        }
        deque_sword.clear();
        deque_bomb.clear();
        deque_arrow.clear();
    }

};
class Ninja:public Warrior{
public:
    std::string weapon1;
    std::string weapon2;
    Ninja(int Number,int Attack,int Life){
        name="ninja";
        number=Number;
        attack=Attack;
        life=Life;
        sword_attack=floor(attack*2.0/10);
        bomb_attack= floor(attack*4.0/10);
        bomb_self_attack= 0;
        arrow_attack= floor(attack*3.0/10);
        if (number%3==0){
            Sword *sword=new Sword();
            deque_sword.push_back(sword);
        }else if (number%3==1){
            Bomb *bomb=new Bomb();
            deque_bomb.push_back(bomb);
        }else{
            Arrow *arrow=new Arrow();
            deque_arrow.push_back(arrow);
        }
        if ((number+1)%3==0){
            Sword *sword=new Sword();
            deque_sword.push_back(sword);
        }else if ((number+1)%3==1){
            Bomb *bomb=new Bomb();
            deque_bomb.push_back(bomb);
        }else{
            Arrow *arrow=new Arrow();
            deque_arrow.push_back(arrow);
        }
        weapon1=weapons[number%3];
        weapon2=weapons[(number+1)%3];
    }
    ~Ninja(){
        for (auto &item: deque_arrow){
            delete item;
        }
        for (auto &item:deque_bomb) {
            delete item;
        }
        for(auto item:deque_sword){
            delete item;
        }
        deque_sword.clear();
        deque_bomb.clear();
        deque_arrow.clear();
    }
};
class Iceman:public Warrior{
public:
    std::string weapon;
    Iceman(int Number,int Attack,int Life){
        name="iceman";
        number=Number;
        attack=Attack;
        life=Life;
        sword_attack=floor(attack*2.0/10);
        bomb_attack= floor(attack*4.0/10);
        bomb_self_attack= floor(bomb_attack*5.0/10);
        arrow_attack= floor(attack*3.0/10);
        if (number%3==0){
            Sword *sword=new Sword();
            deque_sword.push_back(sword);
        }else if (number%3==1){
            Bomb *bomb=new Bomb();
            deque_bomb.push_back(bomb);
        }else{
            Arrow *arrow=new Arrow();
            deque_arrow.push_back(arrow);
        }
        weapon=weapons[number%3];
    }
    ~Iceman(){
        for (auto &item: deque_arrow){
            delete item;
        }
        for (auto &item:deque_bomb) {
            delete item;
        }
        for(auto item:deque_sword){
            delete item;
        }
        deque_sword.clear();
        deque_bomb.clear();
        deque_arrow.clear();
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
        sword_attack=floor(attack*2.0/10);
        bomb_attack= floor(attack*4.0/10);
        bomb_self_attack= floor(bomb_attack*5.0/10);
        arrow_attack= floor(attack*3.0/10);
    }
    ~Lion(){
        for (auto &item: deque_arrow){
            delete item;
        }
        for (auto &item:deque_bomb) {
            delete item;
        }
        for(auto item:deque_sword){
            delete item;
        }
        deque_sword.clear();
        deque_bomb.clear();
        deque_arrow.clear();
    }

};
class Wolf:public Warrior{
public:
    Wolf(int Number,int Attack,int Life){
        number=Number;
        attack=Attack;
        life=Life;
        sword_attack=floor(attack*2.0/10);
        bomb_attack= floor(attack*4.0/10);
        bomb_self_attack= floor(bomb_attack*5.0/10);
        arrow_attack= floor(attack*3.0/10);
    }
    ~Wolf(){
        for (auto &item: deque_arrow){
            delete item;
        }
        for (auto &item:deque_bomb) {
            delete item;
        }
        for(auto item:deque_sword){
            delete item;
        }
        deque_sword.clear();
        deque_bomb.clear();
        deque_arrow.clear();
    }
};
#endif //PROJECT_2023_SPRING_TASK_WARRIORS_H

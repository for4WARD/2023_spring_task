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
    std::string camp;
    int number,life,attack;
    bool dead= false;
    int sword_attack,bomb_attack,bomb_self_attack,arrow_attack;
    int type_num;
    std::string name;
    std::deque<Weapon*>dq_weapon;
    int weapon_count[3]={0,0,0};
    std::string weapons[3]={"sword","bomb","arrow"};
    void weaponSort();
};
class Dragon:public Warrior{
public:
    std::string weapon;
    double morale;
    Dragon(int Number,int Attack,int Life,double Morale){
        type_num=0;
        name="dragon";
        number=Number;
        attack=Attack;
        life=Life;
        morale=Morale;
        sword_attack=floor(attack*2.0/10);
        bomb_attack= floor(attack*4.0/10);
        bomb_self_attack= floor(bomb_attack*5.0/10);
        arrow_attack= floor(attack*3.0/10);
        if (number%3==0){
            Sword *sword=new Sword();
            dq_weapon.emplace_back(sword);
            weapon_count[0]+=1;
        }else if (number%3==1){
            Bomb *bomb=new Bomb();
            dq_weapon.emplace_back(bomb);
            weapon_count[1]+=1;
        }else{
            Arrow *arrow=new Arrow();
            dq_weapon.emplace_back(arrow);
            weapon_count[2]+=1;
        }
        weaponSort();
    }
    ~Dragon(){
        for (auto &item: dq_weapon){
            delete item;
        }
        dq_weapon.clear();
    }

};
class Ninja:public Warrior{
public:
    Ninja(int Number,int Attack,int Life){
        type_num=1;
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
            dq_weapon.emplace_back(sword);
            weapon_count[0]+=1;
        }else if (number%3==1){
            Bomb *bomb=new Bomb();
            dq_weapon.emplace_back(bomb);
            weapon_count[1]+=1;
        }else{
            Arrow *arrow=new Arrow();
            dq_weapon.emplace_back(arrow);
            weapon_count[2]+=1;
        }
        if ((number+1)%3==0){
            Sword *sword=new Sword();
            dq_weapon.emplace_back(sword);
            weapon_count[0]+=1;
        }else if ((number+1)%3==0){
            Bomb *bomb=new Bomb();
            dq_weapon.emplace_back(bomb);
            weapon_count[1]+=1;
        }else{
            Arrow *arrow=new Arrow();
            dq_weapon.emplace_back(arrow);
            weapon_count[2]+=1;
        }
        weaponSort();
    }
    ~Ninja(){
        for (auto &item: dq_weapon){
            delete item;
        }
        dq_weapon.clear();
    }
};
class Iceman:public Warrior{
public:
    std::string weapon;
    Iceman(int Number,int Attack,int Life){
        type_num=2;
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
            dq_weapon.emplace_back(sword);
            weapon_count[0]+=1;
        }else if (number%3==1){
            Bomb *bomb=new Bomb();
            dq_weapon.emplace_back(bomb);
            weapon_count[1]+=1;
        }else{
            Arrow *arrow=new Arrow();
            dq_weapon.emplace_back(arrow);
            weapon_count[2]+=1;
        }
        weaponSort();
    }
    ~Iceman(){
        for (auto &item: dq_weapon){
            delete item;
        }
        dq_weapon.clear();
    }
    void forge();
};
class Lion:public Warrior{
public:
    int loyalty;
    int K;
    bool flee=false;
    Lion(int Number,int Attack,int Life,int Loyalty,int k){
        name="lion";
        type_num=3;
        K=k;
        number=Number;
        attack=Attack;
        life=Life;
        loyalty=Loyalty;
        sword_attack=floor(attack*2.0/10);
        bomb_attack= floor(attack*4.0/10);
        bomb_self_attack= floor(bomb_attack*5.0/10);
        arrow_attack= floor(attack*3.0/10);
        if (number%3==0){
            Sword *sword=new Sword();
            dq_weapon.emplace_back(sword);
            weapon_count[0]+=1;
        }else if (number%3==1){
            Bomb *bomb=new Bomb();
            dq_weapon.emplace_back(bomb);
            weapon_count[1]+=1;
        }else{
            Arrow *arrow=new Arrow();
            dq_weapon.emplace_back(arrow);
            weapon_count[2]+=1;
        }
        weaponSort();
    }
    void forge();
    bool check(){
        return loyalty<=0;
    }
    ~Lion(){
        for (auto &item: dq_weapon){
            delete item;
        }
        dq_weapon.clear();
    }
    void ran_away();

};
class Wolf:public Warrior{
public:
    Wolf(int Number,int Attack,int Life){
        name="wolf";
        type_num=4;
        number=Number;
        attack=Attack;
        life=Life;
        sword_attack=floor(attack*2.0/10);
        bomb_attack= floor(attack*4.0/10);
        bomb_self_attack= floor(bomb_attack*5.0/10);
        arrow_attack= floor(attack*3.0/10);
        weaponSort();
    }
    ~Wolf(){
        for (auto &item: dq_weapon){
            delete item;
        }
        dq_weapon.clear();
    }
};
#endif //PROJECT_2023_SPRING_TASK_WARRIORS_H

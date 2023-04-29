//
// Created by 50207 on 27/4/2023.
//

#include <cstdio>

#ifndef PROJECT_SPRING_2023_WEAPONS_H
#define PROJECT_SPRING_2023_WEAPONS_H
class Weapon{
public:
    int use_time;
    bool remove(){
        return use_time==0;
    }
    void use(){
        use_time-=1;
    }
};
class Sword:public Weapon{
public:
    Sword(){
        use_time=1e9+7;
    }
};
class Bomb:public Weapon{
public:
    Bomb(){
        use_time=1;
    }
};
class Arrow:public Weapon{
public:
    Arrow(){
        use_time=2;
    }
};

#endif //PROJECT_SPRING_2023_WEAPONS_H

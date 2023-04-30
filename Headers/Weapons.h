//
// Created by 50207 on 27/4/2023.
//

#include <cstdio>

#ifndef PROJECT_SPRING_2023_WEAPONS_H
#define PROJECT_SPRING_2023_WEAPONS_H
class Weapon{
public:
    int use_time;
    std::string name;
    std::string get_name(){
        return name;
    }
    bool need_remove(){
        return use_time==0;
    }
    void use(){
        use_time-=1;
    }
    int type_num;
};
class Sword:public Weapon{
public:
    Sword(){
        name="sword";
        type_num=0;
        use_time=1e9+7;
    }
};
class Bomb:public Weapon{
public:
    Bomb(){
        name="bomb";
        type_num=1;
        use_time=1;
    }
};
class Arrow:public Weapon{
public:
    Arrow(){
        name="arrow";
        type_num=2;
        use_time=2;
    }
};

#endif //PROJECT_SPRING_2023_WEAPONS_H

#include "../Headers/Warriors.h"
#include "algorithm"
bool cmp(Weapon *w1,Weapon *w2){
    if (w1->type_num==w2->type_num){
        return w1->use_time>w2->use_time;
    }
    return w1->type_num<w2->type_num;
}
void Lion::forge() {
    loyalty=loyalty-K;
    flee=check();
}
void Lion::ran_away() {
    std::cout<<camp<<" "<<name<<" "<<number<<" ran away"<<std::endl;
}
void Iceman::forge() {
    life-=(life/10);
}

void Warrior::weaponSort() {
    if (!dq_weapon.empty()){
        std::sort(dq_weapon.begin(),dq_weapon.end(),cmp);
    }
}
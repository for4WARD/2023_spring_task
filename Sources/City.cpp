#include "../Headers/City.h"
#include <iomanip>
City::City(int number,int num_of_city) {
    this->number=number;
    this->num_of_city=num_of_city;
}

void City::steal(int time) {
    if (red!= nullptr&&blue!= nullptr){
        if ((red->type_num==4)^(blue->type_num==4)){
            Wolf *wolf= nullptr;
            Warrior *warrior= nullptr;
            if (red->type_num==4){
                wolf=static_cast<Wolf*>(red);
                warrior=blue;
            }else{
                wolf=static_cast<Wolf*>(blue);
                warrior=red;
            }
            int max_steal=10-wolf->weapon_count[0]-wolf->weapon_count[1]-wolf->weapon_count[2];
            for (int i = 0; i <3 ; ++i) {
                if (warrior->weapon_count[0]!=0){
                    int maximal=std::min(warrior->weapon_count[0],max_steal);
                    for (int j = 0; j <maximal ; ++j) {
                        auto it=warrior->dq_weapon[0];
                        wolf->weapon_count[0]+=1;
                        wolf->dq_weapon.push_back(it);
                        warrior->dq_weapon.pop_front();
                        warrior->weapon_count[0]-=1;
                    }
                    std::cout << std::setw(3) << std::setfill('0') << (time / 60) << ":35 "<<wolf->camp<<" wolf "<<wolf->number
                    <<" took "<<maximal<<" sword from "<<warrior->camp<<" "<<warrior->name<<" in city "<<this->number<<std::endl;
                }
                else if (warrior->weapon_count[1]!=0){
                    int maximal=std::min(warrior->weapon_count[1],max_steal);
                    for (int j = 0; j <maximal ; ++j) {
                        auto it=warrior->dq_weapon[0];
                        wolf->weapon_count[1]+=1;
                        wolf->dq_weapon.push_back(it);
                        warrior->dq_weapon.pop_front();
                        warrior->weapon_count[1]-=1;
                    }
                    std::cout << std::setw(3) << std::setfill('0') << (time / 60) << ":35 "<<wolf->camp<<" wolf "<<wolf->number
                              <<" took "<<maximal<<" bomb from "<<warrior->camp<<" "<<warrior->name<<" in city "<<this->number<<std::endl;
                }
                else if (warrior->weapon_count[2]!=0){
                    int maximal=std::min(warrior->weapon_count[2],max_steal);
                    for (int j = 0; j <maximal ; ++j) {
                        auto it=warrior->dq_weapon[warrior->dq_weapon.size()-1];
                        wolf->weapon_count[2]+=1;
                        wolf->dq_weapon.push_back(it);
                        warrior->dq_weapon.pop_back();
                        warrior->weapon_count[2]-=1;
                    }
                    std::cout << std::setw(3) << std::setfill('0') << (time / 60) << ":35 "<<wolf->camp<<" wolf "<<wolf->number
                              <<" took "<<maximal<<" arrow from "<<warrior->camp<<" "<<warrior->name<<" in city "<<this->number<<std::endl;
                }
            }
        }
    }
}

void City::fight(int time) {
    if (this->red!= nullptr&&this->blue!= nullptr){
        red->weaponSort();
        blue->weaponSort();
        Warrior *first,*second;
        if (number&1){
            first=red;
            second=blue;
        }else{
            first=blue;
            second=red;
        }
        auto it_first=first->dq_weapon.begin();
        auto it_second=second->dq_weapon.begin();
        while(!first->dead&&!second->dead){
            if (!first->dead&&!first->dq_weapon.empty()){
                auto weapon=*it_first;
                weapon->use();
                if (weapon->type_num==0){
                    second->life=second->life-first->sword_attack;
                }
                else if (weapon->type_num==1){
                    second->life=second->life-first->bomb_attack;
                    first->life=first->life-first->bomb_self_attack;
                }else{
                    second->life=second->life-first->arrow_attack;
                }
                if (weapon->need_remove()){
                    first->weapon_count[weapon->type_num]-=1;
                    delete *it_first;
                    it_first=first->dq_weapon.erase(it_first);
                    if (it_first==first->dq_weapon.end()){
                        it_first=first->dq_weapon.begin();
                    }
                }else{
                    it_first++;
                    if (it_first==first->dq_weapon.end()){
                        it_first=first->dq_weapon.begin();
                    }
                }
//                std::cout<<first->camp<<" "<<first->name<<" "<<first->life<<" "<<first->weapon_count[1]<<" "<<first->dq_weapon.empty()<<std::endl;
            }
            if (first->life<=0)first->dead= true;
            if (second->life<=0)second->dead= true;
            if (!second->dead&&!second->dq_weapon.empty()&&!first->dead){
                auto weapon=*it_second;
                weapon->use();
                if (weapon->type_num==0){
                    first->life-=second->sword_attack;
                }
                else if (weapon->type_num==1){
                    first->life-=second->bomb_attack;
                    second->life-=second->bomb_self_attack;
                }else{
                    first->life-=second->arrow_attack;
                }
                if (weapon->need_remove()){
                    second->weapon_count[weapon->type_num]-=1;
                    delete *it_second;
                    it_second=second->dq_weapon.erase(it_second);
                    if (it_second==second->dq_weapon.end()){
                        it_second=second->dq_weapon.begin();
                    }
//                    std::cout<<second->camp<<" "<<second->name<<" "<<second->life<<" "<<second->weapon_count[1]<<" "<<second->dq_weapon.empty()<<std::endl;
                }else{
                    it_second++;
                    if (it_second==second->dq_weapon.end()){
                        it_second=second->dq_weapon.begin();
                    }
                }

            }
            if (first->life<=0)first->dead= true;
            if (second->life<=0)second->dead= true;
            if (!first->dead&&!second->dead&&first->dq_weapon.empty()&&second->dq_weapon.empty())break;
        }
        if ((first->dead)^(second->dead)){
            auto alive=second;
            auto dead=first;
            if (second->dead){
                alive=first;
                dead=second;
            }
            int maximal=10-alive->weapon_count[0]-alive->weapon_count[1]-alive->weapon_count[2];
            for (int i = 0; i <2 ; ++i) {
                int to_steal=std::min(maximal,dead->weapon_count[i]);
                for (int j = 0; j <to_steal ; ++j) {
                    auto weapon=dead->dq_weapon[0];
                    alive->dq_weapon.push_back(weapon);
                    dead->dq_weapon.pop_front();
                    maximal-=1;
                }
            }
            int to_steal=std::min(maximal,dead->weapon_count[2]);
            for (int j = 0; j <to_steal ; ++j) {
                auto weapon=dead->dq_weapon[dead->dq_weapon.size()-1];
                alive->dq_weapon.push_back(weapon);
                dead->dq_weapon.pop_back();
                maximal-=1;
            }
            std::cout<<std::setw(3)<<std::setfill('0')<<(time/60)<<":40 "<<alive->camp<<" "<<alive->name<<" "<<alive->number<<" killed "<<dead->camp<<" "<<dead->name
                     <<" "<<dead->number<<" in city "<< this->number<<" remaining "<<alive->life<<" elements"<<std::endl;
        }
        if(first->dead&&second->dead){
            std::cout<<std::setw(3)<<std::setfill('0')<<(time/60)<<":40 both "<<red->camp<<" "<<red->name<<" "<<red->number<<" and "
                     <<blue->camp<<" "<<blue->name<<" "<<blue->number<<" died in city "<<this->number<<std::endl;
        }
        else if (!first->dead&&!second->dead){
            std::cout<<std::setw(3)<<std::setfill('0')<<(time/60)<<":40 both "<<red->camp<<" "<<red->name<<" "<<red->number<<" and "
                     <<blue->camp<<" "<<blue->name<<" "<<blue->number<<" were alive in city "<<this->number<<std::endl;
        }
    }
}
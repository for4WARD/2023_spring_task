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
                              <<" took "<<maximal<<" bomb from "<<warrior->camp<<" "<<warrior->name<<" in city "<<this->number;
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
                              <<" took "<<maximal<<" arrow from "<<warrior->camp<<" "<<warrior->name<<" in city "<<this->number;
                }
            }
        }
    }
}
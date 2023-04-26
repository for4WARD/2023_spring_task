#include "../Headers/Headquarters.h"
#include <iomanip>
Blue_headquarter::Blue_headquarter(const int *Life_value, int m, const int *attack_value) {
    M=m;
    int min=114514666;
    for (int i = 0; i < 5; ++i) {
        life[i]=Life_value[i];
        min=std::min(min,life[i]);
        attack[i]=attack_value[i];
        number[i]=0;
    }
    order[0]=3,order[1]=0,order[2]=1,order[3]=2,order[4]=4;
    stop=min;
    on= true;
}
Red_headquarter::Red_headquarter(const int *Life_value, int m, const int *attack_value) {
    M=m;
    int min=114514666;
    for (int i = 0; i < 5; ++i) {
        life[i]=Life_value[i];
        min=std::min(min,life[i]);
        attack[i]=attack_value[i];
        number[i]=0;
    }
    order[0]=2,order[1]=3,order[2]=4,order[3]=1,order[4]=0;
    stop=min;
    on= true;
}
void Blue_headquarter::generate(){
    bool flag= true;
    while (on&& flag){
        if (M<stop){
            std::cout<<"blue headquarter stops making warriors"<<std::endl;
            on= false;
            break;
        } else if (construct==0&&M>=life[order[0]]){
            ++serial_number;
            M-=life[order[0]];
            int loyalty=M;
            auto *lion=new Lion(++number[order[0]],++attack[order[0]],life[order[0]],loyalty);
            Vector_lion.emplace_back(lion);
            flag= false;
            std::cout<<"blue lion "<<serial_number<<" born with strength "<<(*lion).life<<","<<(*lion).number<<" lion in blue headquarter"<<std::endl;
            std::cout<<"It's loyalty is "<<(*lion).loyalty<<std::endl;
        } else if (construct==1&&M>=life[order[1]]){
            ++serial_number;
            M-=life[order[1]];
            double morale=(M*1.0)/life[order[1]];
            auto *dragon=new Dragon(++number[order[1]],++attack[order[1]],life[order[1]],morale);
            Vector_dragon.emplace_back(dragon);
            flag= false;
            std::cout<<"blue dragon "<<serial_number<<" born with strength "<<(*dragon).life<<","<<(*dragon).number<<" dragon in blue headquarter"<<std::endl;
            std::cout<<"It has a "<<(*dragon).weapon<<",and its morale is "<<std::fixed<<std::setprecision(2)<<(*dragon).morale<<std::endl;
        } else if (construct==2&&M>=life[order[2]]){
            ++serial_number;
            M-=life[order[2]];
            auto *ninja=new Ninja(++number[order[2]],++attack[order[2]],life[order[2]]);
            Vector_ninja.emplace_back(ninja);
            flag=false;
            std::cout<<"blue ninja "<<serial_number<<" born with strength "<<(*ninja).life<<","<<(*ninja).number<<" ninja in blue headquarter"<<std::endl;
            std::cout<<"It has a "<<(*ninja).weapon1<<" and a "<<(*ninja).weapon2<<std::endl;
        } else if (construct==3&&M>=life[order[3]]){
            ++serial_number;
            M-=life[order[3]];
            auto *iceman=new Iceman(++number[order[3]],++attack[order[3]],life[order[3]]);
            Vector_iceman.emplace_back(iceman);
            flag= false;
            std::cout<<"blue iceman "<<serial_number<<" born with strength "<<(*iceman).life<<","<<(*iceman).number<<" iceman in blue headquarter"<<std::endl;
            std::cout<<"It has a "<<(*iceman).weapon<<std::endl;
        } else if (construct==4&&M>=life[order[4]]){
            ++serial_number;
            M-=life[order[4]];
            auto *wolf=new Wolf(++number[order[4]],++attack[order[4]],life[order[4]]);
            Vector_wolf.emplace_back(wolf);
            flag=false;
            std::cout<<"blue wolf "<<serial_number<<" born with strength "<<(*wolf).life<<","<<(*wolf).number<<" wolf in blue headquarter"<<std::endl;
        }
        construct=(construct+1)%5;
    }
}

Blue_headquarter::~Blue_headquarter() {
    for (auto & item : Vector_wolf) {
        delete item;
    }
    for (auto &item: Vector_iceman){
        delete item;
    }
    for (auto &item: Vector_dragon){
        delete item;
    }
    for (auto &item: Vector_lion){
        delete item;
    }
    for (auto &item: Vector_ninja){
        delete item;
    }
    Vector_lion.clear();
    Vector_wolf.clear();
    Vector_ninja.clear();
    Vector_dragon.clear();
    Vector_iceman.clear();
}

void Red_headquarter::generate() {
    bool flag= true;
    while (on&& flag){
        if (M<stop){
            std::cout<<"red headquarter stops making warriors"<<std::endl;
            on= false;
            break;
        } else if (construct==0&&M>=life[order[0]]){
            ++serial_number;
            M-=life[order[0]];
            auto *iceman=new Iceman(++number[order[0]],++attack[order[0]],life[order[0]]);
            Vector_iceman.emplace_back(iceman);
            flag= false;
            std::cout<<"red iceman "<<serial_number<<" born with strength "<<(*iceman).life<<","<<(*iceman).number<<" iceman in red headquarter"<<std::endl;
        } else if (construct==1&&M>=life[order[1]]){
            ++serial_number;
            M-=life[order[1]];
            auto *lion=new Lion(++number[order[1]],++attack[order[1]],life[order[1]],M);
            Vector_lion.emplace_back(lion);
            flag= false;
            std::cout<<"red lion "<<serial_number<<" born with strength "<<(*lion).life<<","<<(*lion).number<<" lion in red headquarter"<<std::endl;
            std::cout<<"It's loyalty is "<<(*lion).loyalty<<std::endl;
        } else if (construct==2&&M>=life[order[2]]){
            ++serial_number;
            M-=life[order[2]];
            auto *wolf=new Wolf(++number[order[2]],++attack[order[2]],life[order[2]]);
            Vector_wolf.emplace_back(wolf);
            flag=false;
            std::cout<<"red wolf "<<serial_number<<" born with strength "<<(*wolf).life<<","<<(*wolf).number<<" wolf in red headquarter"<<std::endl;
        } else if (construct==3&&M>=life[order[3]]){
            ++serial_number;
            M-=life[order[3]];
            auto *ninja=new Ninja(++number[order[3]],++attack[order[3]],life[order[3]]);
            Vector_ninja.emplace_back(ninja);
            flag=false;
            std::cout<<"red ninja "<<serial_number<<" born with strength "<<(*ninja).life<<","<<(*ninja).number<<" ninja in red headquarter"<<std::endl;
            std::cout<<"It has a "<<(*ninja).weapon1<<" and a "<<(*ninja).weapon2<<std::endl;
        } else if (construct==4&&M>=life[order[4]]){
            ++serial_number;
            M-=life[order[4]];
            double morale=M*1.0/(life[order[4]]);
            auto *dragon=new Dragon(++number[order[4]],++attack[order[4]],life[order[4]],morale);
            Vector_dragon.emplace_back(dragon);
            flag= false;
            std::cout<<"red dragon "<<serial_number<<" born with strength "<<(*dragon).life<<","<<(*dragon).number<<" dragon in red headquarter"<<std::endl;
            std::cout<<"It has a "<<(*dragon).weapon<<",and its morale is "<<std::fixed<<std::setprecision(2)<<(*dragon).morale<<std::endl;
        }
        construct=(construct+1)%5;
    }
}

Red_headquarter::~Red_headquarter() {
    for (auto & item : Vector_wolf) {
        delete item;
    }
    for (auto &item: Vector_iceman){
        delete item;
    }
    for (auto &item: Vector_dragon){
        delete item;
    }
    for (auto &item: Vector_lion){
        delete item;
    }
    for (auto &item: Vector_ninja){
        delete item;
    }
    Vector_lion.clear();
    Vector_wolf.clear();
    Vector_ninja.clear();
    Vector_dragon.clear();
    Vector_iceman.clear();
}

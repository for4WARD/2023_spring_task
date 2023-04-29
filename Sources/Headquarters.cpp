#include "../Headers/Headquarters.h"
#include <iomanip>
Blue_headquarter::Blue_headquarter(const int *Life_value, int m, const int *attack_value,int K) {
    this->K=K;
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
Red_headquarter::Red_headquarter(const int *Life_value, int m, const int *attack_value,int K) {
    this->K=K;
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
int Blue_headquarter::generate(){
    while (on){
        if (M<stop){
            on= false;
            return -1;
        } else if (construct==0&&M>=life[order[0]]){
            ++serial_number;
            M-=life[order[0]];
            int loyalty=M;
            auto *lion=new Lion(++number[order[0]],++attack[order[0]],life[order[0]],loyalty,K);
            std::cout<<"blue lion "<<(*lion).number<<" born"<<std::endl;
            std::cout<<"It's loyalty is "<<(*lion).loyalty<<std::endl;
            return 3;
        } else if (construct==1&&M>=life[order[1]]){
            ++serial_number;
            M-=life[order[1]];
            double morale=(M*1.0)/life[order[1]];
            auto *warrior=new Dragon(++number[order[1]],++attack[order[1]],life[order[1]],morale);
            vector_warrior.emplace_back(warrior);
            std::cout<<"blue dragon "<<(*warrior).number<<" born"<<std::endl;
            return 0;
        } else if (construct==2&&M>=life[order[2]]){
            ++serial_number;
            M-=life[order[2]];
            auto *warrior=new Ninja(++number[order[2]],++attack[order[2]],life[order[2]]);
            vector_warrior.emplace_back(warrior);
            std::cout<<"blue ninja "<<(*warrior).number<<" born"<<std::endl;
            return 1;
        } else if (construct==3&&M>=life[order[3]]){
            ++serial_number;
            M-=life[order[3]];
            auto *iceman=new Iceman(++number[order[3]],++attack[order[3]],life[order[3]]);
            vector_warrior.emplace_back(iceman);
            std::cout<<"blue iceman "<<(*iceman).number<<" born"<<std::endl;
            return 2;
        } else if (construct==4&&M>=life[order[4]]){
            ++serial_number;
            M-=life[order[4]];
            auto *wolf=new Wolf(++number[order[4]],++attack[order[4]],life[order[4]]);
            vector_warrior.emplace_back(wolf);
            std::cout<<"blue wolf "<<(*wolf).number<<" born"<<std::endl;
            return 4;
        }
        construct=(construct+1)%5;
    }
}

Blue_headquarter::~Blue_headquarter() {
    for (auto & item : vector_warrior) {
        delete item;
    }
    vector_warrior.clear();
}

int Red_headquarter::generate() {
    while (on){
        if (M<stop){
            std::cout<<"red headquarter stops making warriors"<<std::endl;
            on= false;
            return -1;
        } else if (construct==0&&M>=life[order[0]]){
            ++serial_number;
            M-=life[order[0]];
            auto *iceman=new Iceman(++number[order[0]],++attack[order[0]],life[order[0]]);
            vector_warrior.emplace_back(iceman);
            std::cout<<"red iceman "<<(*iceman).number<<" born"<<std::endl;
            return 2;
        } else if (construct==1&&M>=life[order[1]]){
            ++serial_number;
            M-=life[order[1]];
            auto *lion=new Lion(++number[order[1]],++attack[order[1]],life[order[1]],M,K);
            vector_warrior.emplace_back(lion);
            std::cout<<"red lion "<<(*lion).number<<" born"<<std::endl;
            std::cout<<"It's loyalty is "<<(*lion).loyalty<<std::endl;
            return 3;
        } else if (construct==2&&M>=life[order[2]]){
            ++serial_number;
            M-=life[order[2]];
            auto *wolf=new Wolf(++number[order[2]],++attack[order[2]],life[order[2]]);
            vector_warrior.emplace_back(wolf);
            std::cout<<"red wolf "<<(*wolf).number<<" born"<<std::endl;
            return 4;
        } else if (construct==3&&M>=life[order[3]]){
            ++serial_number;
            M-=life[order[3]];
            auto *ninja=new Ninja(++number[order[3]],++attack[order[3]],life[order[3]]);
            vector_warrior.emplace_back(ninja);
            std::cout<<"red ninja "<<(*ninja).number<<" born"<<std::endl;
            return 1;
        } else if (construct==4&&M>=life[order[4]]){
            ++serial_number;
            M-=life[order[4]];
            double morale=M*1.0/(life[order[4]]);
            auto *dragon=new Dragon(++number[order[4]],++attack[order[4]],life[order[4]],morale);
            vector_warrior.emplace_back(dragon);
            std::cout<<"red dragon "<<(*dragon).number<<" born"<<std::endl;
            return 0;
        }
        construct=(construct+1)%5;
    }
}

Red_headquarter::~Red_headquarter() {
    for (auto & item : vector_warrior) {
        delete item;
    }
    vector_warrior.clear();
}

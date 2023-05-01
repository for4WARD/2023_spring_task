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
    if (life[order[0]]>M) {
        on = false;
    }
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
    if (life[order[0]]>M) {
        on = false;
    }
}
int Blue_headquarter::generate(){
    while (on){
        if (construct==0){
            if (M<life[order[0]]){
                on= false;
                return -1;
            }
            ++number[order[0]];
            M-=life[order[0]];
            if (M<life[order[1]]){
                on= false;
            }
            int loyalty=M;
            auto *lion=new Lion(++serial_number,attack[order[0]],life[order[0]],loyalty,K);
            lion->camp="blue";
            vector_warrior.emplace_back(lion);
            std::cout<<"blue lion "<<(*lion).number<<" born"<<std::endl;
            std::cout<<"Its loyalty is "<<(*lion).loyalty<<std::endl;
            construct=(construct+1)%5;
            return 3;
        } else if (construct==1&&M>=life[order[1]]){
            if (M<life[order[1]]){
                on= false;
                return -1;
            }
            ++number[order[1]];
            M-=life[order[1]];
            if (M<life[order[2]]){
                on= false;
            }
            double morale=(M*1.0)/life[order[1]];
            auto *warrior=new Dragon(++serial_number,attack[order[1]],life[order[1]],morale);
            warrior->camp="blue";
            vector_warrior.emplace_back(warrior);
            std::cout<<"blue dragon "<<(*warrior).number<<" born"<<std::endl;
            construct=(construct+1)%5;
            return 0;
        } else if (construct==2){
            if (M<life[order[2]]){
                on= false;
                return -1;
            }
            ++number[order[2]];
            M-=life[order[2]];
            if (M<life[order[3]]){
                on= false;
            }
            auto *warrior=new Ninja(++serial_number,attack[order[2]],life[order[2]]);
            warrior->camp="blue";
            vector_warrior.emplace_back(warrior);
            std::cout<<"blue ninja "<<(*warrior).number<<" born"<<std::endl;
            construct=(construct+1)%5;
            return 1;
        } else if (construct==3&&M>=life[order[3]]){
            if (M<life[order[3]]){
                on= false;
                return -1;
            }
            ++number[order[3]];
            M-=life[order[3]];
            if (M<life[order[4]]){
                on= false;
            }
            auto *iceman=new Iceman(++serial_number,attack[order[3]],life[order[3]]);
            iceman->camp="blue";
            vector_warrior.emplace_back(iceman);
            std::cout<<"blue iceman "<<(*iceman).number<<" born"<<std::endl;
            construct=(construct+1)%5;
            return 2;
        } else if (construct==4){
            if (M<life[order[4]]){
                on= false;
                return -1;
            }
            ++number[order[4]];
            M-=life[order[4]];
            if (M<life[order[0]]){
                on= false;
            }
            auto *wolf=new Wolf(++serial_number,attack[order[4]],life[order[4]]);
            wolf->camp="blue";
            vector_warrior.emplace_back(wolf);
            std::cout<<"blue wolf "<<(*wolf).number<<" born"<<std::endl;
            construct=(construct+1)%5;
            return 4;
        }

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
        if (construct==0){
            if (M<life[order[0]]){
                on= false;
                return -1;
            }
            ++number[order[0]];
            M-=life[order[0]];
            if (M<life[order[1]]){
                on= false;
            }
            auto *iceman=new Iceman(++serial_number,attack[order[0]],life[order[0]]);
            iceman->camp="red";
            vector_warrior.emplace_back(iceman);
            std::cout<<"red iceman "<<(*iceman).number<<" born"<<std::endl;
            construct=(construct+1)%5;
            return 2;
        } else if (construct==1){
            if (M<life[order[1]]){
                on= false;
                return -1;
            }
            ++number[order[1]];
            M-=life[order[1]];
            if (M<life[order[2]]){
                on= false;
            }
            auto *lion=new Lion(++serial_number,attack[order[1]],life[order[1]],M,K);
            lion->camp="red";
            vector_warrior.emplace_back(lion);
            std::cout<<"red lion "<<(*lion).number<<" born"<<std::endl;
            std::cout<<"Its loyalty is "<<(*lion).loyalty<<std::endl;
            construct=(construct+1)%5;
            return 3;
        } else if (construct==2){
            if (M<life[order[2]]){
                on= false;
                return -1;
            }
            ++number[order[2]];
            M-=life[order[2]];
            if (M<life[order[3]]){
                on= false;
            }
            auto *wolf=new Wolf(++serial_number,attack[order[2]],life[order[2]]);
            wolf->camp="red";
            vector_warrior.emplace_back(wolf);
            std::cout<<"red wolf "<<(*wolf).number<<" born"<<std::endl;
            construct=(construct+1)%5;
            return 4;
        } else if (construct==3){
            if (M<life[order[3]]){
                on= false;
                return -1;
            }
            ++number[order[3]];
            M-=life[order[3]];
            if (M<life[order[4]]){
                on= false;
            }
            auto *ninja=new Ninja(++serial_number,attack[order[3]],life[order[3]]);
            ninja->camp="red";
            vector_warrior.emplace_back(ninja);
            std::cout<<"red ninja "<<(*ninja).number<<" born"<<std::endl;
            construct=(construct+1)%5;
            return 1;
        } else if (construct==4){
            if (M<life[order[4]]){
                on= false;
                return -1;
            }
            ++number[order[4]];
            M-=life[order[4]];
            if (M<life[order[0]]){
                on= false;
            }
            double morale=M*1.0/(life[order[4]]);
            auto *dragon=new Dragon(++serial_number,attack[order[4]],life[order[4]],morale);
            dragon->camp="red";
            vector_warrior.emplace_back(dragon);
            std::cout<<"red dragon "<<(*dragon).number<<" born"<<std::endl;
            construct=(construct+1)%5;
            return 0;
        }
    }
}

Red_headquarter::~Red_headquarter() {
    for (auto & item : vector_warrior) {
        delete item;
    }
    vector_warrior.clear();
}

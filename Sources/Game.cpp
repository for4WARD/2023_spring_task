#include "../Headers/Game.h"
#include <iomanip>
std::string color_str[2] = { "red","blue" };
std::string warrior_str[5] = { "dragon","ninja","iceman","lion","wolf" };
std::string weapon_str[3] = { "sword","bomb","arrow" };
void Game::Run() {
    int m,n,k,t;
    int life[5];
    int attack[5];
    std::cin>>m>>n>>k>>t;
    for (int i = 0; i < 5; ++i) {
        std::cin>>life[i];
        attack[i]=2;
    }
    Blue_headquarter blue_headquarter(life,m,attack,k);
    Red_headquarter red_headquarter(life,m,attack,k);
    int time=0;
    while(red_headquarter.on||blue_headquarter.on){
        if (red_headquarter.on){
            std::cout << std::setw(3) << std::setfill('0') << time<<" " ;
            red_headquarter.generate();
        }
        if (blue_headquarter.on){
            std::cout << std::setw(3) << std::setfill('0') << time<<" " ;
            blue_headquarter.generate();
        }
        time+=1;
    }
}
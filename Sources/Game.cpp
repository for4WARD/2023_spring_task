#include "../Headers/Game.h"
#include <iomanip>
void Game::Run() {
    int m;
    int life[5];
    int attack[5];
    std::cin>>m;
    for (int i = 0; i < 5; ++i) {
        std::cin>>life[i];
        attack[i]=2;
    }
    Blue_headquarter blue_headquarter(life,m,attack);
    Red_headquarter red_headquarter(life,m,attack);
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
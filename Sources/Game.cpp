#include "../Headers/Game.h"
#include <iomanip>

std::string color_str[2] = {"red", "blue"};
std::string warrior_str[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
std::string weapon_str[3] = {"sword", "bomb", "arrow"};

void Game::Run() {
    int win = -1;//0 for red，1 for blue 2 for tie
    int m, n, k, t;
    int life[5];
    int attack[5];
    std::cin >> m >> n >> k >> t;
    for (int i = 0; i < 5; ++i) {
        std::cin >> life[i];
    }
    for (int i = 0; i < 5; ++i) {
        std::cin >> attack[i];
    }
    Blue_headquarter blue_headquarter(life, m, attack, k);
    Red_headquarter red_headquarter(life, m, attack, k);
    Map map(n);
    int time = 0;
    while (time <= t&&win==-1) {
        int red_flag = -1;
        int blue_flag = -1;
        if (time % 60 == 0) {
            if (red_headquarter.on) {
                std::cout << std::setw(3) << std::setfill('0') << (time / 60) << ":00 ";
                red_flag = red_headquarter.generate();
                if (red_flag == -1) {
                    red_headquarter.update = false;
                }
            }else{
                red_headquarter.update= false;
            }
            if (blue_headquarter.on) {
                std::cout << std::setw(3) << std::setfill('0') << (time / 60) << ":00 ";
                blue_flag = blue_headquarter.generate();
                if (blue_flag == -1) {
                    blue_headquarter.update = false;
                }
            }else{
                blue_headquarter.update= false;
            }
        }
        else if (time % 60 == 5) {
            for (auto &item: red_headquarter.vector_warrior) {
                if (item->type_num == 3 && !item->dead) {
                    Lion *l = static_cast<Lion *>(item);
                    if (l->flee) {
                        l->dead = true;
                        std::cout << std::setw(3) << std::setfill('0') << (time / 60) << ":05 ";
                        l->ran_away();
                    }
                }
            }
            for (auto &item: blue_headquarter.vector_warrior) {
                if (item->type_num == 3 && !item->dead) {
                    Lion *l = static_cast<Lion *>(item);
                    if (l->flee) {
                        l->dead = true;
                        std::cout << std::setw(3) << std::setfill('0') << (time / 60) << ":05 ";
                        l->ran_away();
                    }
                }
            }
        }
        else if (time % 60 == 10) {
            int hour=time/60;
            if (red_headquarter.update) {
                map.red_cities[0]->red = red_headquarter.vector_warrior[hour];
            }
            if (blue_headquarter.update) {
                map.blue_cities[0]->blue = blue_headquarter.vector_warrior[hour];
            }
            map.forge();
            for (auto &item: red_headquarter.vector_warrior) {
                if (item->type_num == 3 && !item->dead) {
                    Lion *l = static_cast<Lion *>(item);
                    l->forge();
                }
                if (item->type_num == 2 && !item->dead) {
                    Iceman *i = static_cast<Iceman *>(item);
                    i->forge();
                }
            }
            for (auto &item: blue_headquarter.vector_warrior) {
                if (item->type_num == 3 && !item->dead) {
                    Lion *l = static_cast<Lion *>(item);
                    l->forge();
                }
                if (item->type_num == 2 && !item->dead) {
                    Iceman *i = static_cast<Iceman *>(item);
                    i->forge();
                }
            }//完成移动
            auto city_red=map.red_cities[n+1];
            auto city_blue=map.blue_cities[n+1];
            if (city_blue->blue!= nullptr){
                auto blue=city_blue->blue;
                std::cout << std::setw(3) << std::setfill('0') << (time / 60) << ":10 " << blue->camp << " "
                          << blue->name << " " << blue->number << " marched to blue headquarter" 
                          << " with " << blue->life << " elements and force " << blue->attack << std::endl;
                std::cout << std::setw(3) << std::setfill('0') << (time / 60) << ":10 blue headquarter was taken"<<std::endl;
                win=1;
            }
            for (int i=1;i<=n;i++) {
                auto item=map.red_cities[i];
                if (item->red != nullptr) {
                    auto red = item->red;
                    std::cout << std::setw(3) << std::setfill('0') << (time / 60) << ":10 " << red->camp << " "
                              << red->name << " " << red->number << " marched to city " << item->number
                              << " with " << red->life << " elements and force " << red->attack << std::endl;

                }
                if (item->blue != nullptr) {
                    auto blue = item->blue;
                    std::cout << std::setw(3) << std::setfill('0') << (time / 60) << ":10 " << blue->camp << " "
                              << blue->name << " " << blue->number << " marched to city " << item->number
                              << " with " << blue->life << " elements and force " << blue->attack << std::endl;

                }
            }
            if (city_red->red!= nullptr){
                auto red=city_red->red;
                std::cout << std::setw(3) << std::setfill('0') << (time / 60) << ":10 " << red->camp << " "
                          << red->name << " " << red->number << " marched to red headquarter"
                          << " with " << red->life << " elements and force " << red->attack << std::endl;
                std::cout << std::setw(3) << std::setfill('0') << (time / 60) << ":10 red headquarter was taken"<<std::endl;
                if (win==1){
                    win=2;
                }else{
                    win=0;
                }
            }
        }
        else if (time % 60 == 35){
            for (int i = 1; i <=n ; ++i) {
                auto city=map.red_cities[i];
                city->steal(time);
            }
        }
        else if (time % 60 == 40){
            for (int i = 1; i <=n ; ++i) {
                auto city=map.red_cities[i];
                city->fight(time);
            }
        }
        else if (time % 60 == 50) {
            std::cout << std::setw(3) << std::setfill('0') << (time / 60) << ":50 " << red_headquarter.M
                      << " elements in red headquarter" << std::endl;
            std::cout << std::setw(3) << std::setfill('0') << (time / 60) << ":50 " << blue_headquarter.M
                      << " elements in blue headquarter" << std::endl;
        }
        else if (time % 60 == 55){
            for (int i = 1; i <=n ; ++i) {
                auto city=map.red_cities[i];
                if (city->red!= nullptr&&!city->red->dead){
                    auto red=city->red;
                    std::cout<<std::setw(3)<<std::setfill('0')<<(time/60)<<":55 "<<red->camp<<" "<<red->name<<" "<<red->number
                    <<" has "<<red->weapon_count[0]<<" sword "<<red->weapon_count[1]<<" bomb "<<red->weapon_count[2]<<" arrow and "
                    <<red->life<<" elements"<<std::endl;
                }
                if (city->blue!= nullptr&&!city->blue->dead){
                    auto blue=city->blue;
                    std::cout<<std::setw(3)<<std::setfill('0')<<(time/60)<<":55 "<<blue->camp<<" "<<blue->name<<" "<<blue->number
                             <<" has "<<blue->weapon_count[0]<<" sword "<<blue->weapon_count[1]<<" bomb "<<blue->weapon_count[2]<<" arrow and "
                             <<blue->life<<" elements"<<std::endl;
                }
            }
            
        }
        time += 5;
    }
}
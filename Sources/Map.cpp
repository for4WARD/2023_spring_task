#include "../Headers/Map.h"

Map::Map(int num_of_city) {
    this->num_of_city=num_of_city;
    for (int i = 0; i <=num_of_city+1 ; ++i) {
        City *city=new City(i,num_of_city);
        red_cities[i]=city;
        blue_cities[num_of_city-i+1]=city;
    }
}

void Map::forge() {
    for (int i = num_of_city+1; i >=0 ; --i) {
        if (red_cities[i]->red!= nullptr&&red_cities[i]->red->dead) {
            red_cities[i]->red= nullptr;
        }
        if (blue_cities[i]->blue!= nullptr&&blue_cities[i]->blue->dead){
            blue_cities[i]->blue= nullptr;
        }
    }
    for (int i = num_of_city+1; i >=1 ; --i) {
        red_cities[i]->red=red_cities[i-1]->red;
        blue_cities[i]->blue=blue_cities[i-1]->blue;
    }
}
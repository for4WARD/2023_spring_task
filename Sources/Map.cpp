#include "../Headers/Map.h"

Map::Map(int num_of_city) {
    this->num_of_city=num_of_city;
    for (int i = 1; i <=num_of_city ; ++i) {
        City *city=new City(i,num_of_city);
        red_cities[i]=city;
        blue_cities[num_of_city-i+1]=city;
    }
}

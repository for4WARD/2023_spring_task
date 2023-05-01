#include "./Headers/Game.h"
int main(){
//    freopen("../test.in","r+",stdin);
//    freopen("../test.out","w+",stdout);
    int cases;
    std::cin>>cases;
    for (int i = 0; i < cases; ++i){
        std::cout<<"Case "<<(i+1)<<":"<<std::endl;
        Game game;
        game.Run();
    }
    system("pause");
}

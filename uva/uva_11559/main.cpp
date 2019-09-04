#include <iostream>

using namespace std;

int main()
{
    int part;
    int budget;
    int hotels;
     int weeks;

    while(cin >> part >> budget >> hotels>> weeks){
       int min_cost = -1;
        for(int i = 0; i < hotels; i++){
            int cost;
            cin >> cost;
            int total_cost = part * cost;
            for(int j = 0; j < weeks; j++){
                int rooms;
                cin >> rooms;
                if(rooms >= part && total_cost <= budget && (total_cost < min_cost || min_cost ==-1)){
                    min_cost = total_cost;
                }
            }
        }
        if(min_cost == -1){
            cout << "stay home" << endl;
        }else{
            cout << min_cost << endl;
        }


    }


    return 0;
}

#include <iostream>
#include <tuple>
using namespace std;

int main()
{
    int x = 4;
    int y = 5;

    auto t = tie(x,y);
    //tuple<int,int> t = tie(x,y);
    //auto t = tie(x,y);
    int &z = get<0>(t);
    z+=3;
    cout << get<0>(t) << endl;
    cout << get<1>(t) << endl;


    return 0;
}

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream cout("out.txt");

    int h;
    int l;
    cin >> h;

    while(h != 0)
    {
        cin >> l;
        int el;
        int prev;
        int total = 0;
        for(int i = 0; i < l; i++){
            cin >> el;
            if (i == 0 ){
                total = h-el;
            }else{
                total+= max( h - el - prev,0 );
            }
            prev = h - el;
        }


        cout << total<<endl;
        cin >> h;
    }


    return 0;
}

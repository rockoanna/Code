#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    while(a!=0 || b!=0 || c!=0 || d!=0){
        int move = 0;
        if(a <= b){
            move += (40+ a -b);
        }else{
            move += (a - b);
        }

        if(b < c){
            move += c - b;
        }else{
            move += 40 - (b - c);
        }

        if(c <= d){
            move += (40+ c - d);
        }else{
            move += (c - d);
        }
        cout   << (move*9 + 360*3)<<endl;
        cin>>a>>b>>c>>d;
    }
    return 0;
}

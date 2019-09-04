#include <iostream>
#include <string>

using namespace std;

string process(int x0, int y0, int x, int y){
            if(x > x0 && y > y0){
                return "NE";
            }else{
                if(x < x0 && y > y0){
                    return "NO";
                }else{
                    if(x < x0 && y < y0){
                        return "SO";
                    }else{
                        if(x > x0 && y < y0){
                            return "SE";
                        }else{
                            return "divisa";
                        }
                    }
                }
            }
}

int main()
{
    int n;
    cin >> n;
    while(n != 0){
        int x0;
        int y0;
        cin >> x0;
        cin >> y0;
        for(int i = 0; i < n; i++){
            int x;
            int y;
            cin >> x;
            cin >> y;
            cout<<process(x0,y0,x,y)<<endl;
        }
        cin >> n;
    }
    return 0;
}

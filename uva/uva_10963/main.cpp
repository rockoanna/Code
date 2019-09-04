#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int w;
        cin >> w;
        int count_ = 1;

        int x1;
        cin >> x1;
        int x2;
        cin >> x2;
        int dif = abs(x1 - x2);

        for(int j = 1; j < w; j++){
            int y1;
            cin >> y1;
            int y2;
            cin >> y2;
            if(abs(y1 - y2) == dif){
                count_ += 1;
            }

        }
        if(count_ == w){
            cout << "yes" <<endl;
        }else{
            cout << "no" << endl;
        }
        if(i < n - 1){
            cout << endl;
        }
    }


    return 0;
}

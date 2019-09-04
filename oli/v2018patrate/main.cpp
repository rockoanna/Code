#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned int m;
    cin >> m;

    unsigned int n;
    cin >> n;

    unsigned int k = (2*m+1)*(2*m + 1) - (2*m -1)*(2*m -1);
    cout << k << endl;

     int x = floor(sqrt(n));
     if(x % 2 == 0){
        x -= 1;
     }

     int t = (x+1) / 2;
     cout << t << endl;

     return 0;
}

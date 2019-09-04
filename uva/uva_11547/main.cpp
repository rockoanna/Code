#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    for(int i = 0; i < t; i++){
        cin >> n;
        int res = (( n * 315) + 36962) / 10 % 10;
        cout << abs(res) << endl;
    }
    return 0;
}

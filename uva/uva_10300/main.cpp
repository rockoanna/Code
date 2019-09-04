#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int f;
        cin >> f;
        int sum = 0;
        for(int j = 0; j < f; j++){
            int y;
            cin >> y;
            int a;
            cin >> a;
            int e;
            cin >> e;

            sum += y*e;

        }
        cout << sum <<endl;

    }


    return 0;
}

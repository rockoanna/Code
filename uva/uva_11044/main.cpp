#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        int w;
        cin >> w;

        int h;
        cin >> h;

        int res = (w / 3 * 3)*(h / 3 * 3)/9;
        cout << res <<endl;
    }


    return 0;
}

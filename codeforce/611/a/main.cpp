#include <iostream>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int x = 0; x < n; x++)
    {
        int h;
        cin >> h;

        int m;
        cin >> m;

        int res = 0;
        res = (24 - h) * 60 - m;

        cout << res << endl;

    }

    return 0;
}

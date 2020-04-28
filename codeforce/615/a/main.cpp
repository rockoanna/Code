#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        int a;
        cin >> a;

        int b;
        cin >> b;

        int c;
        cin >> c;

        int n;
        cin >> n;

        vector<int> v(3);
        v[0] = a;
        v[1] = b;
        v[2] = c;

        sort(v.begin(), v.end());

        int x = v[2] - v[1];
        n -= x;

        int y = v[2] - v[0];
        n -= y;

        if(n > 0)
        {
            if(n % 3 == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            if(n == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }


    }

    return 0;
}

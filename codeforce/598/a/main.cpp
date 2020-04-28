#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        int b;
        cin >> b;

        int x;
        cin >> x;

        int sum;
        cin >> sum;

        bool yes = false;

        if(b >= sum)
        {
            cout << "YES" << endl;
            continue;
        }

        if(sum - min(sum / x, a) * x <= b)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int s;
    cin >> s;

    int v;
    cin >> v;

    int j;
    cin >> j;

    int tj;
    cin >> tj;

    int svj;
    cin >> svj;

    int m2 = min(min(j, v), s);
    int m1 = min(j, t);
    int res = 0;
    bool s1 = false;;

    if(tj < svj)
    {
        res += m2 * svj;
        j -= m2;
    }
    else
    {
        s1 = true;
        res += m1 * tj;
        j -= m1;
    }

    if(j != 0)
    {
        m2 = min(min(j, v), s);
        m1 = min(j, t);
        if(s1)
        {
            res += m2 * svj;
        }
        else
        {
            res += m1 * tj;
        }
    }

    cout << res << endl;

    return 0;
}

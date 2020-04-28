#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

typedef vector<int> vi;
typedef string st;
typedef stringstream ss;

inline ss in_line()
{
    st line;
    getline(cin, line);
    return ss(line);
}


int main()
{
    int n;
    cin >> n;
    vi nr(n);

    cin.ignore();
    ss line = in_line();

    int start = 0;
    vi b;
    b.reserve(n);
    vi e;
    e.reserve(n);
    int l = 0;

    line >> nr[0];
    for(int i = 1; i < n; i++)
    {
        line >> nr[i];
        if(nr[i] <= nr[i - 1])
        {
            b.push_back(start);
            e.push_back(i-1);
            l = max(l, i - start);
            start = i;
        }
    }
    b.push_back(start);
    e.push_back(n-1);
    l = max(l, n- start);

    if(b.size() > 1)
    {
        for(int i = 1; i < b.size(); i++)
        {
            if(e[i - 1] - 1 >= 0 && nr[e[i - 1] - 1]  < nr[b[i]])
            {
                l = max(l, e[i - 1] - b[i - 1] + e[i] - b[i] + 1);
            }

            if(b[i] + 1 < n  && nr[e[i - 1]] < nr[b[i] + 1])
            {
                l = max(l, e[i - 1] - b[i - 1] + 1 + e[i] - b[i]);
            }
        }
        cout << l << endl;

    }
    else
    {
        cout << n << endl;
    }


    return 0;
}

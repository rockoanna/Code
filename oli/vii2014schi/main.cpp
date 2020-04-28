#include <bits/stdc++.h>

using namespace std;

typedef int64_t i64;
typedef int32_t i32;
typedef uint64_t u64;
typedef uint32_t u32;
typedef string st;
typedef stringstream ss;

typedef double db;

typedef vector<i64> vl;
typedef vector<i32> vi;
typedef vector<char> vc;
typedef vector<db> vd;
typedef vector<st> vs;

typedef map<st,i32> st2i;
typedef map<st,i64> st2l;
typedef map<st,db> st2d;

typedef map<i64,i64> l2l;
typedef map<i64,i32> l2i;

typedef map<i32,i32> i2i;
typedef map<i32,i64> i2l;

int main()
{
    ios::sync_with_stdio(false);

    ofstream cout {"schi.out"};
    ifstream cin {"schi.in"};

    i64 n;
    cin >> n;

    map<i64, i64> m;
    i64 mx = -1;
    for(int i = 0; i < n; i++)
    {
        i64 x;
        cin >> x;

        if(x > mx)
        {
            mx = x;
            m[x] = i;
        }
    }

    i64 k;
    cin >> k;

    for(int q = 0; q < k; q++)
    {
        int z;
        cin >> z;

        auto t = m.find(z);
        if(t == m.end())
        {
            cout << 0;
        }
        else
        {
            auto nx = next(t);
            if(nx != m.end())
            {
                cout << (*nx).second - (*t).second;
            }
            else
            {
                cout << n - (*t).second;
            }
        }

        if(q + 1 < k)
        {
            cout << " ";
        }
    }



    return 0;
}

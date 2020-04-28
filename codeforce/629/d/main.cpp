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

    int t;
    cin >> t;

    for(int tt = 0; tt < t; tt++)
    {
        u64 n;
        cin >> n;

        vl v(n);
        i64 same = 0;
        bool okay = true;

        for(u64 i = 0; i < n; i++)
        {
            cin >> v[i];
            if(i == 0)
            {
                same = v[i];
            }
            else
            {
                if(v[i] != same)
                {
                    okay = false;
                }
            }
        }

        if(okay)
        {
            cout << 1 << endl;
            for(u64 i = 0; i < n; i++)
            {
                cout << 1 << " ";
            }

            cout << endl;

            continue;
        }

        vl c(n);
        c[0] = 1;

        u64 crt = 2;

        if(n % 2 == 0)
        {
            u64 nx = 2;
            for(u64 i = 1; i < n; i++)
            {
                c[i] = nx;
                if(nx == 1)
                {
                    nx = 2;
                }
                else
                {
                    nx = 1;
                }
            }
        }
        else
        {

            for(u64 i = 1; i < n; i++)
            {
                if(v[i] == v[i - 1])
                {
                    c[i] = c[i - 1];
                    continue;
                }

                if(c[i - 1] == 1)
                {
                    c[i] = 2;
                }
                else
                {
                    c[i] = 1;
                }
            }

            if(c[0] == c[n - 1] && v[0] != v[n - 1])
            {
                if(c[0] == c[1])
                {
                    c[0] = 2;
                }
                else
                {
                    crt += 1;
                    c[n - 1] = 3;
                }
            }

        }

        cout << crt << endl;
        for(auto i : c)
        {
            cout << i << " ";
        }

        cout << endl;
    }

    return 0;
}

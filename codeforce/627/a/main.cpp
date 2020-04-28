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

    i64 n;
    cin >> n;

    for(int x = 0; x < n; x++)
    {
        i64 c;
        cin >> c;

        i64 last = -1;
        bool okay = true;
        for(int i = 0; i < c; i++)
        {
            i64 h;
            cin >> h;

            if(!okay)
            {
                continue;
            }
            if(last == -1)
            {
                last = h;
                continue;
            }

            if(last > h)
            {
                if((last - h) % 2 == 1)
                {
                    okay = false;
                }
            }
            else
            {
                if((h - last) % 2 == 1)
                {
                    okay = false;
                }
            }
        }

        if(okay)
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

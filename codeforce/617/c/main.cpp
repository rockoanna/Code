#include <bits/stdc++.h>
#define g0 get<0>
#define g1 get<1>

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

    int nn;
    cin >> nn;

    for(int r = 0; r < nn; r++)
    {
        int e;
        cin >> e;

        string s;
        cin >> s;

        map<tuple<i64, i64>, i64> m;
        i64 x = 0;
        i64 y = 0;
        auto t = make_tuple(x, y);
        m.insert({t, 0});
        i64 l = e + 1;
        tuple<i64, i64> res;

        for(int i = 0; i < e; i++)
        {
            if(s[i] == 'L')
            {
                x -= 1;
            }
            else
            {
                if(s[i] == 'R')
                {
                    x += 1;
                }
                else
                {
                    if(s[i] == 'U')
                    {
                        y += 1;

                    }
                    else
                    {
                        y -= 1;
                    }
                }
            }

            auto d = make_tuple(x, y);
            auto mc = m.find(d);
            if(mc == m.end())
            {
                m.insert({d, i + 1});
            }
            else
            {
                if(l > i + 1 - mc->second)
                {
                    res = make_tuple(mc->second + 1, i + 1);
                    l = i + 1 - mc->second;
                }

                mc->second = i + 1;
            }
        }
        if(l == e + 1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << g0(res) << " " << g1(res) << endl;
        }

    }

    return 0;
}

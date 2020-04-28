#include <bits/stdc++.h>

using namespace std;

#define g0 get<0>
#define g1 get<1>

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

#define DEBUG

#ifdef DEBUG
#define dbg(var) {cerr << __LINE__ <<": "<< #var <<" = "<< var << std::endl;}
#else
#define dbg(var)
#endif

int main()
{
    u64 n;
    cin >> n;

    u64 q;
    cin >> q;

    vector<tuple<u64, u64>> v;
    v.reserve(q);

    map<tuple<u64, u64>, bool> m;

    for(u64 t = 0; t < q; t++)
    {
        u64 y;
        cin >> y;

        u64 x;
        cin >> x;

        tuple<u64, u64> tp = {x - 1, y - 1};

        bool found = false;
        for(u64 i = 0; i < v.size(); i++)
        {
            if(v[i] == tp)
            {
                m[tp] = !m[tp];
                found = true;
                break;
            }
        }

        if(!found)
        {
            v.push_back(tp);
            m[tp] = false;

            sort(v.begin(), v.end());
        }

        if(t == 0)
        {
            cout << "Yes" << endl;
            continue;
        }

        u64 len = v.size();

        bool pass = true;
        for(u64 i = 0; i < len; i++)
        {
            if(!m[v[i]])
            {
                bool up = (g1(v[i]) == 0);

                tuple<u64, u64> c;
                if(up)
                {
                    c = {g0(v[i]), g1(v[i]) + 1};
                }
                else
                {
                    c = {g0(v[i]), g1(v[i]) - 1};
                }

                found = binary_search(v.begin(), v.end(), c);
                if(found)
                {
                    pass = false;
                    break;
                }

                if(up && g0(v[i]) < n - 1)
                {
                    c = {g0(v[i]) + 1, g1(v[i]) + 1};
                }
                else
                {
                    if(!up && g0(v[i]) > 0)
                    {
                        c = {g0(v[i]) - 1, g1(v[i]) - 1};
                    }
                }

                found = binary_search(v.begin(), v.end(), c);
                if(found)
                {
                    pass = false;
                    break;
                }

                if(up && g0(v[i]) > 0)
                {
                    c = {g0(v[i]) - 1, g1(v[i]) + 1};
                }
                else
                {
                    if(!up && g0(v[i]) < n - 1)
                    {
                        c = {g0(v[i]) + 1, g1(v[i]) - 1};
                    }
                }

                found = binary_search(v.begin(), v.end(), c);
                if(found)
                {
                    pass = false;
                    break;
                }
            }
        }

        if(pass)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }

    }

    return 0;
}

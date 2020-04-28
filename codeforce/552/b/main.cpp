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


inline ss in_line()
{
    st line;
    getline(cin, line);
    return ss(line);
}

int main()
{
    u64 n;
    cin >> n;

    vector<u64> v;
    v.reserve(3);

    bool ok = true;

    for(u64 i = 0; i < n; i++)
    {
        u64 x;
        cin >> x;

        if(v.size() < 4)
        {
            bool found = binary_search(v.begin(), v.end(), x);
            if(found)
            {
                continue;
            }
            else
            {
                if(v.size() == 4)
                {
                    ok = false;
                }
                v.push_back(x);
                sort(v.begin(), v.end());
            }
        }
    }

    if(!ok)
    {
        cout << -1;
    }
    else
    {
        u64 len = v.size();
        if(len == 1)
        {
            cout << 0;
        }

        if(len == 2)
        {
            if((v[1] + v[0]) % 2 == 0)
            {
                cout << v[1] - (v[1] + v[0]) / 2;
            }
            else
            {
                cout << v[1] - v[0];
            }
        }

        if(len == 3)
        {
            if((v[2] + v[0]) % 2 == 0 && (v[0] + v[2]) / 2 == v[1])
            {
                cout << v[2] - v[1];
            }
            else
            {
                cout << -1;
            }
        }

        if(len > 3)
        {
            cout << -1;
        }
    }

    return 0;
}

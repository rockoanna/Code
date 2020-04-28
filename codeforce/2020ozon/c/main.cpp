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
    ios::sync_with_stdio(false);

    i64 n;
    cin >> n;

    i64 m;
    cin >> m;

    vector<i64> v(n);
    set<i64> s;

    bool cont = true;
    for(i64 i = 0; i < n; i++)
    {
        cin >> v[i];

        if(cont)
        {
            if(s.count(v[i] % m))
            {
                cont = false;
                break;
            }
            else
            {
                s.insert(v[i] % m);
            }
        }
    }

    if(!cont)
    {
        cout << 0;
    }
    else
    {
        i64 res = 1;
        for(i64 i = 0; i < n; i++)
        {
            for(i64 j = i + 1; j < n; j++)
            {
                res *= abs(v[i] - v[j]) % m;
                res %= m;
            }
        }

        res %= m;
        cout << res;
    }

    return 0;
}

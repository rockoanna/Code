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

u64 cmmdc(u64 a, u64 b)
{
    if(a < b)
    {
        u64 crt = a;
        a = b;
        b = crt;
    }

    if(a == b)
    {
        return a;
    }

    if(a == 1 || b == 1)
    {
        return 1;
    }

    if(a == 0)
    {
        return b;
    }

    if(b == 0)
    {
        return a;
    }

    return cmmdc(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);

    u64 n;
    cin >> n;

    vector<u64> v(n);

    for(u64 i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    u64 mx = v[n - 1];

    vl res;
    res.reserve(n);

    u64 gcd = 0;
    for(u64 i = 0; i < n - 1; i++)
    {
        if(v[i] < mx)
        {
            u64 x = mx - v[i];
            gcd = cmmdc(x, gcd);
            res.push_back(x);
        }
    }

    u64 len = res.size();
    u64 p = 0;
    for(u64 i = 0; i < len; i++)
    {
        p += res[i] / gcd;
    }

    cout << p << " " << gcd;

    return 0;
}

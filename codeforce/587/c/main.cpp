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



struct coordinates
{
    i64 x;
    i64 y;
    coordinates()
    {
        this->x=0;
        this->y=0;
    }
};

struct rec
{
    coordinates topr;
    coordinates bottoml;
};

bool intersection(rec& r1, rec& r2, rec& res)
{
    res.bottoml.x = 0;
    res.bottoml.y = 0;
    res.topr.x = 0;
    res.topr.y = 0;

    coordinates top;
    top.x = min(r1.topr.x, r2.topr.x);
    top.y = min(r1.topr.y, r2.topr.y);

    coordinates b;
    b.x = max(r1.bottoml.x, r2.bottoml.x);
    b.y = max(r1.bottoml.y, r2.bottoml.y);

    if(b.x > top.x || b.y > top.y)
    {
        return false;
    }

    res.topr = top;
    res.bottoml = b;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    /// white
    rec white;
    cin >> white.bottoml.x;
    cin >> white.bottoml.y;
    cin >> white.topr.x;
    cin >> white.topr.y;
    /// white

    /// black 1
    rec black1;
    cin >> black1.bottoml.x;
    cin >> black1.bottoml.y;
    cin >> black1.topr.x;
    cin >> black1.topr.y;
    /// black 1

    /// black 2
    rec black2;
    cin >> black2.bottoml.x;
    cin >> black2.bottoml.y;
    cin >> black2.topr.x;
    cin >> black2.topr.y;
    /// black 2

    u64 aw = abs(white.topr.x - white.bottoml.x) * abs(white.topr.y - white.bottoml.y);

    int flag = 0;

    rec r1;
    bool i1 = intersection(white, black1, r1);
    if(i1)
    {
        flag += 1;
    }
    u64 a1 = abs(r1.topr.x - r1.bottoml.x) * abs(r1.topr.y - r1.bottoml.y);

    rec r2;
    bool i2 = intersection(white, black2, r2);
    if(i2)
    {
        flag += 10;
    }
    u64 a2 = abs(r2.topr.x - r2.bottoml.x) * abs(r2.topr.y - r2.bottoml.y);



    switch(flag)
    {
    case 1:
        if(a1 >= aw)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }
        break;

    case 10:
        if(a2 >= aw)
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }
        break;

    case 11:
    {
        rec f;
        bool in = intersection(r1, r2, f);
        u64 a3 = abs(f.topr.x - f.bottoml.x) * abs(f.topr.y - f.bottoml.y);

        u64 res;
        if(!in)
        {
            res = a1 + a2;
        }
        else
        {
            res = a1 + a2 - a3;
        }

        if(res < aw)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        break;
    }

    case 0:
        cout << "YES";
        break;
    }

    return 0;
}

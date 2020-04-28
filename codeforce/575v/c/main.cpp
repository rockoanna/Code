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

struct pos
{
    i32 x;
    i32 y;
};

struct rec
{
    pos ll;
    pos ur;
};

bool intersection (rec r1, rec r2, rec& res)
{
    if(r1.ll.x > r2.ur.x || r1.ll.y > r2.ur.y || r2.ll.x > r1.ur.x || r2.ll.y > r1.ur.y)
    {
        return false;
    }

    res.ll.x = max(r1.ll.x, r2.ll.x);
    res.ll.y = max(r1.ll.y, r2.ll.y);
    res.ur.x = min(r1.ur.x, r2.ur.x);
    res.ur.y = min(r1.ur.y, r2.ur.y);

    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    u32 t;
    cin >> t;

    for(u32 tt = 0; tt < t; tt++)
    {
        i32 n;
        cin >> n;

        vector<rec> v(n);
        for(i32 i = 0; i < n; i++)
        {
            i64 x;
            cin >> x;

            i64 y;
            cin >> y;

            int l;
            cin >> l;

            int u;
            cin >> u;

            int ri;
            cin >> ri;

            int d;
            cin >> d;

            bool left = (l == 1);
            bool up = (u == 1);
            bool right = (ri == 1);
            bool down = (d == 1);

            rec r;

            if(left)
            {
                r.ll.x = -100000;
            }
            else
            {
                r.ll.x = x;
            }

            if(up)
            {
                r.ur.y = 100000;
            }
            else
            {
                r.ur.y = y;
            }

            if(right)
            {
                r.ur.x = 100000;
            }
            else
            {
                r.ur.x = x;
            }

            if(down)
            {
                r.ll.y = -100000;
            }
            else
            {
                r.ll.y = y;
            }

            v[i] = r;
        }

        if(n == 1)
        {
            cout << 1 << " " << v[0].ll.x << " " << v[0].ll.y << endl;
            continue;
        }

        rec res;
        bool valid = intersection(v[0], v[1], res);

        for(i64 i = 2; i < n && valid; i++)
        {
            valid = intersection(res, v[i], res);
        }

        if(!valid)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << " " << res.ll.x << " " << res.ll.y << endl;
        }

    }

    return 0;
}

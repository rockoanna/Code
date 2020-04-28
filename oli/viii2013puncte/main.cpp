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

i64 solve2(set<tuple<i64, i64>>& s)
{
    i64 res = 0;
    for(auto it0 = s.begin(); it0 != s.end(); it0++)
    {
        // cout << "it0 :" << get<0>(*it0) << " " << get<1>(*it0) << endl;

        set<double> slopes;
        for(auto it = s.begin(); it != s.end(); it++)
        {
            if(it == it0)
            {
                continue;
            }

            double slope =(get<1>(*it) - get<1>(*it0)) / double(get<0>(*it) - get<0>(*it0));

            auto f = slopes.find(slope);
            if(f == slopes.end())
            {
                res += 1;
           //     cout << setprecision(10);
             ///   cout << get<0>(*it) << " " << get<1>(*it) << " slooooope :" << slope << endl;
            }

            slopes.insert(slope);
        }
    }

    return res / 2;
}

int main()
{
    u64 n;
    cin >> n;

    map<i64, i64> x;
    map<i64, i64> y;
    i64 mx = 0;

    set<tuple<i64, i64>> s;

    for(int i = 0; i < n; i++)
    {
        i64 a;
        cin >> a;

        i64 b;
        cin >> b;

        x[a] += 1;
        y[b] += 1;

        mx = max(x[a], mx);
        mx = max(y[b], mx);

        if(a == b || a + b == 0)
        {
            s.insert({a, b});
        }
    }

    cout << mx << endl;
    cout << solve2(s) << endl;

    return 0;
}

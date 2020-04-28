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

typedef vector<i64> vi6;
typedef vector<u64> vu6;
typedef vector<i32> vi3;
typedef vector<u32> vu3;
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

    u64 t;
    cin >> t;

    for(u64 tt = 0; tt < t; tt++)
    {
        u64 n;
        cin >> n;

        u64 k;
        cin >> k;

        vector<u64> v(n);

        for(u64 i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        map<u64, u64> m;
        for(u64 i = 0; i < n / 2; i++)
        {
            u64 x = v[i] + v[n - i - 1];
            m[x] += 1;
        }

        if(m.size() == 1)
        {
            cout << 0 << endl;
            continue;
        }

        auto mx = m.rbegin();
        u64 y = mx->first;
        u64 c = 0;

        for(u64 i = 0; i < n / 2; i++)
        {
            u64 x = v[i] + v[n - i - 1];

            if(x != y)
            {
                c += 1;
                if(v[i] >= y && v[n - i - 1] >= y)
                {
                    c += 1;
                    continue;
                }

                if(v[i] == y || v[n - i - 1] == y)
                {
                    c += 1;
                    continue;
                }

                if(k + v[i] < y && k + v[n - i - 1] < y)
                {
                    cout << v[i] << " ******** " << v[n - i - 1] << endl;
                    c += 1;
                }
            }
        }

        cout << c << endl;
    }

    return 0;
}

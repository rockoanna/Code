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
    ios::sync_with_stdio(false);

    u64 n;
    cin >> n;

    u64 k;
    cin >> k;

    map<u64, u64> v2i;
    map<u64, u64> i2v;

    for(u64 i = 0; i < n; i++)
    {
        u64 v;
        cin >> v;

        v2i[v] = i;
        i2v[i] = v;
    }

    string res(n, '0');

    bool t = false;
    while(!v2i.empty())
    {
        char r;
        if(t)
        {
            r = '2';
        }
        else
        {
            r = '1';
        }

        auto mx = v2i.rbegin();
        auto mxv = (*mx).second;

        auto fi = i2v.find(mxv);

        u64 times = 0;
        auto crt = fi;
        crt++;
        while(times < k)
        {
            if(crt == i2v.end())
            {
                break;
            }
            else
            {
                auto idx = (*crt).first;
                res[idx] = r;
                v2i.erase(crt->second);
                crt = i2v.erase(crt);
                times += 1;
            }
        }

        crt = fi;
        times = 0;
        while(times < k)
        {
            if(crt == i2v.begin())
            {
                break;
            }
            auto prev = --crt;
            auto idx = (*prev).first;
            res[idx] = r;
            v2i.erase(prev->second);
            crt = i2v.erase(prev);
            times += 1;
        }

        auto idx = (*fi).first;
        res[idx] = r;
        i2v.erase(fi);

        v2i.erase((*mx).first);

        t = !t;
    }

    cout << res;
    return 0;
}

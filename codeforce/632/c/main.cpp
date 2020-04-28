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

i64 solve(vector<i64>& v, i64 si, i64 ei)
{
    if(si >= v.size() || ei < 0)
    {
        return 0;
    }

    if(si > ei)
    {
        return 0;
    }

    if(si == ei)
    {
        if(v[si] != 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    map<i64, i64> idx2s;
    i64 crt_t = 0;
    for(i64 i = si; i <= ei; i++)
    {
        crt_t += v[i];
        if(crt_t == 0)
        {
            return (i - si) * (i - si + 1) / 2 + solve(v, si + 1, ei) - solve(v, si + 1, i - 1);
        }
        else
        {
            auto fd = idx2s.find(crt_t);
            if(fd == idx2s.end())
            {
                idx2s.insert({crt_t, i});
            }
            else
            {
                i64 j = fd->second;
                return (i - si) * (i - si + 1) / 2 + solve(v, j + 1, ei) - solve(v, j + 1, i - 1);
            }
        }
    }

    i64 n = ei - si + 1;
    return n * (n + 1) / 2;
}

int main()
{
    ios::sync_with_stdio(false);

    i64 n;
    cin >> n;

    vector<i64> v(n);
    for(i64 i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << solve(v, 0, n - 1) << endl;

    return 0;
}

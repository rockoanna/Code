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

    vector<tuple<u64, u64>> v(n);
    for(u64 i = 0; i < n; i++)
    {
        u64 x;
        cin >> x;

        v[i] = {x, i + 1};
    }

    sort(v.rbegin(), v.rend());

    u64 res = 0;
    for(u64 i = 0; i < n; i++){
        res += g0(v[i]) * i + 1;
    }

    cout << res << endl;
    for(auto i : v){
        cout << g1(i) << " ";
    }

    return 0;
}

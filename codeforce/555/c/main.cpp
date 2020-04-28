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

    u64 len;
    cin >> len;

    deque<u64> v(len);
    for(u64 i = 0; i < len; i++)
    {
        cin >> v[i];
    }

    string res = "";

    u64 len_c = len;
    u64 last = 0;

    for(u64 i = 0; i < len_c; i++)
    {
        len = v.size();
        if(v[0] > last && (v[0] <= v[len - 1] || v[len - 1] < last))
        {
            last = v[0];

            res.push_back('L');
            v.pop_front();
            continue;
        }

        if(v[len - 1] > last && (v[len - 1] <= v[0] || v[0] < last))
        {
            last = v[len - 1];

            res.push_back('R');
            v.pop_back();
            continue;
        }

        break;
    }

    cout << res.size() << endl;
    cout << res << endl;

    return 0;
}

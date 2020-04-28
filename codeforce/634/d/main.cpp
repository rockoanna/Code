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

void change(string& s, vector<u64>& v)
{
    u64 len = 9;
    v.reserve(9);

    for(u64 i = 0; i < len; i++)
    {
        v.push_back(s[i] - '0');
    }
}

int main()
{
    ios::sync_with_stdio(false);

    u64 t;
    cin >> t;

    for(u64 tt = 0; tt < t; tt++)
    {
        string s;

        vector<vector<u64>> v(9);
        for(u64 i = 0; i < 9; i++)
        {
            cin >> s;
            change(s, v[i]);
        }

        v[0][1] = v[1][1];
        v[1][4] = v[2][4];
        v[0][7] = v[2][7];

        v[3][1] = v[4][1];
        v[4][4] = v[5][4];
        v[3][7] = v[5][7];

        v[6][1] = v[7][1];
        v[7][4] = v[8][4];
        v[6][7] = v[8][7];


        for(auto i : v)
        {
            for(auto j : i)
            {
                cout << j;
            }

            cout << endl;
        }
    }

    return 0;
}

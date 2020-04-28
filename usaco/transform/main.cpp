/*
ID: oanna.p1
TASK: transform
LANG: C++
*/

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

void rotate90(u64 len, vector<vector<int>>& v, vector<vector<int>>& res)
{
    for(u64 i = 0; i < len; i++)
    {
        for(u64 j = 0; j < len; j++)
        {
            res[i][j] = v[len - j - 1][i];
            //res[len - i - 1][j] = v[j][i];
        }
    }
}

void rotate180(u64 len, vector<vector<int>>& v, vector<vector<int>>& res){
    for(u64 i = 0; i < len; i++)
    {
        for(u64 j = 0; j < len / 2; j++)
        {
            res[i][j] = v[j][i];
            res[j][i] = v[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    u64 n = 3;
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> res = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    rotate180(n, v, res);
    for(auto i : res)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}

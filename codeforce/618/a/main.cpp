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

int main()
{
    ios::sync_with_stdio(false);

    i64 t;
    cin >> t;

    for(int c = 0; c < t; c++)
    {
        i64 len;
        cin >> len;

        i64 sum = 0;
        i64 res = 0;

        for(int i = 0; i < len; i++)
        {
            int x;
            cin >> x;

            sum += x;
            if(x == 0)
            {
                res += 1;
            }
        }

        sum += res;
        if(sum == 0)
        {
            sum += 1;
            res += 1;
        }

        cout << res << endl;
    }
    return 0;
}

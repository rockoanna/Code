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

    i64 n;
    cin >> n;

    for(int x = 0; x < n; x++)
    {
        i64 b;
        cin >> b;

        i64 res = 0;
//        while(b != 0)
//        {
//            if(b - 10 < 0)
//            {
//                res += b;
//                break;
//            }
//            else
//            {
//                res += 10;
//                b -= 10;
//                b += 1;
//            }
//        }

        while(b > 9)
        {
            i64 y = b / 10;
            res += y * 10;
            b = b % 10;
            b += y;
        }

        res += b;

        cout << res << endl;
    }

    return 0;
}

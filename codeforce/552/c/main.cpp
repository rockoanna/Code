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

    u64 a;
    cin >> a;

    u64 b;
    cin >> b;

    u64 c;
    cin >> c;

    u64 w = min(a / 3, min(b / 2, c / 2));

    u64 fave = 0;
    for(u64 i = 0; i < 7; i++)
    {
        u64 crt = i;

        u64 al = a - w * 3;
        u64 bl = b - w * 2;
        u64 cl = c - w * 2;

        u64 days = 0;

        while(true)
        {
            if(crt == 0 || crt == 3 || crt == 6)
            {
                if(al == 0)
                {
                    break;
                }
                else
                {
                    al -= 1;
                }
            }
            else if(crt == 1 || crt == 5)
            {
                if(bl == 0)
                {
                    break;
                }
                else
                {
                    bl -= 1;
                }
            }
            else
            {
                if(cl == 0)
                {
                    break;
                }
                else
                {
                    cl -= 1 ;
                }
            }

            days += 1;
            crt += 1;
            crt = crt % 7;
        }

        fave = max(fave, days);
    }

    cout << (w * 7 + fave);

    return 0;
}

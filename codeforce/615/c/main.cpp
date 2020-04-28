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

    u64 t;
    cin >> t;

    for(u64 tt = 0; tt < t; tt++)
    {
        u64 n;
        cin >> n;

        bool okay = false;
        for(u64 i = 2; i * i * i <= n; i++)
        {
            if(n % i == 0)
            {
                for(u64 j = 2; j * j <= i; j++)
                {
                    if(i % j == 0 && j != n / i && j != i / j && n / i != i / j)
                    {
                        cout << "YES" << endl;
                        cout << n / i << " "<< j << " "<< i / j << endl;
                        okay = true;
                        break;
                    }
                }

                if(okay)
                {
                    break;
                }
                else
                {
                    u64 x = n / i;
                    for(u64 j = 2; j * j < x; j++)
                    {
                        if(x % j == 0 && j != i && j != x / j && i != x / j)
                        {
                            cout << "YES" << endl;
                            cout << i << " "<< j << " "<< x / j << endl;
                            okay = true;
                            break;
                        }
                    }

                    if(okay)
                    {
                        break;
                    }
                }
            }
        }

        if(!okay){
            cout << "NO" << endl;
        }
    }


    return 0;
}

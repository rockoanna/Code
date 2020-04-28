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

inline bool enough(u64 n, u64 p)
{
    if(n % 2 == 0)
    {
        if(p < n / 2 * (n + 1))
        {
            return false;
        }
    }
    else
    {
        if(p < n * ((n * 1) / 2))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    u64 p;
    cin >> p;


    u64 days;
    cin >> days;

    if(p < days)
    {
        cout << "NO";
    }
    else
    {
        bool ok = enough(days, p);

        if(!ok)
        {
            cout << "NO";
        }
        else
        {
            if(days == 1)
            {
                cout << "YES" << endl;
                cout << p;
                return 0;
            }

            vector<u64> v(days);
            v[0] = 1;
            p -= 1;

            for(u64 i = 1; i < days; i++)
            {
                v[i] = v[i - 1] + 1;
                p -= 1;
            }

            if(p != 0)
            {
                if(v[days - 1] + p <= 2 * v[days - 2])
                {
                    v[days - 1] += p;

                    cout << "YES" << endl;
                    for(auto x : v)
                    {
                        cout << x << " ";
                    }
                }
                else
                {
                    v[days - 1] += 2 * v[days - 2] - v[days - 1];
                    p -= 2 * v[days - 2] - v[days - 1];

                    for(u64 i = days - 2; i > 0 && p > 0; i--)
                    {
                        if(v[i] + p <= 2 * v[i - 1])
                        {
                            v[i] += p;
                            p = 0;
                            break;
                        }
                        else
                        {
                            v[i] += 2 * v[i - 1] - v[i];
                            p -= 2 * v[i - 1] - v[i];
                        }
                    }

                    if(p > 0)
                    {
                        if(v[0] + p < v[1])
                        {
                            v[0] += p;
                            p = 0;
                        }
                        else
                        {
                            cout << "NO";
                            return 0;
                        }
                    }

                    cout << "YES";
                    for(auto x : v)
                    {
                        cout << x << " ";
                    }
                }
            }
        }
    }

    return 0;
}

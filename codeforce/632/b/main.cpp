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

inline string solve(const vector<i64>& a, const vector<i64>& b, i64 n)
{
    bool got1 = false;
    bool got2 = false;

    for(i64 i = 0; i < n; i++)
    {
        switch (a[i])
        {
        case -1:
        {
            if(got2 == false)
            {
                if(got1)
                {
                    if(a[i] <= b[i])
                    {
                        return "YES";
                    }
                    else
                    {
                        return "NO";
                    }
                }
                else
                {
                    if(a[i] != b[i])
                    {
                        return "NO";
                    }
                    else
                    {
                        got2 = true;
                        break;
                    }
                }
            }
            else
            {
                if(!got1)
                {
                    if(a[i] < b[i])
                    {
                        return "NO";
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    return "YES";
                }
            }
        }
        case 0:
        {
            if(a[i] == b[i])
            {
                break;
            }

            if(a[i] > b[i])
            {
                if(got2)
                {
                    break;
                }
                else
                {
                    return "NO";
                }
            }

            if(a[i] < b[i])
            {
                if(got1)
                {
                    break;
                }
                else
                {
                    return "NO";
                }
            }
        }
        case 1:
        {
            if(got1 == false)
            {
                if(got2)
                {
                    if(a[i] >= b[i])
                    {
                        return "YES";
                    }
                    else
                    {
                        return "NO";
                    }
                }
                else
                {
                    if(a[i] != b[i])
                    {
                        return "NO";
                    }
                    else
                    {
                        got1 = true;
                        break;
                    }
                }
            }
            else
            {
                if(!got2)
                {
                    if(a[i] > b[i])
                    {
                        return "NO";
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    return "YES";
                }
            }
        }
        }
    }

    return "YES";
}

int main()
{
    ios::sync_with_stdio(false);

    i64 t;
    cin >> t;

    for(i64 tt = 0; tt < t; tt++)
    {
        i64 n;
        cin >> n;

        i64 same = 0;

        vector<i64> a(n);
        vector<i64> b(n);

        for(i64 i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for(i64 i = 0; i < n; i++)
        {
            cin >> b[i];

            if(b[i] == a[i])
            {
                same += 1;
            }
        }

        if(a[0] != b[0])
        {
            cout << "NO" << endl;
            continue;
        }

        if(same == n)
        {
            cout << "YES" << endl;
            continue;
        }

        cout << solve(a, b, n) << endl;
    }

    return 0;
}

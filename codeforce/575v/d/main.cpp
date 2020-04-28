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

inline int nr(char c)
{
    switch(c)
    {
    case 'R':
        return -1;

    case 'G':
        return 0;

    default:
        return 1;
    }
}

inline int next(int x)
{
    switch(x)
    {
    case -1:
        return 0;

    case 0:
        return 1;

    default:
        return -1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    next(24);
    u64 t;
    cin >> t;

    for(u64 tt = 0; tt < t; tt++)
    {
        u64 len;
        cin >> len;

        u64 st;
        cin >> st;

        string ss;
        cin >> ss;

        vi in;
        in.reserve(len);
        for(auto ch : ss)
        {
            in.push_back(nr(ch));
        }

        vi v(len);
        vl count_(len);

        i64 mi = len;
        i64 crt;
        for(int k = -1; k < 2 && mi > 0; k++)
        {
            crt = k;
            u64 crt_c = 0;

            for(u64 i = 0; i < len; i++)
            {
                if(in[i] != crt)
                {
                    crt_c += 1;
                }

                crt = next(crt);
                count_[i] = crt_c;

                if(i >= st - 1)
                {
                    if(i != st - 1)
                    {
                        mi = min(count_[i] - count_[i - st], mi);
                    }
                    else
                    {
                        mi = min(count_[i], mi);
                    }

                    if(mi == 0)
                    {
                        break;
                    }
                }
            }
        }

        cout << mi << endl;
    }

    return 0;
}

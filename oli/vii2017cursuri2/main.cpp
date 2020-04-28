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

int class_nr(vector<tuple<int, int>>& v, int k)
{
    int len = v.size();
    vector<bool> rem(len, true);

    int res = 1;
    int prev = get<1>(v[0]);
    rem[0] = false;

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(rem[i] && get<0>(v[j]) >= prev)
            {
                res += 1;
                prev = get<1>(v[j]);
                rem[j] = false;
            }
        }
    }

    return res;
}

inline int max_time(vector<tuple<int, int>>& v, int k)
{
    int mi = -1;
    int len = v.size();

    for(int i = 0; i < k; i++)
    {
        int prev = 0;

        for(int j = i; j < len; j+=k)
        {
            int x = get<0>(v[j]);

            if(j != i)
            {
                if(mi == -1)
                {
                    mi = x - prev;
                }
                else
                {
                    mi = min(mi, x - prev);
                }
            }
            prev = x;
        }
    }
    return mi;
}

int main()
{
    ios::sync_with_stdio(false);

    int c;
    cin >> c;

    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<tuple<int, int>> v(n);

    if(c == 1)
    {
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            int y;
            cin >> y;

            v[i] = {y, x};
        }

        sort(v.begin(), v.end());
        cout << class_nr(v, k);
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            int y;
            cin >> y;

            v[i] = {x, y};
        }

        sort(v.begin(), v.end());
        cout << max_time(v, k);
    }

    return 0;
}

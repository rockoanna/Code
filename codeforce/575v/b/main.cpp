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

    u64 t;
    cin >> t;

    for(u64 tt = 0; tt < t; tt++)
    {
        u64 len;
        cin >> len;

        i64 s;
        cin >> s;

        u64 o = 0;

        vl v(len);

        vl ans;
        ans.reserve(s);

        for(u64 i = 0; i < len; i++)
        {
            cin >> v[i];
            if(v[i] % 2 == 1)
            {
                o += 1;
            }
        }

        if(o < s)
        {
            cout << "NO";
            if(tt + 1 != t)
            {
                cout << endl;
            }
            continue;
        }

        i64 tmp = s;
        for(u64 i = 0; i < len && tmp != 1; i++)
        {
            if(tmp == 1)
            {
                continue;
            }

            if(v[i] % 2 == 1)
            {
                ans.push_back(i + 1);
                tmp -= 1;
            }
        }

        ans.push_back(len);

        u64 m;
        if(s - 2 < 0)
        {
            m = 0;
        }
        else
        {
            m = ans[s - 2];
        }

        u64 sum = 0;
        for(u64 i = m; i < len; i++)
        {
            sum += v[i];
        }

        if(sum % 2 == 0)
        {
            cout << "NO";
            if(tt + 1 != t)
            {
                cout << endl;
            }
            continue;
        }

        cout << "YES" << endl;
        for(auto x : ans)
        {
            cout << x << " ";
        }

        if(tt + 1 != t)
        {
            cout << endl;
        }
    }

    return 0;
}

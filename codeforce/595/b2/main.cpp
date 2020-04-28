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

    int t;
    cin >> t;

    for(int tt = 0; tt < t; tt++)
    {
        u64 n;
        cin >> n;

        vl perm(n + 1);

        vl res(n + 1, 0);
        vector<bool> e(n + 1, false);

        for(u64 i = 1; i <= n; i++)
        {
            cin >> perm[i];
        }

        u64 solved = 0;
        vi cycle;
        cycle.reserve(n);

        for(u64 i = 1; i < n + 1 && solved < n; i++)
        {
            if(e[i])
            {
                continue;
            }

            cycle.clear();

            int start = i;

            cycle.push_back(start);

            int next = perm[start];

            while(next != start)
            {
                cycle.push_back(next);
                next = perm[next];
            }

            auto len = cycle.size();
            for(auto c : cycle)
            {
                res[c] = len;
                e[c] = true;
            }

            solved += len;
        }

        for(u64 i = 1; i <= n; i++)
        {
            cout << res[i] << " ";
        }

        cout << endl;
    }

    return 0;
}

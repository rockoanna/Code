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

    int n;
    cin >> n;

    for(int t = 0; t < n; t++)
    {
        int p;
        cin >> p;

        int k;
        cin >> k;

        vi v(p);

        for(int i = 0; i < p; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        if(v[0] + k < v[p - 1] - k)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << v[0] + k << endl;
        }
    }

    return 0;
}

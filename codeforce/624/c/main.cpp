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
    u64 t;
    cin >> t;

    for(u64 tt; tt < t; tt++)
    {
        map<char, u64> m;

        for(char c = 'a'; c <= 'z'; c++)
        {
            m.insert({c, 0});
        }

        u64 len;
        cin >> len;

        u64 tries;
        cin >> tries;

        string s;
        cin >> s;

        for(u64 i = 0; i < len; i++)
        {
            m[s[i]] += 1;
        }

        vector<u64> v(tries);

        for(u64 i = 0; i < tries; i++)
        {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        for(u64 i = 0; i < len; i++)
        {
            auto it = lower_bound(v.begin(), v.end(), i + 1);
            m[s[i]] += distance(it, v.end());
        }

        for(char c = 'a'; c < 'z'; c++)
        {
            cout << m[c] <<" ";
        }

        cout << m['z'];

        if(tt + 1 != t)
        {
            cout << endl;
        }
    }
    return 0;
}

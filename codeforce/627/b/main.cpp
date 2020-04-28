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

bool is_palindrome(vi& v)
{
    i64 len = v.size();

    map<i64, i64> m;
    for(int i = 0; i < len; i++)
    {
        if(i == 0)
        {
            m[v[i]] += 1;
        }
        else
        {
            if(v[i - 1] == v[i])
            {
                if(i > 1 && v[i - 2] == v[i])
                {
                    return true;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                m[v[i]] += 1;
                if(m[v[i]] >= 2)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int x = 0; x < n; x++)
    {
        i64 len;
        cin >> len;

        vi v(len);
        for(int i = 0; i < len; i++)
        {
            cin >> v[i];
        }

        if(is_palindrome(v))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

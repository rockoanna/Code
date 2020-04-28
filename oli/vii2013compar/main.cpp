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

    string s;
    cin >> s;

    int n = s.size() + 1;
    cout << n << endl;

    vi res;
    vector<bool> v(n + 1, true);
    int p = 0;
    int len = s.size();

    for(int k = 0; k < len + 1; k++)
    {
        if(k == 0)
        {
            if(s[k] == '>')
            {
                res.push_back(n);
                v[n] = false;
                p = n;
            }
            else
            {
                res.push_back(1);
                v[1] = false;
                p = 1;
            }
            continue;
        }

        if(s[k - 1] == '<')
        {
            for(int i = p + 1; i < n + 1; i++)
            {
                if(v[i])
                {
                    v[i] = false;
                    res.push_back(i);
                    p = i;
                    break;
                }
            }
        }
        else
        {
            if(s[k] == '<')
            {
                for(int i = 1; i < p; i++)
                {
                    if(v[i])
                    {
                        res.push_back(i);
                        p = i;
                        v[i] = false;
                        break;
                    }
                }
                continue;
            }
            for(int i = p - 1; i > 0; i--)
            {
                if(v[i])
                {
                    res.push_back(i);
                    p = i;
                    v[i] = false;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}

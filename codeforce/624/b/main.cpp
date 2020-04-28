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

bool sortable(vi v, vi pos)
{
    int len = v.size();
    for(int i = 0; i < len - 1; i++)
    {
        if(v[i] > v[i + 1])
        {
            auto found = binary_search(pos.begin(), pos.end(), i + 1);

            if(found)
            {
                int tmp = v[i + 1];
                v[i + 1] = v[i];
                v[i] = tmp;

                if(i > 0)
                {
                    i -= 2;
                }

                continue;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int n;
    cin >> n;

    for(int t = 0; t < n; t++)
    {
        int len;
        cin >> len;

        int p;
        cin >> p;

        vi v(len);
        vi pos(p);

        for(int i = 0; i < len; i++)
        {
            cin >> v[i];
        }

        for(int i = 0; i < p; i++)
        {
            cin >> pos[i];
        }

        sort(pos.begin(), pos.end());

        bool okay = sortable(v, pos);
        if(okay)
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

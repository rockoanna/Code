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

i64 cost(i64 m, i64 me, i64 o)
{
    if(m <= me)
    {
        return 0;
    }

    i64 x = m % (o + me);
    if(x == 0)
    {
        x = o + me;
    }

    auto cost = x / me;

    if(x % me == 0){
        cost -= 1;
    }

    return cost;
}

int main()
{
    ios::sync_with_stdio(false);

    i64 m_n;
    cin >> m_n;

    i64 me;
    cin >> me;

    i64 o;
    cin >> o;

    i64 k;
    cin >> k;

    vi v(m_n);

    for(int x = 0; x < m_n; x++)
    {
        i64 m;
        cin >> m;

        v[x] = cost(m, me, o);
    }

    sort(v.begin(), v.end());
    i64 res = 0;
    for(int i = 0; i < m_n; i++)
    {
        if(k - v[i] >= 0)
        {
            res += 1;
            k -= v[i];
        }
        else
        {
            break;
        }
    }

    cout << res << endl;

    return 0;
}

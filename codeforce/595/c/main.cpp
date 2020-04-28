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

void good_nr(vector<u64>& v)
{
    u64 p = 1;
    for(u64 i = 1; i < 11; i++)
    {
        v.push_back(p);
        u64 len = v.size();

        for(u64 j = 0; j < len - 1; j++)
        {
            v.push_back(p + v[j]);
        }

        p *= 3;
    }
}

int main()
{
    ios::sync_with_stdio(false);

    vector<u64> v;
    v.reserve(2046);
    good_nr(v);


    int t;
    cin >> t;

    for(int tt = 0; tt < t; tt++)
    {
        u64 n;
        cin >> n;

        if(binary_search(v.begin(), v.end(), n))
        {
            cout << n << endl;
        }
        else
        {
            auto x = upper_bound(v.begin(), v.end(), n);
            cout << (*x) << endl;
        }
    }

    return 0;
}

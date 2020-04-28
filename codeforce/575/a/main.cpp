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

    for(int i = 0; i < n; i++)
    {
        vl v(3);
        cin >> v[0];
        cin >> v[1];
        cin >> v[2];

        u64 a = 0;
        u64 b = 0;

        sort(v.begin(), v.end());
        if(v[1] != v[2])
        {
            b = v[1];
            a = v[0];
            u64 x = b - a;
            if(v[2] <= x)
            {
                a += v[2];
                cout << a << endl;
            }
            else
            {
                a += x;
                v[2] -= x;
                a += v[2] / 2;
            }
        }
        else
        {
            a = v[1];
            b = v[2];
            a += v[0] / 2;
        }
        cout << a << endl;


    }

    return 0;
}

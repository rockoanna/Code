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
        vl v(3);
        cin >> v[0];
        cin >> v[1];
        cin >> v[2];

        sort(v.begin(), v.end());

        u64 a = v[0];
        u64 b = v[1];

        if(v[2] - (b - a) >= 0){
            v[2] -= (b - a);
            a = b;
        }else{
            a += v[2];
        }

        if(a < b)
        {
            cout << a;
            cout << endl;
            continue;
        }

        if(v[2] != 0)
        {
            cout << a + v[2] / 2;
            cout << endl;
            continue;
        }

        if(a == b)
        {
            cout << a;
            cout << endl;
            continue;
        }

    }

    return 0;
}

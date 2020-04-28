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

u64 mx = 100000;

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int tt = 0; tt < t; tt++)
    {
        u64 n;
        cin >> n;

        u64 k;
        cin >> k;

        string s = "";
        s.append(n, 'a');

        u64 t_root = ceil((sqrt(8 * k + 1) - 1) / 2);

        u64 x = t_root;
        u64 y = k - x * (x - 1) / 2 - 1;

        cout << "y : "  << y << endl;
        cout << "x : " << x << endl;
        s[n - x - 1] = 'b';
        s[n - y - 1] = 'b';


        cout << s << endl;
    }

    return 0;
}


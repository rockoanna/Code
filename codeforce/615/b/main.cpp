#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
#include <cmath>

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

    for(int x = 0; x < n; x++)
    {
        int p;
        cin >> p;

        vector<tuple<int, int>> v(p);
        vi vy(p);

        for(int i = 0; i < p; i++)
        {
            int x;
            int y;
            cin >> x;
            cin >> y;

            vy[i] = y;

            tuple<int, int> t = {x, y};
            v[i] = t;
        }

        int crtx = 0;
        int crty = 0;

        sort(v.begin(), v.end());
        sort(vy.begin(), vy.end());

        int count_ = 0;
        int r = 0;
        int u = 0;
        string res = "";
        for(int i = 0; i < n; i++)
        {
            if(get<1>(v) > vy){}
            if(get<0>(v) > crtx)
            {
                crtx = get<0>(v);
                int z = crtx;
                res.push_back();
            }
        }
    }

    return 0;
}

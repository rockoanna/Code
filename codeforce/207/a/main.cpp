#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
#include <set>
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
    int m;
    cin >> n;
    cin >> m;

    vi res(n + 1);
    set<int> alive;

    for(int i = 1; i < n + 1; i++)
    {
        alive.insert(i);
    }

    for(int i = 0; i < m; i ++)
    {
        int l;
        cin >> l;
        int r;
        cin >> r;
        int w;
        cin >> w;

        auto x = alive.lower_bound(l);
//        auto y = alive.upper_bound(r);
//
//        for(auto it = x; it != y;){
//            if(*it != w){
//                res[*it] = w;
//                it = alive.erase(it);
//            }else{
//                it++;
//            }
//        }

        for(auto it = x; it != alive.end() && *it <= r;)
        {
            if(*it != w)
            {
                res[*it] = w;
                it = alive.erase(it);
            }
            else
            {
                it++;
            }
        }
    }

    for(int i = 1; i < n + 1; i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;
    return 0;
}

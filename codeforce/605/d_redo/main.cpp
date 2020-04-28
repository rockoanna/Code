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
    int n;
    cin >> n;

    vi v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vi beg;
    vi en;

    for(int i = 0; i < n; i++)
    {
        if(v[i] < v[i - 1] && i + 1 != n)
        {
            en.push_back(v[i - 1]);
            beg.push_back(v[i]);
            continue;
        }

        if(i + 1 == n && v[i] < v[i - 1])
        {
            en.push_back(v[i - 1]);
            beg.push_back(v[i]);
            continue;
        }
    }


    return 0;
}

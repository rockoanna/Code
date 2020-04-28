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
    i64 len;
    cin >> len;

    int c;
    cin >> c;

    string s;
    cin >> s;

    vc v(c);
    for(i64 i = 0; i < c; i++)
    {
        cin >> v[i];
    }

    i64 count_ = 0;
    i64 nr = 0;
    bool okay = false;

    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < v.size(); j++)
        {
            if(v[j] == s[i])
            {
                okay = true;
                break;
            }
        }

        if(okay)
        {
            nr = nr + 1;
            count_ += nr;
        }
        else
        {
            nr = 0;
        }

        okay = false;
    }

    cout << count_ << endl;

    return 0;
}


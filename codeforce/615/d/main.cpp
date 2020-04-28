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

    vi v;
    bool okay = false;
    for(int i = 2; i < 100; i++)
        {
            for(int j = 2; j <= i / 2; j++)
            {
                if(i % j == 0)
                {
                    okay = true;
                    break;
                }
            }

            if(!okay)
            {
                v.push_back(i);
                cout << i << endl;
            }
        }

    return 0;
}

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

    for(int x = 0; x < n; x++)
    {
        int len;
        cin >> len;

        string s;
        cin >> s;

        string r = st(len, 'x');
        int count_ = 0;

        while(s != r)
        {
            bool happen = false;
            string k = s;
            for(int i = 0; i < len; i++)
            {
                if(s[i] == 'A')
                {
                    if(i + 1 != len && s[i + 1] == 'P')
                    {
                        k[i + 1] = 'A';
                        happen = true;
                    }
                    else
                    {
                        k[i] = 'x';
                    }
                }
            }
            s = k;

            if(!happen){
                break;
            }

            count_ += 1;
        }

        cout << count_ << endl;

    }

    return 0;
}

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

    for(int x = 0; x < n; x++)
    {
        int y;
        cin >> y;

        string s;
        cin >> s;

        char prev = '';
        int a = -1;
        int b = -1;

        for(int i = 0; i < s; i++)
        {
            if(s[i] == 'L')
            {
                if(prev == 'R')
                {
                    a = i - 1;
                    b = i;
                    break;
                }
            }

            if(s[i] == 'R')
            {
                if(prev == 'L')
                {
                    a = i - 1;
                    b = i;
                    break;
                }
            }

            if(s[i] == 'U')
            {
                if(prev == 'D')
                {
                    a = i - 1;
                    b = i;
                    break;
                }
            }

            if(s[i] == 'D')
            {
                if(prev == 'U')
                {
                    a = i - 1;
                    b = i;
                    break;
                }
            }
        }


    }

}

return 0;
}

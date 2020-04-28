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

    i32 n;
    cin >> n;

    for(int x = 0; x < n; x++)
    {
        int p;
        cin >> p;

        string s1;
        string s2;
        cin >> s1;
        cin >> s2;

        int l = 0;
        int c = 0;
        bool h = true;
        bool okay = true;

        for(int i = 0; i < p; i++)
        {
            if(s1[i] == '1' || s1[i] == '2')
            {
                s1[i] = '1';
            }
            else
            {
                s1[i] = '2';
            }

            if(s2[i] == '1' || s2[i] == '2')
            {
                s2[i] = '1';
            }
            else
            {
                s2[i] = '2';
            }
        }


        while(okay)
        {
            if(h)
            {
                if(l == 0)
                {
                    if(s1[c] == '1')
                    {
                        c += 1;
                    }
                    else
                    {
                        l = 1;
                        h = false;
                    }
                }
                else
                {
                    if(s2[c] == '1')
                    {
                        c += 1;
                    }
                    else
                    {
                        l = 0;
                        h = false;
                    }
                }
            }
            else
            {
                if(l == 0)
                {
                    if(s1[c] == '1')
                    {
                        okay = false;
                        break;
                    }
                    else
                    {
                        h = true;
                        c += 1;
                    }
                }
                else
                {
                    if(s2[c] == '1')
                    {
                        okay = false;
                        break;
                    }
                    else
                    {
                        h = true;
                        c += 1;
                    }
                }
            }

            if(c == p){
                okay = (l == 1);
                break;
            }
        }

        if(okay)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

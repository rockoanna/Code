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

    int t;
    cin >> t;

    for(int tt = 0; tt < t; tt++)
    {
        u64 len;
        cin >> len;

        string s;
        cin >> s;

        string a = "1";
        string b = "1";

        for(u64 i = 1; i < len; i++)
        {
            if(a > b)
            {
                if(s[i] == '1')
                {
                    b.push_back('1');
                    a.push_back('0');
                    continue;
                }

                if(s[i] == '2')
                {
                    b.push_back('2');
                    a.push_back('0');
                    continue;
                }

                if(s[i] == '0')
                {
                    b.push_back('0');
                    a.push_back('0');
                    continue;
                }

            }
            else
            {
                if(b > a)
                {
                    if(s[i] == '1')
                    {
                        a.push_back('1');
                        b.push_back('0');
                        continue;
                    }

                    if(s[i] == '2')
                    {
                        b.push_back('0');
                        a.push_back('2');
                        continue;
                    }

                    if(s[i] == '0')
                    {
                        b.push_back('0');
                        a.push_back('0');
                        continue;
                    }
                }
                else
                {
                    if(s[i] == '1')
                    {
                        b.push_back('1');
                        a.push_back('0');
                        continue;
                    }

                    if(s[i] == '2')
                    {
                        b.push_back('1');
                        a.push_back('1');
                        continue;
                    }

                    if(s[i] == '0')
                    {
                        b.push_back('0');
                        a.push_back('0');
                        continue;
                    }
                }

            }
        }

        cout << a << endl;
        cout << b << endl;
    }

    return 0;
}


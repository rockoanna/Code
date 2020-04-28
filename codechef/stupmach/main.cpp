//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

#define g0 get<0>
#define g1 get<1>

typedef int64_t i64;
//typedef int32_t i32;
typedef uint64_t u64;
//typedef uint32_t u32;
//typedef string st;
//typedef stringstream ss;
//
//typedef double db;
//
//typedef vector<i64> vl;
//typedef vector<i32> vi;
//typedef vector<char> vc;
//typedef vector<db> vd;
//typedef vector<st> vs;
//
//typedef map<st,i32> st2i;
//typedef map<st,i64> st2l;
//typedef map<st,db> st2d;
//
//typedef map<i64,i64> l2l;
//typedef map<i64,i32> l2i;
//
//typedef map<i32,i32> i2i;
//typedef map<i32,i64> i2l;

//#define DEBUG
//
//#ifdef DEBUG
//#define dbg(var) {cerr << __LINE__ <<": "<< #var <<" = "<< var << std::endl;}
//#else
//#define dbg(var)
//#endif

int main()
{
    ios::sync_with_stdio(false);

    u64 t;
    cin >> t;

    for(u64 tt = 0; tt < t; tt++)
    {
        u64 n;
        cin >> n;

        u64 token = 0;
//        u64 first = 0;
//
//        u64 extra = 1000000000;
//
//
//        bool ok = true;

        vector<u64> v(n);
        vector<u64> m(n);
        for(u64 i = 0; i < n; i++)
        {
            cin >> v[i];
            if(i == 0)
            {
                m[i] = 0;
            }
            else
            {
                if(v[i] < v[m[i - 1]])
                {
                    m[i] = i;
                }
                else
                {
                    m[i] = m[i - 1];
                }
            }

//            if(i == 0)
//            {
//                first = v[i];
//                token += first;
//            }
//            else
//            {
//                if(ok)
//                {
//                    if(v[i] > first)
//                    {
//                        token += first;
//                    }
//                    else
//                    {
//                        token += v[i];
//
//                        extra = min(extra, v[i]);
//                        ok = false;
//                    }
//                }
//                else
//                {
//                    if(v[i] > extra)
//                    {
//                        token += extra;
//                    }
//                    else
//                    {
//                        extra = v[i];
//                        token += extra;
//                    }
//                }
//            }
        }



        u64 small = UINT64_MAX;
        for(i64 i = n - 1; i >= 0; i--)
        {
            if(small == m[i])
            {
                continue;
            }

            small = m[i];

            token += v[m[i]] * (i + 1);

            for(i64 j = 0; j <= i; j++)
            {
                v[j] -= v[m[i]];
            }



        }

        cout << token << endl;

//        u64 stop = n;
//
//        while(v[0] != 0)
//        {
//            for(u64 i = 0; i < n; i++)
//            {
//                if(v[i] == 0)
//                {
//                    stop = i;
//                    break;
//                }
//            }
//
//            for(u64 i = 0; i < stop; i++)
//            {
//                v[i] -= 1;
//                token += 1;
//            }
//
//            if(v[0] == 0)
//            {
//                break;
//            }
//        }

        //cout << token << endl;
    }

    return 0;
}

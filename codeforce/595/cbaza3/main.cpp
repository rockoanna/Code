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

inline deque<int> ternary(u64 n)
{
    deque<int> t;

    while(n != 0)
    {
        t.push_front(n % 3);
        n /= 3;
    }

    return t;
}

void remove_2(deque<int>& d)
{
//    cout << "in: ";
//    for(auto e : d)
//    {
//        cout << e;
//    }
//
//    cout << endl;

    int c = 0;
    for(i64 i = d.size() - 1; i >= 0; i--)
    {
        if(d[i] == 2)
        {
            d[i] = 0;
            c = 1;
        }
        else
        {
            if(c != 0)
            {
                d[i] += 1;
                c = 0;

                if(d[i] == 2)
                {
                    c = 1;
                    d[i] = 0;
                }
                else
                {
                    for(i64 j = i + 1; j < d.size(); j++)
                    {
                        d[j] = 0;
                    }
                }
            }
        }
    }

    if(c == 1)
    {
        d.push_front(1);
        for(i64 i = 1; i < d.size(); i++)
        {
            d[i] = 0;
        }
    }

//    cout << "out: ";
//    for(auto e : d)
//    {
//        cout << e;
//    }
//
//    cout << endl;
}

u64 base_10(deque<int>& d)
{
    u64 res = 0;
    u64 len = d.size();

    u64 pow = 1;
    for(i64 i = len - 1; i >= 0; i--)
    {
        if(d[i] == 1)
        {
            res += pow;
        }
        //else{
//            if(d[i] == 2){
//                res += pow * 2;
//            }
//        }

        pow *= 3;
    }

    return res;
}

inline u64 solve(u64 n)
{
    deque<int> b = ternary(n);
    remove_2(b);
    u64 x = base_10(b);
    return x;
}

int main()
{
    ios::sync_with_stdio(false);

//    u64 x;
//    cin >> x;
//
//    auto v = ternary(x);
//
//    cout << x << " = " << base_10(v);
//
//    cout << endl;
//
//    for(auto e : v){
//        cout << e;
//    }

    u64 t;
    cin >> t;

    for(u64 tt = 0; tt < t; tt++)
    {
        u64 n;
        cin >> n;

        cout << solve(n) << endl;
    }

    return 0;
}

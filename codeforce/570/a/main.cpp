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

i64 digits_sum(i64 x)
{
    int res = 0;
    while(x != 0)
    {
        res += x % 10;
        x /= 10;
    }

    return res;
}

int main()
{
    i64 n;
    cin >> n;

    i64 x = digits_sum(n);
    if(x % 4 == 0)
    {
        cout << n << endl;
    }
    else
    {
        for(int i = 0; i < 100; i++){
            n += 1;
            x = digits_sum(n);
            if(x % 4 == 0){
                cout << n << endl;
                break;
            }
        }
    }

    return 0;
}

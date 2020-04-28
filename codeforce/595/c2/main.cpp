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

void pow3(vector<u64>& v)
{
    u64 p = 1;
    for(u64 i = 0; i < 39; i++)
    {
        v.push_back(p);
        p *= 3;
    }
}

u64 val_for_index(u64 idx, vector<u64>& pow)
{
    bitset<64> bits{idx};

    u64 res = 0;
    for(int i = 0; i < 40; i++)
    {
        if(bits[i] == 1)
        {
            res += pow[i];
        }
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);

    vector<u64> pow;
    pow.reserve(39);
    pow3(pow);


    int t;
    cin >> t;

    for(int tt = 0; tt < t; tt++)
    {
        u64 n;
        cin >> n;

        u64 low = 1;
        u64 high = (low << 39) - 1;

        bool found = false;
        while(low <= high)
        {
            u64 mid = low / 2 + high / 2;
            if(low % 2 == 1 && high % 2 == 1)
            {
                mid += 1;
            }

            auto val = val_for_index(mid, pow);

            if(n < val)
            {
                high = mid - 1;
                continue;
            }

            if(n > val)
            {
                low = mid + 1;
                continue;
            }

            if(n == val)
            {
                found = true;
                break;
            }
        }

        if(found)
        {
            cout << n << endl;
        }
        else
        {
            cout << val_for_index(low, pow) << endl;
        }
    }

    return 0;
}

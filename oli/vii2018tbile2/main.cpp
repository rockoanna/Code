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

tuple<vector<u64>, vector<u64>> put(u64 n)
{
    vector<u64> red;
    vector<u64> white;

    white.push_back(1);
    white.push_back(3);

    red.push_back(2);
    red.push_back(4);

    for(u64 i = 1; i <= n; i++)
    {
        u64 x = red[i] + white[i];

        if(x <= n)
        {
            white.push_back(x);

            u64 y = white[i] + 1;

            if(y == 4)
            {
                y += 1;
            }

            while(y < x)
            {
                red.push_back(y);
                y += 1;
            }
        }
        else
        {
            for(u64 j = white[i] + 1; j <= n; j++)
            {
                red.push_back(j);
            }

            break;
        }
    }

    return {white, red};
}

inline u64 c1(u64 n)
{
    auto red = get<1>(put(n));
    return red.size();
}

u64 c2(u64 n, u64 v, u64 m)
{
    // vector<u64> red;
    //  vector<u64> white;
    u64 wh = 3;
    vector<u64> pw = {1, 3};

    pw.reserve(n);
    // red.reserve(n);
    // white.reserve(n);

    // white.push_back(1);
    // white.push_back(3);

    // red.push_back(2);
    // red.push_back(4);

    u64 rd = 3;
    v -= 1;
    u64 res = 0;

    u64 cr = 0;
    u64 cw = 0;

    if(v == 0)
    {
        res += 2;
        res += 1;
    }

    if(v == 1)
    {
        res += 3;
        res += 4;
    }

    cr += 2;
    cw += 2;

    for(u64 i = 1; i <= n; i++)
    {
        if(binary_search(pw.begin(), pw.end(), ++rd))
        {
            rd++;
        }
        u64 x = rd + wh;
        // cout << wh << endl;
        if(x <= n)
        {
            // white.push_back(x);

//            cw += 1;
//            if(cw >= m)
//            {
//                cw = 0;
//            }

            if(cw == v)
            {
                res += x;
            }

            cw += 1;
            if(cw >= m)
            {
                cw = 0;
            }

            u64 y = wh + 1;
            wh = x;
            pw.push_back(x);

            if(y == 4)
            {
                y += 1;
            }

            //u64 offset = (v - cr % m) % v;

            u64 offset;
            if(cr % m ==v){
                offset = 0;
            }else if(cr % m < v){
                offset = v - cr % m;
            }else{
                offset = m - cr % m + v;
            }
            y += offset;

            while(y < x)
            {
                // red.push_back(y);

                res += y;
                y += m;
//                if(cr == v)
//                {
//                    res += y;
//                }
//
//                cr += 1;
//                if(cr >= m)
//                {
//                    cr = 0;
//                }
//
//
//                y += 1;
            }
            cr = x % m;
        }
        else
        {
            u64 offset;
            if(cr % m ==v){
                offset = 0;
            }else if(cr % m < v){
                offset = v - cr % m;
            }else{
                offset = m - cr % m + v;
            }
            for(u64 j = wh + 1 + offset; j <= n; j+=m)
            {
                // red.push_back(j);
//                cr += 1;
//                if(cr >= m)
//                {
//                    cr = 0;
//                }

                res += j;
//                if(cr == v)
//                {
//                    res += j;
//                }
//
//                cr += 1;
//                if(cr >= m)
//                {
//                    cr = 0;
//                }

            }

            break;
        }
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);

    ifstream cin {"tbile.in"};
    ofstream cout {"tbile.out"};

    int c;
    cin >> c;

    u64 n;
    cin >> n;

    u64 m;
    cin >> m;

    if(c == 1)
    {
        u64 x = c1(n);

        if(x % m == 0)
        {
            cout << x / m << " " << x;
        }
        else
        {
            cout << x / m + 1 << " " << x;
        }
    }
    else
    {
        u64 v;
        cin >> v;

        cout << c2(n, v, m);
    }

    return 0;
}

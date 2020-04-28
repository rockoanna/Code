#include <bits/stdc++.h>

using namespace std;

typedef int64_t i64;

inline i64 div(i64 n)
{
    i64 res = 0;

    for(int i = 1; i * i <= n; i++)
    {
        if(i * i == n)
        {
            res += 1;
            continue;
        }

        if(n % i == 0)
        {
            res += 2;
        }
    }

    return res - 1;
}

inline i64 solve1(vector<i64>& v, i64 len)
{
    return div(len);
}

inline vector<i64> div2(i64 n)
{
    vector<i64> v;
    v.reserve(n);

    for(int i = 1; i * i <= n; i++)
    {
        if(i * i == n)
        {
            v.push_back(i);
            continue;
        }

        if(n % i == 0)
        {
            v.push_back(i);
            if(i != 1)
            {
                v.push_back(n / i);
            }
        }
    }

    return v;
}



tuple<i64, i64> solve2(vector<i64>& v, i64 len)
{
    i64 f = -1;
    i64 c = 0;
    i64 e = 0;

    auto d = div2(len);

    i64 lend = d.size();

    for(int i = 0; i < lend; i++)
    {
        for(int j = 0; j < len; j+=d[i])
        {
            auto st = v.begin();
            advance(st, j);

            auto ed = v.begin();
            advance(ed, j + d[i]);

            auto x = max_element(st, ed);

            st = v.begin();
            advance(st, j);

            ed = v.begin();
            advance(ed, j + d[i]);

            auto y = min_element(st, ed);

            if(f == -1)
            {
                f = x - y;
                c = len / d[i];
            }
            else
            {
                f = min(f, x - y);
                if(f == x - y){
                    c = len / d[i];
                }
            }
        }
    }

    i64 mx = -1;
    i64 x = len / c;
    for(int i = 0; i < len; i+=x)
    {
        i64 sum = 0;

        for(int j = i; j < i + x; j++)
        {
            sum += v[j];
        }

        if(i == 0)
        {
            mx = sum;
            e = i + 1;
        }
        else
        {
            mx = max(mx, sum);

            if(mx == sum)
            {
                e = i + 1;
            }
        }
    }

    return {c, e};
}

int main()
{
    ifstream cin {"wind.in"};
    ofstream cout {"wind.out"};

    int c;
    cin >> c;

    i64 n;
    cin >> n;

    vector<i64> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if(c == 1)
    {
        cout << solve1(v, n);
    }
    else
    {
        auto t = solve2(v, n);
        cout << get<0>(t) << " " << get<1>(t);
    }

    return 0;
}

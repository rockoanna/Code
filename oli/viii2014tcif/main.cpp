#include <bits/stdc++.h>

#define g0 get<0>
#define g1 get<1>

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

#define DEBUG

#ifdef DEBUG
#define dbg(var) {cerr << __LINE__ <<": "<< #var <<" = "<< var << std::endl;}
#else
#define dbg(var)
#endif

string nr(u64 a, u64 b, u64 c, u64 c1, u64 c2, u64 c3, string& s)
{
    vector<tuple<u64, u64>> v = {{c1, a}, {c2, b}, {c3, c}};
    sort(v.begin(), v.end());

    string res;
    res.reserve(a + b + c);

    if(a + b + c > s.size())
    {
        if(get<0>(v[0]) == 0)
        {
            res.append(1, g0(v[1]) + '0');
            res.append(g1(v[0]), g0(v[0]) + '0');
            if(g1(v[1]) - 1 > 0)
            {
                res.append(g1(v[1]) - 1, g0(v[1]) + '0');
            }
            res.append(g1(v[2]), g0(v[2]) + '0');
        }
        else
        {
            res.append(g1(v[0]), g0(v[0]) + '0');
            res.append(g1(v[1]), g0(v[1]) + '0');
            res.append(g1(v[2]), g0(v[2]) + '0');
        }
        return res;
    }

    map<u64, u64> f = {{c1, a}, {c2, b}, {c3, c}};

    u64 len = s.size();

    for(u64 i = 0; i < len; i++)
    {
        u64 crt = s.at(i) - '0';
        u64 x = g0(v[0]);
        u64 y = g0(v[1]);
        u64 z = g0(v[2]);

        if((crt == x && f[x] > 0 && (i != 0 || x != 0)) || (crt == y && f[y] > 0) || (crt == z && f[z] > 0))
        {
            if(crt == x)
            {
                res.push_back(x + '0');
                f[x] -= 1;
            }
            else
            {
                if(crt == y)
                {
                    res.push_back(y + '0');
                    f[y] -= 1;
                }
                else
                {
                    res.push_back(z + '0');
                    f[z] -= 1;
                }
            }

            for(u64 j = i + 1; j < len; j++)
            {
                crt = s.at(j) - '0';
                if(crt == x && f[x] > 0)
                {
                    res.push_back(x + '0');
                    f[x] -= 1;
                    continue;
                }
                else
                {
                    if(crt == y && f[y] > 0)
                    {
                        res.push_back(y + '0');
                        f[y] -= 1;
                        continue;
                    }

                    if(crt == z && f[z] > 0)
                    {
                        res.push_back(z + '0');
                        f[z] -= 1;
                        continue;
                    }

                    if(crt > z)
                    {
                        next_permutation(res.begin(), res.end());
                        res.append(f[x], x + '0');
                        res.append(f[y], y + '0');
                        res.append(f[z], z + '0');
                        break;
                    }
                    else
                    {
                        if(crt < x)
                        {
                            res.append(f[x], x + '0');
                            res.append(f[y], y + '0');
                            res.append(f[z], z + '0');
                            break;
                        }
                        else
                        {
                            if(crt < y)
                            {
                                res.append(1, y + '0');
                                res.append(f[x], x + '0');
                                if(f[y] > 1)
                                {
                                    res.append(f[y] - 1, y + '0');
                                }
                                res.append(f[z], z + '0');
                                break;
                            }
                            else
                            {
                                res.append(1, z + '0');
                                res.append(f[x], x + '0');
                                res.append(f[y], y + '0');

                                if(f[z] > 1)
                                {
                                    res.append(f[z] - 1, z + '0');
                                }

                                break;
                            }
                        }
                    }
                }
            }

            break;
        }
        else
        {
            if(crt < x)
            {
                if(x == 0)
                {
                    res.append(1, y + '0');
                    res.append(f[x], x + '0');
                    if(f[y] > 1)
                    {
                        res.append(f[y] - 1, y + '0');
                    }
                    res.append(f[z], z + '0');
                }
                else
                {
                    res.append(f[x], x + '0');
                    res.append(f[y], y + '0');
                    res.append(f[z], z + '0');
                }

                break;
            }
            else
            {
                if(crt < y)
                {
                    res.append(1, y + '0');
                    res.append(f[x], x + '0');
                    if(f[y] > 1)
                    {
                        res.append(f[y] - 1, y + '0');
                    }
                    res.append(f[z], z + '0');
                    break;
                }
                else
                {
                    if(crt < z)
                    {
                        res.append(1, z + '0');
                        res.append(f[x], x + '0');
                        res.append(f[y], y + '0');
                        if(f[z] > 1)
                        {
                            res.append(f[z] - 1, z + '0');
                        }
                        break;
                    }
                }
            }
        }
    }

    return res;
}

int main()
{
    ifstream cin {"tcif.in"};
    ofstream cout {"tcif.out"};

    u64 a;
    cin >> a;

    u64 b;
    cin >> b;

    u64 c;
    cin >> c;

    u64 c1;
    cin >> c1;

    u64 c2;
    cin >> c2;

    u64 c3;
    cin >> c3;

    string n;
    cin >> n;

    cout << nr(a, b, c, c1, c2, c3, n);

    return 0;
}

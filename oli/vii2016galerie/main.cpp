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

void dig(vector<vector<bool>>& v, vector<int>& c, int l, int w)
{
    int len = c.size();
    int x = w + l + 1 + w;
    int y = w + 1 + 2 * w + 2 * l;
    int cn = 0;

    vector<bool> okay(len, true);
    while(cn < len)
    {
        vector<tuple<int, int>> dug(len);
        for(int i = 0; i < len; i++)
        {
            if(okay[i])
            {
                if(c[i] > 0 && c[i] <= w)
                {
                    for(int j = 0; j < l; j++)
                    {
                        if(v[j][c[i] - 1] == false)
                        {
                            v[j][c[i] - 1] = true;
                            dug[j] = {j, c[i] - 1};
                            break;
                        }
                        else
                        {
                            okay[i] = false;
                            cn += 1;
                            for(int k = 0; k < len; k++)
                            {
                                if(get<0>(dug[k]) == j && get<1>(dug[k]) == c[i] - 1)
                                {
                                    okay[k] = false;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }
                else
                {

                    if(c[i] > w + 1 && c[i] <= l + w)
                    {
                        for(int j = w - 1; j > -1; j--)
                        {
                            if(v[c[i] - w - 1][j] == false)
                            {
                                v[c[i] - w - 1][j] = true;
                                dug[j] = {c[i] - w - 1, j};
                                break;
                            }
                            else
                            {
                                okay[i] = false;
                                cn += 1;
                                for(int k = 0; k < len; k++)
                                {
                                    if(get<0>(dug[k]) == c[i] - w - 1 && get<1>(dug[k]) == j)
                                    {
                                        okay[k] = false;
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                    }
                    else
                    {

                        if(c[i] > l + w && c[i] <= l + 2 * w)
                        {
                            for(int j = l - 1; j > -1; j--)
                            {
                                if(v[j][x - c[i] - 1] == false)
                                {
                                    v[j][x - c[i] - 1] = true;
                                    dug[j] = {j, x - c[i] - 1};
                                    break;
                                }
                                else
                                {
                                    okay[i] = false;
                                    cn += 1;
                                    for(int k = 0; k < len; k++)
                                    {
                                        if(get<0>(dug[k]) == j && get<1>(dug[k]) == x - c[i] - 1)
                                        {
                                            okay[k] = false;
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                        else
                        {
                            for(int j = l - 1; j > -1; j--)
                            {
                                if(v[y - c[i] - w - 1][j] == false)
                                {
                                    v[y - c[i] - w - 1][j] = true;
                                    dug[j] = {y - c[i] - w - 1, j};
                                    break;
                                }
                                else
                                {
                                    okay[i] = false;
                                    cn += 1;
                                    for(int k = 0; k < len; k++)
                                    {
                                        if(get<0>(dug[k]) == y - c[i] - w - 1 && get<1>(dug[k]) == c[i] - 1)
                                        {
                                            okay[k] = false;
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int q1(vector<vector<bool>>& v, vector<int>& c, int l, int w)
{
    dig(v, c, l, w);
    int len = v[0].size();
    int sz = v.size();
    int mx = -1;

    for(int i = 0; i < sz; i++)
    {
        int s = 0;
        for(int j = 0; j < len; j++)
        {
            if(v[i][j])
            {
                s += 1;
            }
            else
            {
                break;
            }
        }

        mx = max(s, mx);
    }

    for(int i = 0; i < sz; i++)
    {
        int s = 0;
        for(int j = len; j > -1; j--)
        {
            if(v[i][j])
            {
                s += 1;
            }
            else
            {
                break;
            }
        }
        mx = max(s, mx);
    }

    for(int i = 0; i < len; i++)
    {
        int s = 0;
        for(int j = 0; j < sz; j++)
        {
            if(v[j][i])
            {
                s += 1;
            }
            else
            {
                break;
            }
        }

        mx = max(mx, s);
    }

    for(int i = 0; i < len; i++)
    {
        int s = 0;
        for(int j = sz; j > -1; j--)
        {
            if(v[j][i])
            {
                sz += 1;
            }
            else
            {
                break;
            }
        }

        mx = max(mx, s);
    }

    return mx;
}

int main()
{
    ios::sync_with_stdio(false);

    int q;
    cin >> q;

    int n;
    int m;
    cin >> n;
    cin >> m;

    int c;
    cin >> c;

    vi sp(c);
    for(int i = 0; i < c; i++)
    {
        cin >> sp[i];
    }

    vector<vector<bool>> v(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            v[i].push_back(false);
        }
    }

    if(q == 1)
    {
        cout << q1(v, sp, n, m);
    }
    else
    {
        //
    }

    return 0;
}

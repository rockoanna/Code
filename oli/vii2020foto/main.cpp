#include <bits/stdc++.h>

using namespace std;

int prb1 (vector<vector<int>>& v)
{
    int mx = -1;
    int lenr = v.size();
    int lenc = v[0].size();

    for(int i = 0; i < lenr; i++)
    {
        int c = 0;
        for(int j = 0; j < lenc; j++)
        {
            if(v[i][j] == 0)
            {
                c += 1;
            }
            else
            {
                mx = max(mx, c);
                c = 0;
            }
        }
    }

    return mx;
}

inline bool okay (vector<vector<int>>& v, int i, int j)
{
    if(i == 0)
    {
        return true;
    }

    if(v[i - 1][j] == 1)
    {
        return false;
    }

    if(j != 0 && v[i - 1][j - 1] == 1)
    {
        return false;
    }

    if(j + 1 != v[0].size() && v[i - 1][j + 1] == 1)
    {
        return false;
    }

    return true;
}

inline bool yes(vector<vector<int>>& v, int& i, int& j)
{
    int of[3] = {-1, 0, 1};
    int ov[3] = {100,10,1};

    int a = 0;

    for(int k = 0; k < 3; k++)
    {
        int crtj = j + of[k];
        if(crtj >= 0 && crtj < v[0].size())
        {
            if(v[i + 1][crtj] == 1)
            {
                a += ov[k];
            }
        }
    }

    if(a == 1)
    {
        i += 1;
        j += 1;

        return true;
    }

    if(a == 10)
    {
        i += 1;
        return true;
    }

    if(a == 100)
    {
        i += 1;
        j -= 1;

        return true;
    }

    return false;

}

tuple<int, int> prb2 (vector<vector<int>>& v)
{
    int h = -1;
    int f = 0;

    int lenr = v.size();
    int lenc = v[0].size();

    for(int i = 0; i < lenr; i++)
    {
        for(int j = 0; j < lenc; j++)
        {
            if(v[i][j] == 1)
            {
                if(okay(v, i, j))
                {
                    // cout << i << " " << j << endl;

                    f += 1;

                    bool ok = true;
                    int tmpj = j;
                    int tmpi = i;

                    int ch = 1;

                    while(ok && tmpi + 1 < v.size())
                    {
                        if(yes(v, tmpi, tmpj))
                        {
                            ch += 1;
                        }
                        else
                        {
                            ok = false;
                        }
                    }

                    h = max(ch, h);
                }
            }
        }
    }

    return {f, h};
}

int main ()
{
    ifstream cin {"foto.in"};
    ofstream cout {"foto.out"};

    int c;
    cin >> c;

    int r;
    cin >> r;

    int col;
    cin >> col;

    vector<vector<int>> v(r);
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < col; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    if(c == 1)
    {
        cout << prb1(v);
    }
    else
    {
        auto t = prb2(v);
        cout << get<0>(t) << " " << get<1>(t);
    }

    return 0;
}


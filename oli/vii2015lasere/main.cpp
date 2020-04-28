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

void laser(vector<vector<int>>& v, int x1, int y1, int c, int len)
{
    int x = x1 - 1;
    int y = y1 - 1;

    if(c == 1)
    {
        for(int i = 0; i < x; i++)
        {
            v[i][y] -= 1;
        }
    }
    else
    {
        if(c == 2)
        {
            for(int i = y + 1; i < len; i++)
            {
                v[x][i] -= 1;
            }
        }
        else
        {
            if(c == 3)
            {
                for(int i = x + 1; i < len; i++)
                {
                    v[i][y] -= 1;
                }
            }
            else
            {
                for(int i = 0; i < y; i++)
                {
                    v[x][i] -= 1;
                }
            }
        }
    }
}

bool q1(vector<vector<int>>& v, int x, int y)
{
    array<int, 3> a = {-1, 0, 1};

    int len = v[x].size();

    for(auto i : a)
    {
        for(auto j : a)
        {
            if(x + i < 0 || x + i >= len || y + j < 0 || y + j >= len)
            {
                continue;
            }

            if(v[x][y] <= v[x + i][y + j])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

int q2(vector<vector<int>>& v, int s)
{
    int count_ = 0;
    vector<vector<bool>> f(s);

    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < s; j++)
        {
            f[i].push_back(false);
        }
    }

    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < s; j++)
        {
            if(q1(v, i, j))
            {
                f[i][j] = true;
            }
        }
    }

    bool okay = false;
    for(int i = 0; i < s; i++)
    {
        okay = false;
        for(int j = 1; j < s; j++)
        {
            if(f[i][j])
            {
                if(f[i][j - 1])
                {
                    okay = true;
                }
            }
            else
            {
                if(okay)
                {
                    count_ += 1;
                    okay = false;
                }
            }
        }
    }

    return count_;
}

int main()
{
    ios::sync_with_stdio(false);

    int q;
    cin >> q;

    int s;
    cin >> s;

    int m;
    cin >> m;

    vector<vector<int>> v(s);

    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < s; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        int y;
        cin >> y;

        int c;
        cin >> c;

        laser(v, x, y, c, s);
    }

    if(q == 1)
    {
        int count_ = 0;
        for(int i = 0; i < s; i++)
        {
            for(int j = 0; j < s; j++)
            {
                if(q1(v, i, j))
                {
                    count_ += 1;
                }
            }
        }

        cout << count_ << endl;
    }
    else
    {
        cout << q2(v, s) << endl;
    }

//    for(int i = 0; i < s; i++)
//    {
//        for(int j = 0; j < s; j++)
//        {
//            cout << v[i][j] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}

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

inline int check_lines(vector<vector<int>>& v)
{
    int len = v[0].size();
    int winner = 0;
    for(int i = 0; i < len; i++)
    {
        winner = v[i][0];
        if(winner  == 0)
        {
            continue;
        }
        for(int j = 1; j < len; j++)
        {
            if(v[i][j] != winner)
            {
                winner = 0;
                break;
            }
        }
        if(winner  != 0)
        {
            return winner;
        }
    }
    return winner;
}

inline int check_columns(vector<vector<int>>& v)
{
    int len = v[0].size();
    int winner = 0;
    for(int j = 0; j < len; j++)
    {
        winner = v[0][j];
        if(winner  == 0)
        {
            continue;
        }
        for(int i = 1; i < len; i++)
        {
            if(v[i][j] != winner)
            {
                winner = 0;
                break;
            }
        }
        if(winner != 0)
        {
            return winner;
        }
    }
    return winner;
}


inline int check_p_diagonal(vector<vector<int>>& v)
{
    int len = v[0].size();
    int winner = v[0][0];
    if(winner  == 0)
    {
        return winner;
    }
    for(int i = 1; i < len; i++)
    {
        if(v[i][i] != winner)
        {
            return 0;
        }

    }
    return winner;
}

inline int check_p_diagonal_a(vector<vector<int>>& v)
{
    int len = v[0].size();
    int winner = v[0][1];
    if(winner  == 0)
    {
        return winner;
    }
    for(int i = 1; i < len-1; i++)
    {
        if(v[i][i+1] != winner)
        {
            return 0;
        }

    }
    return winner;
}

inline int check_p_diagonal_b(vector<vector<int>>& v)
{
    int len = v[0].size();
    int winner = v[1][0];
    if(winner  == 0)
    {
        return winner;
    }
    for(int i = 2; i < len; i++)
    {
        if(v[i][i-1] != winner)
        {
            return 0;
        }

    }
    return winner;
}

inline int check_s_diagonal(vector<vector<int>>& v)
{
    int len = v[0].size();
    int winner = v[0][len-1];
    if(winner  == 0)
    {
        return winner;
    }
    for(int i = 1; i < len; i++)
    {
        if(v[i][len- 1 -i] != winner)
        {
            return 0;
        }

    }
    return winner;
}

inline int check_s_diagonal_a(vector<vector<int>>& v)
{
    int len = v[0].size();
    int winner = v[0][len-2];
    if(winner  == 0)
    {
        return winner;
    }
    for(int i = 1; i < len-1; i++)
    {
        if(v[i][len - 2 -i] != winner)
        {
            return 0;
        }

    }
    return winner;
}

inline int check_s_diagonal_b(vector<vector<int>>& v)
{
    int len = v[0].size();
    int winner = v[1][len-1];
    if(winner  == 0)
    {
        return winner;
    }
    for(int i = 2; i < len; i++)
    {
        if(v[i][len - i] != winner)
        {
            return 0;
        }

    }
    return winner;
}

inline int win(vector<vector<int>>& v)
{
    int res = check_lines(v);
    if(res > 0)
    {
        return res;
    }
    res = check_columns(v);
    if(res > 0)
    {
        return res;
    }
    res = check_p_diagonal(v);
    if(res > 0)
    {
        return res;
    }
    res = check_p_diagonal_a(v);
    if(res > 0)
    {
        return res;
    }
    res = check_p_diagonal_b(v);
    if(res > 0)
    {
        return res;
    }
    res = check_s_diagonal(v);
    if(res > 0)
    {
        return res;
    }
    res = check_s_diagonal_a(v);
    if(res > 0)
    {
        return res;
    }
    res = check_s_diagonal_b(v);
    if(res > 0)
    {
        return res;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);

    ifstream cin {"joc.in"};
    ofstream cout {"joc.out"};

    int c;
    cin >> c;

    int d;
    cin >> d;

    int k;
    cin >> k;

    int t = 0;
    int s = 0;

    int longest =0;
    for(int tt = 0; tt < k; tt++)
    {
        vector<vector<int>> v(d);
        bool done = false;

        for(int i = 0; i < d; i++)
        {
            for(int j = 0; j < d; j++)
            {
                v[i].push_back(0);
            }
        }
        int i = 0;
        for(i = 0; i < d * d; i++)
        {
            int x;
            cin >> x;
            // cout << x << endl;

            if(!done)
            {
                if(tt % 2 == 0)
                {
                    if(i % 2 == 0)
                    {
                        if(x % d > 0)
                        {
                            v[x / d][x % d - 1] = 1;
                        }
                        else
                        {
                            v[(x / d) - 1][d - 1] = 1;
                        }
                    }
                    else
                    {
                        if(x % d > 0)
                        {
                            v[x / d][x % d - 1] = 2;
                        }
                        else
                        {
                            v[(x / d) - 1][d - 1] = 2;
                        }
                    }
                }
                else
                {
                    if(i % 2 == 0)
                    {
                        if(x % d > 0)
                        {
                            v[x / d][x % d - 1] = 2;
                        }
                        else
                        {
                            v[x / d - 1][d - 1] = 2;
                        }
                    }
                    else
                    {
                        if(x % d > 0)
                        {
                            v[x / d][x % d - 1] = 1;
                        }
                        else
                        {
                            v[x / d - 1][d - 1] = 1;
                        }
                    }
                }
            }

            if(i >= d && !done)
            {

                int z = win(v);
                if(z > 0)
                {
                    longest = max(longest,i+1);
                    done = true;
                    if(z == 1)
                    {
                        t += 1;
                    }
                    else
                    {
                        s += 1;
                    }
                }
            }
        }
    }

    if(c == 1)
    {
        cout << t << " " << s;
    }
    else
    {
        cout << longest;
    }

    return 0;
}

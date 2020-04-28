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

void t1(vector<int>& v)
{
    int len = v.size();
    int x = v[len - 1];
    for(int i = len - 2; i > -1; i--)
    {
        if(v[i] > x)
        {
            int tmp = v[len - 1];
            v[len - 1] = v[i];
            v[i] = tmp;
            break;
        }
    }
}

deque<int> digits(int a)
{
    deque<int> d;
    while(a > 0)
    {
        d.push_front(a % 10);
        a /= 10;
    }

    return d;
}

i64 t2(vector<int>& v, int a)
{
    deque<int> d = digits(a);
    int len = v.size();
    int s = d.size();
    i64 res = 0;

    for(int i = 0; i < len; i++)
    {
        if(v[i] == d[0])
        {
            if(i + 1 == len)
            {
                return res;
            }

            int x = d[0];
            int z = 0;
            int y = i + 1;
            while(y < len)
            {
                bool okay = false;
                for(int k = y; k < len; k++)
                {
                    if(z + 1 >= s)
                    {
                        y = k;
                        x = d[0];
                        res += 1;
                        okay = true;
                        z = 0;
                        break;
                    }

                    if(v[k] == d[z + 1])
                    {
                        z += 1;
                        x += 1;
                    }
                }

                if(!okay)
                {
                    break;
                }

            }
        }
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    int a;
    cin >> a;
    int n;
    cin >> n;

    vi v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if(t == 1)
    {
        t1(v);
        for(int i = 0; i < n; i++)
        {
            cout << v[i];
        }
    }
    else
    {
        cout << t2(v, a);
    }

    return 0;
}

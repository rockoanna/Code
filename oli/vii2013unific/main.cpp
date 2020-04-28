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

deque<i32> digits(i64 n)
{
    deque<int> d;
    while(n > 0)
    {
        d.push_front(n % 10);
        n /= 10;
    }

    return d;
}

void dig_count(deque<int> d, map<int,int>& m)
{
    for(int i = 0; i < d.size(); i++)
    {
        m[d[i]] += 1;
    }
}

inline bool can_unify(i64 x, i64 y, i64 u)
{
    deque<int> d1 = digits(x);
    deque<int> d2 = digits(y);
    deque<int> d3 = digits(u);

    if(d3.size() == d1.size() + d2.size()) {}
    return
}

i64 unify(i64 x, i64 l)
{
    deque<int> d1 = digits(x);
    deque<int> d2 = digits(l);
    int len1 = d1.size();
    int len2 = d2.size();
    vector<bool> v1(len1, true);
    vector<bool> v2(len2, true);

    int c = 0;

    for(int i = 0; i < len1; i++)
    {
        for(int j = 0; j < len2; j++)
        {
            if(d1[i] == d2[j])
            {
                v1[i] = false;
                v2[j] = false;
                c += 1;
            }
        }
    }

    if(c == len2)
    {
        return -1;
    }

    i64 n = 0;
    for(int i = 0; i < len2; i++)
    {
        if(v2[i])
        {
            n *= 10;
            n += d2[i];
        }
    }

    for(int i = 0; i < len1; i++)
    {
        if(v1[i])
        {
            n *= 10;
            n += d1[i];
        }
    }

    return n;
}

int main()
{
    ios::sync_with_stdio(false);

    i64 n;
    cin >> n;

    map<int, int> m;
    vector<u64> v;
    for(int i = 0; i < n; i++)
    {
        i64 x;
        cin >> x;

        deque<int> d = digits(x);
        dig_count(d, m);

        if(i > 0)
        {
            i64 y = unify(x, v.back());
            if(can_unify(x, v.back(), y))
            {
                if(y == -1)
                {
                    v.pop_back();
                }
                else
                {
                    v.back() = y;
                }
            }
            else
            {
                v.push_back(x);
            }
        }
        else
        {
            v.push_back(x);
        }

    }

    while(true)
    {
        bool c = false;
        for(auto it =v.begin(); it!=v.end(); it++)
        {
            if(it ==v.begin())
            {
                continue;
            }
            auto pv  = prev(it,1);
            i64 y = unify(*it, *pv);
            if(can_unify(*it, *pv, y))
            {
                if(y == -1){
                    it = v.erase(it);
                }
                *pv = y;
                it = v.erase(it);
                c = true;
            }
        }

        if(!c)
        {
            break;
        }
    }

    int mx = m[0];
    int nr = 0;
    for(int i = 1; i < 10; i++)
    {
        if(m[i] > mx)
        {
            nr = i;
            mx = m[i];
        }
        else
        {
            if(m[i] == mx)
            {
                nr = min(i, nr);
            }
        }
    }

    int vs = v.size();
    cout << nr << endl;

    if(vs > 0)
    {
        cout << vs << endl;

        for(int i = 0; i < vs; i++)
        {
            cout << v[i] << " ";
        }
    }
    return 0;
}

int main0()
{
    std::vector<int> v{ 3, 1, 4 };

    auto it = --v.end();

    std::cout << *it << '\n';

    auto pv = prev(it, 2);

    std::cout << *pv << '\n';


    std::cout << *it << '\n';

    auto x = &v.back();
    *x = 10;
    cout<<v.back();
}

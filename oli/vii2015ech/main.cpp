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

bool ech(deque<int> n)
{
    int sum[2] = {0,0};

    for(int i=0; i<n.size(); i++)
    {
        sum[i%2]+=n[i];
    }

    return sum[0] == sum[1];
}

deque<int> digits(string s)
{
    deque<int> d;
    for(auto c : s)
    {
        d.push_front(c - '0');
    }

    return d;
}

void oneadd (deque<int>& d)
{
    int c = 1;
    for(int i = 0; i < d.size(); i++)
    {
        if(c == 0)
        {
            return;
        }

        int x = d[i];
        d[i] = (c + x) % 10;
        c = (c + x) / 10;
    }

    if(c > 0)
    {
        d.push_back(c);
    }

//    for(auto i : d)
//    {
//        cout << i;
//    }
//
//    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);

    string n;
    cin >> n;

    deque<int> d = digits(n);

    //int i = 0;
    do
    {
       // i++;
        oneadd(d);
    }while(!ech(d));

   // cout << i << endl;

    for(int i = 0; i < d.size(); i++)
    {
        cout << d[d.size() - i - 1];
    }

    return 0;
}

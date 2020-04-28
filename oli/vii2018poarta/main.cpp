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

tuple<string, int> div2(string s)
{
    int r = 0;
    string res = "";

    int len = s.size();
    for(int i = 0; i < len; i++)
    {
        int x = ((r * 10 + (s[i] - '0')) / 2);
        char c = x + '0';

        if(i == 0 && c == '0')
        {
            r = (s[i] - '0') % 2;
            continue;
        }

        res.push_back(c);
        r = (s[i] - '0') % 2;
    }

    return{res, r};
}

u64 done(int n, string s, int c)
{
    u64 res = 0;
    auto t = div2(s);
    string nn = to_string(n);
    u64 p = 0;

    while(get<0>(t) > nn)
    {
        res += 1;
        res += get<1>(t);

        p += 2;
        p += get<1>(t);

        t = div2(get<0>(t));
    }

    res += 1;
    res += get<1>(t);

    p += 2;
    p += get<1>(t);

    if(c == 1){
        return res + 1;
    }else{
        return p;
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int c;
    cin >> c;

    int n;
    cin >> n;

    string s;
    cin >> s;

    cout << done(n, s, c);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define g0 get<0>
#define g1 get<1>

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


inline ss in_line()
{
    st line;
    getline(cin, line);
    return ss(line);
}


int main()
{
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    u64 len = s.size();

    u64 i = 0;
    u64 j = len - 1;

    vector<u64> v;
    v.reserve(len);

    while(i < j)
    {
        if(s[i] == ')')
        {
            i++;
            continue;
        }

        if(s[j] == '(')
        {
            j--;
            continue;
        }

        if(i < j)
        {
            v.push_back(i + 1);
            v.push_back(j + 1);

            i++;
            j--;

        }
        else
        {
            break;
        }
    }

    if(v.empty())
    {
        cout << 0;
    }
    else
    {
        cout << 1 << endl;
        cout << v.size() << endl;
        sort(v.begin(), v.end());

        for(auto x : v)
        {
            cout << x << " ";
        }
    }

    return 0;
}

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

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int tt = 0; tt < t; tt++)
    {
        u64 n;
        cin >> n;

        vector<u64> v(n);

        u64 mx = 0;

        for(u64 i = 0; i < n; i++)
        {
            cin >> v[i];
            mx = max(v[i], mx);
        }

        if(mx > n)
        {
            cout << 0 <<  endl;
            continue;
        }

        vector<tuple<u64, u64>> res;
        vector<u64> vals = {mx};
        if(n-mx !=mx)
        {
            vals.push_back(n-mx);
        }
        for(auto len: vals)
        {
            set<u64> l;
            set<u64> r;
            bool ok = true;

            for(u64 i = 0; i < len; i++)
            {
                if(l.count(v[i]) == 0)
                {
                    l.insert(v[i]);
                }
                else
                {
                    ok = false;
                    break;
                }
            }

            if(ok)
            {
                ok = (*l.rbegin()) == l.size();
            }

            if(ok)
            {
                for(u64 i = len; i < n; i++)
                {
                    if(r.count(v[i]) == 0)
                    {
                        r.insert(v[i]);
                    }
                    else
                    {
                        ok = false;
                        break;
                    }
                }
            }

            if(ok)
            {
                ok = (*r.rbegin()) == r.size();
            }

            if(ok)
            {
//                cout<<"SOLUTION" << endl;
//                for(auto e : l)
//                {
//                    cout << e << " ";
//                }
//
//                cout << endl;
//
//                for(auto e : r)
//                {
//                    cout << e << " ";
//                }
//
//                cout << endl;

                res.emplace_back(l.size(), r.size());
            }

        }

        cout << res.size() << endl;
        for(auto x : res)
        {
            cout << g0(x) << " " << g1(x) << endl;
        }
    }

    return 0;
}

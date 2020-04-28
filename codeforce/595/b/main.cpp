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

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int tt = 0; tt < t; tt++)
    {
        u64 n;
        cin >> n;

        vl perm(n + 1);
        vl book(n + 1, 0);
        iota(book.begin(),book.end(), 0);
        vl res(n + 1, 0);
        u64 solved =0;

        for(u64 i = 1; i <= n; i++)
        {
            cin >> perm[i];
        }

        int day =1;
        vl day_book(n+1, 0);
        while(solved != n)
        {
            fill(day_book.begin(),day_book.end(),0);
            for(int i=1; i<n+1; i++)
            {
                auto np =perm[i];
                day_book[np] = book[i];
                if(day_book[np] == np && res[i] == 0)
                {
                    solved+=1;
                    res[i] = day;
                }
            }
            book = day_book;
            day+=1;
        }

        for(u64 i = 1; i <= n; i++)
        {
            cout << res[i] << " ";
        }

        cout << endl;
    }

    return 0;
}

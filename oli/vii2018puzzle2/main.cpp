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

inline bool yes(int n)
{
    int x = n % 10;
    n /= 10;

    while(n > 0)
    {
        if(n % 10 != x)
        {
            return false;
        }

        n /= 10;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    ifstream cin {"puzzle.in"};
    ofstream cout {"puzzle.out"};

    chrono::steady_clock::time_point start = chrono::steady_clock::now();


    int n;
    cin >> n;

    vector<int> p(n);

    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
    }



    int res = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int y = p[i] + p[j];
            if(yes(y))
            {
                res += 1;
            }
        }
    }

    cout << res;

    chrono::steady_clock::time_point stop= chrono::steady_clock::now();
    std::cout << "Time difference = " << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << "ms" << endl;
    return 0;
}

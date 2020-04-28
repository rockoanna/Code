#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
#include <cmath>

using namespace std;

typedef stringstream ss;
typedef double db;
typedef int64_t i64;
typedef int32_t i32;
typedef uint64_t u64;
typedef uint32_t u32;
typedef string st;

typedef vector<i64> vl;
typedef vector<i32> vi;
typedef vector<char> vc;
typedef vector<db> vd;
typedef vector<st> vs;


int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int x = 0; x < t; x++)
    {
        int n;
        cin >> n;

        i64 y = 0;
        vl v(n);

        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            y += v[i];
        }

        i64 m = -1000000000;
        i64 b = m;
        i64 start = -1;
        for(int i = 0; i < n; i++)
        {

            if(v[i] >= v[i] + m){
                start = i;
                m= v[i];
            }else{
                m = v[i] + m;
            }

            if(start > 0 || i != n - 1){
                b = max(b, m);
            }

        }

        if(b >= y)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }

    }

    return 0;
}

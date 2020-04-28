#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int x = 0; x < t; x++)
    {
        int n;
        cin >> n;
        cin.ignore();

        string s;
        getline(cin, s);
        stringstream ss(s);

        int64_t delta = 0;

        vector<int> v1(n);
        vector<int> v2(n);
        for(int i = 0; i < 2 * n; i++)
        {
            int a;
            ss >> a;
            if (a != 1)
            {
                a = -1;
            }
            if(i < n)
            {
                v1[i] = a;

            }
            else
            {
                v2[i - n] = a;

            }
            delta += a;
        }
        reverse(v1.begin(), v1.end());
        unordered_map<int32_t, int32_t> memo;
        memo.reserve(2 * n);
        memo.insert({0,0});
        int64_t nr = 0;

        for(int i = 0; i < n; i++)
        {
            nr += v2[i];
            if(memo.find(nr) == memo.end())
            {
                memo.insert({nr, i + 1});
            }
        }
        int res = 2 * n;
        auto fd = memo.find(delta);
        if(fd != memo.end())
        {
            res = (*fd).second;
        }

        int64_t t1 = 0;
        for(int i = 0; i < n; i ++)
        {
            t1 += v1[i];
            int left = delta - t1;
            auto fd = memo.find(left);
            if(fd != memo.end())
            {
                res =min(res, i+1+(*fd).second);
            }
        }
        cout << res << endl;
    }


    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int x = 0; x < n; x++)
    {
        string s;
        cin >> s;

        string h;
        cin >> h;

        int len1 = s.size();
        int len2 = h.size();
        bool okay = false;
        sort(s.begin(), s.end());

        for(int i = 0; i < len2 - len1 + 1; i++)
        {
            string x = h.substr(i, len1);
            sort(x.begin(), x.end());
            if(s == x)
            {
                okay = true;
                break;
            }
        }

        if(okay)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

    }

    return 0;
}

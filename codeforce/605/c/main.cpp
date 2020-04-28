#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int64_t l;
    cin >> l;

    int good;
    cin >> good;

    string s;
    cin >> s;

    vector<char> v(good);

    for(int i = 0; i < good; i++)
    {
        cin >> v[i];
    }

    uint64_t r = 0;
    uint64_t count_ = 0;

    for(int64_t i = 0; i < l; i++)
    {
        bool ok = false;
        for(auto c : v)
        {
            if(c == s[i])
            {
                ok = true;
                break;
            }
        }
        if(ok)
        {
            r += 1;
            count_ += r;
        }
        else
        {
            r = 0;
        }
    }

    cout << count_ << endl;

    return 0;
}

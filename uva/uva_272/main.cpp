#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string line;
    getline(cin, line, (char)0);
    string res;
    bool sq = true;
    for(char c:line)
    {
        if(c != '"')
        {
            res.push_back(c);
        }
        else
        {
            if(sq)
            {
                res.push_back('`');
                res.push_back('`');
            }
            else
            {
                res.push_back('\'');
                res.push_back('\'');
            }
            sq =!sq;
        }
    }
    cout << res;
    return 0;
}

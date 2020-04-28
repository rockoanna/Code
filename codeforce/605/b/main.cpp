#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int x = 0; x < n; x++)
    {
        string s;
        cin >> s;

        map<char, int32_t> freq;
        for(auto i : s)
        {
            freq[i]+=1;
        }

        int rl = min(freq['L'],freq['R']);
        int du = min(freq['D'],freq['U']);


        if(du == 0)
        {
            rl = min(rl, 1);
        }

        if(rl == 0)
        {
            du = min(du, 1);
        }

        cout << rl * 2 + du * 2 << endl;
        string res = string(rl, 'L')+string(du, 'U')+string(rl, 'R')+string(du, 'D');
        cout << res << endl;

    }


    return 0;
}

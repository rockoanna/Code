#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int l;
    cin >> l;

    int plat;
    cin >> plat;

    int j;
    cin >> j;

    vector<int> len(plat);
    int sum = 0;

    for(int i = 0; i < plat; i++)
    {
        cin >> len[i];
        sum += len[i];
    }

    if(sum == l)
    {
        cout << "YES" << endl;
        for(int i = 0; i < plat; i++)
        {
            for(int j = 0; j < len[i]; j++)
            {
                cout << i + 1 << " ";
            }
        }
    }
    else
    {
        vector<int> r(l);
        for(int i = 0; i < l; i++)
        {
            if(){}
        }
    }

    return 0;
}

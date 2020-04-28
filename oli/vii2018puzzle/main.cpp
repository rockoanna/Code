#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> pieces(n);

    for(int i = 0; i < n; i++)
    {
        cin >> pieces[i];
    }

    int res = 0;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            bool ok = true;
            int nr1 = pieces[i];
            int nr2 = pieces[j];
            int x = nr1 % 10 + nr2 % 10;
            nr1 = nr1 / 10;
            nr2 = nr2 / 10;

            while(nr1 != 0)
            {
                if(nr1 % 10 + nr2 % 10 == x)
                {
                    nr1 = nr1 / 10;
                    nr2 = nr2 / 10;
                }
                else
                {
                    ok = false;
                    break;
                }
            }

            if(ok == true)
            {
                res += 1;
            }
        }
    }

    cout << res << endl;


    return 0;
}

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    // ofstream cout {"out.text"};

    int t;
    cin >> t;

    for(int k = 0; k < t; k++)
    {
        int count_ = 0;

        int days;
        cin >> days;

        int p;
        cin >> p;

        vector<int> v(p);

        for(int j = 0; j < p; j++)
        {
            cin >> v[j];

        }

        for(int i = 1; i <= days; i++)
        {
            if(i % 7 != 0 && i % 7 != 6)
            {
                for(auto n : v)
                {
                    if(i % n == 0)
                    {
                        count_ += 1;
                        break;
                    }
                }
            }
        }

        cout << count_ << endl;
    }


return 0;
}

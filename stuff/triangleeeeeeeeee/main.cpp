#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int count_ = 0;

    for(int i = 1; i <= n && count_ < n; i++)
    {
        int top = (i + i - 1) * 2 + 1;
        for(int j = 1; j <= top; j++)
        {
            if(count_ < n)
            {
                if(j <= top / 2 + 1)
                {
                    cout << j << " ";
                    count_ += 1;
                }
                else
                {
                    cout << top - j + 1 << " ";
                    count_ += 1;
                }
            }
            else
            {
                break;
            }
        }

        cout << endl;
    }


    return 0;
}

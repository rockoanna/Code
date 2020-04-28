#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int count_ = 0;
    bool okay = false;

    for(int i = 0; i < n && !okay; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(count_ < n)
            {
                cout << j << " ";
                count_ += 1;
            }
            else
            {
                okay = true;
                break;
            }
        }

    }


    return 0;
}

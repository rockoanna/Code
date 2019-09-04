#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    int b;
    cin >> b;

    while(b != -1)
    {

        if(a > b)
        {
            if(100 +(b - a) > a - b)
            {
                cout << (a - b) << endl;
            }
            else
            {
                cout << (100 +(b - a)) << endl;
            }

        }
        else
        {
            if(100 +(a - b) > b - a)
            {
                cout << (b - a) << endl;
            }
            else
            {
                cout << (100 +(a - b)) << endl;
            }
        }


        cin >> a;
        cin >> b;
    }


    return 0;
}

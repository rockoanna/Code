#include <iostream>
#include <string>

using namespace std;



int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        int len  = x.size();

        if(x=="1" || x=="4" || x=="78")
        {
            cout << "+" << endl;
        }
        else
        {
            if( len >= 3 && x[len - 1] == '5' && x[len - 2] == '3')
            {
                cout << "-" << endl;
            }
            else
            {
                if(len >= 3 && x[0] == '9' && x[len - 1] == '4')
                {
                    cout << "*" << endl;
                }
                else
                {
                    if(len >= 3 && x[0] == '1' && x[1] == '9' && x[2] == '0')
                    {
                        cout << "?" << endl;
                    }
                    else
                    {
                        cout << "+" << endl;
                    }
                }
            }
        }
    }
    return 0;
}

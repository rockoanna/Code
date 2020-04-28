#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int ds;
    int df;
    cin >> ds;
    cin >> df;

    int vs;
    int vf;
    cin >> vs;
    cin >> vf;

    int posd = ds;
    int posv = vs;
    bool okay = false;

    while(true)
    {
        if(posd == posv)
        {
            okay = true;
            break;
        }

        if(posd == df || posv == vf)
        {
            break;
        }

        if(posd != n)
        {
            posd += 1;
        }
        else
        {
            posd = 1;
        }

        if(posv != 1)
        {
            posv -= 1;
        }
        else
        {
            posv = n;
        }

    }

    if(okay)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }


    return 0;
}

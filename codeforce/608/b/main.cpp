#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int len;
    cin >> len;

    string s;
    cin >> s;

    int b = 0;
    int w = 0;

    for(int i = 0; i < len; i++)
    {
        if(s[i] == 'B')
        {
            b += 1;
        }
        else
        {
            w += 1;
        }
    }

    if(b == 0 || w == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        if(b % 2 == 1 && w % 2 == 1)
        {
            cout << - 1 << endl;
        }
        else
        {
            char c;
            char k;
            vector<int> v;

            if(b % 2 == 1)
            {
                if(w % 2 == 0)
                {
                    c = 'W';
                    k = 'B';
                }
            }
            else
            {
                if(w % 2 == 0)
                {
                    if(b < w)
                    {
                        k = 'B';
                        c = 'W';
                    }
                    else
                    {
                        k = 'W';
                        c = 'B';
                    }
                }
                else
                {
                    c = 'B';
                    k = 'W';
                }
            }

            for(int i = 0; i < len; i++)
            {
                if(s[i] == c && i + 1 != len)
                {
                    if(s[i + 1] == k)
                    {
                        s[i] = k;
                        s[i + 1] = c;
                    }
                    else
                    {
                        s[i] = k;
                        s[i + 1] = k;
                    }

                    v.push_back(i + 1);
                }
            }

            int sz = v.size();
            cout << sz << endl;
            for(int i = 0; i < sz; i++)
            {
                cout << v[i] << " ";
            }

        }

    }



    return 0;
}

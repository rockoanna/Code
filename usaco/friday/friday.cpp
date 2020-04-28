/*
ID: oanna.p1
TASK: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream cin("friday.in");
    ofstream cout("friday.out");

    int n;
    cin >> n;

    int months[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    vector<int> w(7);
    int day = 0;

    for(int i = 1900; i < n + 1900; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            w[day % 7] += 1;
            int d = months[j];
            if(j==1 &&  (i % 4 == 0 && (i % 100 != 0 || i == 2000)))
            {
                d+=1;
            }
            day+=d;
        }
    }


    for(int i = 0; i < 7; i++)
    {
        cout << w[i];
        if(i == 6)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }
    return 0;
}

/*
ID: oanna.p1
TASK: milk2
LANG: C++
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <algorithm>

#define g0 get<0>
#define g1 get<1>


using namespace std;



int main()
{
    ifstream cin {"milk2.in"};
    ofstream cout {"milk2.out"};


    int n;
    cin >> n;

    vector<tuple<int, int>> d(n);

    for(int i = 0; i < n; i++)
    {
        int f;
        cin >> f;
        int s;
        cin >> s;

        d[i] = {f, s};

    }

    sort(d.begin(), d.end());

    int s = g0(d[0]);
    int e = g1(d[0]);
    int mm = e - s;
    int mi = 0;

    int i = 1;
    while(i < n){
        int crts = g0(d[i]);
        int crte = g1(d[i]);

        if(crts <= e){
            e = max(e, crte);
            mm = max(mm, e - s);
        }else{
            mi = max(mi, crts - e);
            s = crts;
            e = crte;
            mm = max(mm, s - s);
        }
        i += 1;
    }


    cout << mm << " " << mi << endl;

    return 0;
}

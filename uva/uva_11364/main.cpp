#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int np;
        cin >> np;
        vector<int>p(np);
        for(int j = 0; j < np; j++){
            cin >> p[j];
        }
        sort(p.begin(), p.end());
        cout << (p[np - 1] - p[0])*2 << endl;
    }

    return 0;
}

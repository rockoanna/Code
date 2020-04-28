#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> bd;
struct ArrDesc{
    string name;
    int dim;
    vector<bd> bounds;
};

int main()
{
    int n;
    cin >> n;

    int x;
    cin >> x;

    vector<string> names(n);
    vector<vector<int>> nr;

    for(int i = 0; i < n; i++)
    {
        cin >> names[i];

        vector<int> v;

        int base;
        cin >> base;
        v.push_back(base);
        int b;
        cin >> b;
        v.push_back(b);
        int d;
        cin >> d;
        v.push_back(d);

        for(int j = 0; j < d * 2; j++)
        {
            int low;
            cin >> low;
            v.push_back(low);

            int up;
            cin >> up;
            v.push_back(up);
        }

        nr.push_back(v);
    }



    return 0;
}

/*
ID: oanna.p1
TASK: gift1
LANG: C++
*/

#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    ifstream cin("gift1.in");
    ofstream cout("gift1.out");
    int n;
    cin >> n;

    vector<string> v(n);
    unordered_map<string, int> m;
    m.max_load_factor(0.5);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]] = 0;
    }

    string s;
    while(cin >> s)
    {
        int money;
        cin >> money;

        int nr_pers;
        cin >> nr_pers;

        for(int j = 0; j < nr_pers; j++)
        {
            string name;
            cin >> name;

            m[name] += money / nr_pers;
        }

        if(nr_pers > 0)
        {
            m[s] -= money;
            m[s] += money % nr_pers;
        }
    }

    for(auto i : v)
    {
        cout << i << " " << m[i] << '\n';
    }


    return 0;
}

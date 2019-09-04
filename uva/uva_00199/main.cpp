#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int tc = 0;
    int n;

    while(cin >> n)
    {
        if(tc > 0){
            cout<<endl;
        }
        tc+=1;
        map<string, int> cat;
        vector<string> names(n);
        for(int i = 0; i < n; i++)
        {
            cin >> names[i];
            cat[names[i]] = 0;
        }
        for(int i = 0; i< n; i++)
        {
            string name;
            cin >> name;
            int money;
            cin >> money;
            int pers;
            cin >> pers;
            if(pers != 0){
                int give = money / pers;
                cat[name] -= (money - money % pers);
                for(int j = 0; j < pers; j++)
                {
                    string p;
                    cin >> p;
                    cat[p] += give;
                }
            }
        }
        for(auto name:names)
        {
            cout << name << " " << cat[name] << endl;
        }
    }
    return 0;
}

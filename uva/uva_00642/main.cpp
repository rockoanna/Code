#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <fstream>

using namespace std;


int main()
{
    //ofstream cout {"out.txt"};
    unordered_map<string, set<string>> d;
    string s;
    while(true)
    {
        cin >> s;
        if(s == "XXXXXX")
        {
            break;
        }
        string s_c(s);
        sort(s_c.begin(),s_c.end());
        auto &res = d[s_c];
        res.insert(s);
    }
//    for(auto kv : d)
//    {
//        cout << kv.first <<" { " ;
//        auto words = kv.second;
//        for(auto w: words)
//        {
//            cout << w << '\n';
//        }
//        cout <<"}"<<endl;
//
//    }
    string word;
    while(true)
    {
        cin >> word;
        if(word == "XXXXXX")
        {
            break;
        }
        sort(word.begin(), word.end());
        auto res = d.find(word);
        if(res != d.end())
        {
            auto words = (*res).second;
            for(auto w: words)
            {
                cout << w << '\n';
            }

        }
        else
        {
            cout << "NOT A VALID WORD" << '\n';
        }
        cout << "******" << '\n';
    }
    return 0;
}

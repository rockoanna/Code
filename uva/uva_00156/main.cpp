#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool is_anagram(string &s1, string &s2)
{
    map <char, int> d;
    for(auto j : s1)
    {
        char c = tolower(j);
        auto r = d.find(c);
        if(r == d.end())
        {
            d[c] = 1;
        }
        else
        {
            (*r).second += 1;
        }
    }

    for(auto i : s2)
    {
        char c = tolower(i);
        auto r = d.find(c);
        if(r == d.end())
        {
            return false;
        }
        else
        {
            (*r).second -= 1;
            if((*r).second == 0)
            {
                d.erase(r);
            }
        }
    }
    return d.empty();

}

int main()
{
    string s1;
    vector<string> txt;
    while(getline(cin, s1))
    {
        if(s1=="#")
        {
            break;
        }

        stringstream s(s1);
        string s2;
        while(s>>s2)
        {
            txt.push_back(s2);
        }
    }
    sort(txt.begin(), txt.end());
    for(auto s : txt)
    {
        bool ana = false;
        for(auto t : txt)
        {
            if( s != t &&  s.size()==t.size() && is_anagram(s,t)){
                ana =true;
                break;
            }
        }
        if(!ana){
            cout << s<<endl;
        }
    }

    return 0;
}

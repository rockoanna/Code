#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string clean(string &w)
{
    string res;
    for(auto c : w)
    {
        if(!isspace(c))
        {
            res.push_back(c);
        }
    }
    return res;
}

bool is_anagram(string &w1, string &w2)
{
    string s1 = clean(w1);
    string s2 = clean(w2);

    if(s1.size() != s2.size())
    {
        return false;
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;

}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();


    for(int t = 0; t < n; t++)
    {
        vector<string> words;
        words.reserve(n);

        string s;
        getline(cin, s);
        while(s.length() > 0 )
        {
            words.push_back(s);
            getline(cin, s);
        }
        sort(words.begin(), words.end());

        for(int i = 0; i < words.size(); i++)
        {
            for(int j = i+1; j < words.size(); j++)
            {
                if(is_anagram(words[i], words[j]))
                {
                    cout << words[i] << " = " << words[j] << '\n';
                }
            }
        }
        if(t+1 < n)
        {
            cout << '\n';
        }

    }

    return 0;
}


int main1()
{
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();


    for(int t = 0; t < n; t++)
    {
        map<string,vector<string>> anas;
        string s;
        getline(cin, s);
        while(s.length() > 0 )
        {
            string root_s = clean(s);
            sort(root_s .begin(),root_s .end() );

            auto res = anas.find(root_s );
            if(res == anas.end())
            {
                vector<string> b;
                b.push_back(s);
                anas.insert({root_s,b});
            }
            else
            {
                (*res).second.push_back(s);
            }

            getline(cin, s);
        }


        for(auto kv : anas)
        {
            auto bucket = kv.second;
            sort(bucket.begin(), bucket.end());
            for(int i=0; i<bucket.size(); i++)
            {
                for(int j=i+1; j<bucket.size(); j++)
                {
                    cout<< bucket[i] << " = "<<bucket[j]<<'\n';
                }
            }

        }
        if(t+1 < n)
        {
            cout << '\n';
        }

    }

    return 0;
}


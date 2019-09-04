#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>

using namespace std;

string clean(string &s)
{
    string res;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            res.push_back(s[i]);
        }
    }

    return res;
}


bool is_magical(string &s, int k)
{
    vector<string> v;
    v.reserve(k);
    for(int i=0; i<s.size(); i+=k)
    {
        v.push_back(s.substr(i,k));
    }
    for(int i=0; i<k; i++)
    {
        for(int j=i; j<k; j++)
        {
            if(v[i][j] != v[j][i] || v[i][j] != v[k-1-j][k-1-i] )
            {
                return false;
            }
        }
    }
    return true;
}

const char el = '\n';

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    //ofstream cout {"out.txt"};
    //ifstream cin {"in.txt"};

    for(int i = 0; i < n; i++)
    {
        string txt;
        getline(cin, txt);
        string s = clean(txt);
        int k = round(sqrt(s.size()));
        //cout<<txt.size()<<" "<<s.size()<<" "<<k<<endl;
        cout << "Case #" << i + 1 << ":"<< el;
        if(k * k != s.size() || !is_magical(s, k))
        {
            cout << "No magic :(" << el;
        }
        else
        {
            cout << k << el;
        }
    }

    return 0;
}

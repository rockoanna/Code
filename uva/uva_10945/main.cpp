#include <iostream>

using namespace std;

bool is_palindrom(string &s)
{
    string res;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            res.push_back(s[i]);
        }
        else
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
            {
                res.push_back(tolower(s[i]));
            }
        }
    }

    for(int i = 0; i < res.size() / 2; i++)
    {
        if(res[i] != res[res.size() - i - 1])
        {
            return false;
        }
    }
    return true;
}


int main()
{
    string txt;
    getline(cin, txt);

    while(txt != "DONE") {
        if(is_palindrom(txt) == true){
            cout << "You won't be eaten!" << '\n';
        }else{
            cout << "Uh oh.." << '\n';
        }
        getline(cin, txt);
    }
    return 0;
}

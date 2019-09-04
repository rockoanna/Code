#include <iostream>
#include <fstream>
#include <map>

using namespace std;

static const map<char,char> pairs{{'A','A'},{'E','3'}, {'H','H'}, {'I','I'}, {'L','J'},{'J','L'},{'M','M'},
    {'O','O'},{'S','2'}, {'T','T'},{'U','U'},{'V','V'},{'W','W'},{'X','X'},
    {'Y','Y'}, {'Z','5'}, {'1','1'}, {'2','S'}, {'3','E'},{'5','Z'},{'8','8'}};

static const char NOT_FOUND ='\0';

inline char mirror(char x)
{
    auto res = pairs.find(x);
    if(res != pairs.end())
    {
        return (*res).second;
    }
    else
    {
        return NOT_FOUND;
    }
}



inline bool is_palindrom(string p)
{
    for(int i = 0; i < p.size() / 2; i++)
    {
        if(p[i] != p[p.size() - i - 1])
        {
            return false;
        }
    }

    return true;


}

inline bool is_mirror_string(string s)
{
    int len = s.size();
    for(int i = 0; i < len / 2; i++)
    {
        auto mrr = mirror(s[i]);

        if( mrr == NOT_FOUND)
        {
            return false;
        }

        if(mrr != s[len - i - 1])
        {
            return false;
        }
    }

    if(len % 2 == 1)
    {
        int mid = len /2 ;
        return (mirror(s[mid]) == s[mid] );
    }
    else
    {
        return true;
    }
}


int main()
{

    string s;

    while(getline(cin, s))
    {
        bool pal = is_palindrom(s);
        bool mrr = is_mirror_string(s);
        if(pal)
        {
            if(mrr)
            {
                cout << s << " -- is a mirrored palindrome." << '\n';
            }
            else
            {
                cout << s << " -- is a regular palindrome." << '\n';
            }

        }
        else
        {
            if(mrr)
            {
                cout << s << " -- is a mirrored string." << '\n';
            }
            else
            {
                cout << s << " -- is not a palindrome." << '\n';
            }
        }
        cout<<'\n';
    }

    return 0;
}

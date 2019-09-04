#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

bool comp(char &c1, char c2){
    char cu1 = tolower(c1);
    char cu2 = tolower(c2);
    if(cu1 == cu2){
        return c1 < c2;
    }else{
        return cu1 < cu2;
    }
}


int main()
{
    int n;
    cin >> n;
    //ofstream cout {"out.txt"};
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end(), comp);
        cout << s << endl;
        while(next_permutation(s.begin(), s.end(), comp))
        {
            cout << s << endl;
        }
    }
    return 0;
}

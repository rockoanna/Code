#include <map>
#include <iostream>

using namespace std;

bool is_ana(string &s1, string &s2){
    map<char, int> f;
    for(auto cc : s1){
        char c =cc.tolower();
        auto r = f.find(c);
        if(r == f.end()){
            f[c] = 1;
        }else{
            (*r).second += 1;
        }
    }
    for(auto cc : s2){
        char c =cc.tolower();
        auto r = f.find(c);
        if(r == f.end()){
            return false;
        }else{
            (*r).second -= 1;
            if((*r).second == 0){
                f.erase(r);
            }
        }
    }

    return f.empty();
}

int main()
{
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;

    cout << is_ana(s1, s2) << endl;
    return 0;
}

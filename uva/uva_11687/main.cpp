#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    while(s != "END"){
        string prev = s;
        string crt = to_string(s.size());
        int count_ = 1;
        while(crt != prev){
            prev = crt;
            crt = to_string(crt.size());
            count_ += 1;
        }
        cout << count_ << '\n';

        getline(cin, s);
    }
    return 0;
}

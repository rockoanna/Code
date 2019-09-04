#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int digit_sum(int n){
    int sum = 0;
    while(n != 0){
        sum += n % 10;
        n = n/10;
    }
    return sum;
}

int one_digit_sum(int n){
    while(n > 9){
        n = digit_sum(n);
    }
    return n;
}

int eval(string name){
    int res = 0;
    for(auto crt : name){
        if(crt >= 'a' && crt <= 'z'){
            res += crt - 'a' + 1;
        }else{
            if(crt >= 'A' && crt <= 'Z'){
                res += crt - 'A' + 1;
            }
        }
    }
    return res;
}

int main()
{
    string f;
    string s;
    while(getline(cin, f) && getline(cin, s)){
        int v1 = one_digit_sum(eval(f));
        int v2 = one_digit_sum(eval(s));
        cout.precision(2);
        cout.flags(cout.fixed);
        if(v1 <= v2){
            cout << 100*(v1/ (double) v2)<<" %" <<'\n';
        }else{
            cout << 100*(v2/ (double) v1)<<" %" << '\n';
        }
    }

    return 0;
}

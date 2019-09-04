#include <iostream>
#include<vector>

using namespace std;
vector<int>digits(int n)
{
    vector<int>res;
    if(n == 0 ){
        res. push_back(0);
    }

    int a =n;

    while(a !=0){
        res .push_back(a % 10);
        a = a / 10;
    }

    for(int i = 0;i<res.size() / 2; i++){
        int x =res[i];
        res[i] = res[res.size()-i-1];
        res[res.size()-i-1]=x;
    }

    return res;
}

int nr(vector<int>row)
{
    int b = 0;
    for(int i = 0;i<row.size();i++){
        b = b * 10 + row[i];
    }
    return b;
}

bool is_prime(int n)
{
    if(n % 2 == 0){
        return n == 2;
    }

    for(int i = 3; i*i < n; i+=2){
        if(n % i == 0){
            return false;
        }
    }
    return true;

}

int main()
{
    int a;
    cin >> a;

    int b;
    cin >> b;

    vector<int>dig_a = digits(a);
    vector<int>dig_b = digits(b);
    vector<int>all;
    all.push_back(a);
    all.push_back(b);

    for(auto da : dig_a){
        for(int i = 0; i < dig_b.size(); i++){
            int x = 0;
            for(int j = 0; j < dig_b.size(); j++){
                if(i != j){
                    x = x*10 + dig_b[j];
                }else{
                    x = x*10 + da;
                }
            }
            all.push_back(x);
        }
    }
    int greteast_prime = -1;
    int greteast_not_prime = -1;
    for(auto x: all){
        if(is_prime(x) ){
            if(x > greteast_prime){
                   greteast_prime = x;
             }
        }else{
            if(x > greteast_not_prime){
                   greteast_not_prime = x;
            }
        }

    }
    if(greteast_prime > 0){
        cout << greteast_prime;
    }else{
        cout << greteast_not_prime;
    }

    return 0;
}

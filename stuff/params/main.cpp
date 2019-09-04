#include <iostream>
#include <vector>
using namespace std;

void db(vector<int> &v){
    vector<int> res;
    for(int i=0;i<v.size();i++){
        v[i] = 2*v[i];
    }
}

void swap(int x, int y, int &sum, int &prod){
    sum = x+y;
    prod = x*y;
}

int reverse(int m){
    int res =0;
    int n =m;
    while(n != 0){
        res = res*10 + (n%10);
        n = n/10;
    }
    return res;
}

char toupper(char c){
    if (c >='a' && c <='z'){
        c-=32;
    }
}

int main()
{
    int x =3;
    int y=4;
    int s =0;
    int p =1000;
    swap(x,y,s,p);
    cout<<s <<" "<<p<<endl;
//    vector<int> v1;
//    for(int i=0;i<100000000;i++){
//        v1.push_back(i);
//    }
//
//
//    cout << v1[9999999] << endl;
    return 0;
}

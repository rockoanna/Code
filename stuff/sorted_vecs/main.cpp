#include <iostream>
#include <vector>
#include <set>

using namespace std;

int vec1()
{
    vector<int> v = {2,3,5,7,9};
    int val = 4;
    int pos = -1;

    for(int i=0;i< v.size();i++){
        if(v[i]>= val){
            pos = i;
            break;
        }
    }
    if(pos == -1){
        v.push_back(val);
    }else{
        v.push_back(-1);
        for(int i=v.size()-1;i >= pos;i-- ){
            v[i+1]=v[i];
        }
        v[pos] = val;
    }
    for(auto x:v){
        cout<<x<<",";
    }
    cout <<endl;
    return 0;
}

int vec2()
{
    vector<int> v = {2,3,5,7,9,9};
    int val = 4;
    auto pos = lower_bound(v.begin(),v.end(), val);
    v.insert(pos,val);
    for(auto x:v){
        cout<<x<<",";
    }
    cout <<endl;
    return 0;
}

int set1()
{
    multiset<int> v = {2,3,5,7,9,9};
    int val = 4;
    auto pos = lower_bound(v.begin(),v.end(), val);
    v.insert(pos,val);
    for(auto x:v){
        cout<<x<<",";
    }
    cout <<endl;
    return 0;
}


int main(){
    vec1();
    vec2();
    set1();
    return 0;
}

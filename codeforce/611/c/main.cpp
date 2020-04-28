#include <iostream>
#include <unordered_set>
#include <deque>
#include <sstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore();

    deque<int> give(n + 1);
    unordered_set<int> got;
    deque<int> left;


    string s;
    getline(cin, s);
    stringstream ss(s);
    int x;
    int k = 0;

    while(ss >> x)
    {
        k += 1;
        give[k] = x;
        got.insert(x);
    }

    for(int i = 1; i < n + 1; i++)
    {
        if(got.find(i) == got.end()){
            left.push_back(i);
        }
    }

    int prev = -1;

    for(int i = 1; i < n + 1; i++){
        if(give[i] == 0){
            int cnd = left.back();
            if(cnd != i){
                give[i] = cnd;
                left.pop_back();
                prev = i;
            }else{
                cnd = left.front();
                if(cnd != i){
                    give[i] = cnd;
                    prev = i;
                }else{
                    int prev_v = give[prev];
                    give[prev] = cnd;
                    give[i] = prev_v;
                }
                left.pop_front();
            }
        }
    }

    stringstream res;
    for(int i = 1; i < n + 1; i++){
        res<<give[i];
        if(i != n){
            res<<" ";
        }
    }
    cout << res.str() << endl;

    return 0;
}

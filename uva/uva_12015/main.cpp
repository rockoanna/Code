#include <vector>
#include <map>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int ni = 0; ni < n; ni++){
        vector<string>names(10);
        vector<int> ranks(10);
        int max_r = -1;

        for(int i = 0; i < 10; i++){
            cin >> names[i];
            cin >> ranks[i];
            if(ranks[i] > max_r){
                max_r = ranks[i];
            }
        }
        cout << "Case #" << ni + 1 << ":" << endl;
        for(int i = 0; i < 10; i++){
            if(ranks[i] == max_r){
                cout << names[i] << endl;
            }
        }
    }


    return 0;
}



int main2()
{
    int n;
    cin >> n;
    for(int ni = 0; ni < n; ni++){
        multimap<int,string> data;

        for(int i = 0; i < 10; i++){
            string  name;
            int hits;
            cin >> name;
            cin >> hits;
            data.insert(pair<int,string>(hits,name));
        }
        cout <<endl<< "Case #" << ni + 1 << ":" << endl;
        auto best = (*data.rbegin()).first;
        for(auto it=data.find(best);it !=data.end();it++){
            if((*it).first == best){
                cout<<(*it).second<<endl;
            }else{
                break;
            }
        }
    }

    return 0;
}

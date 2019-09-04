#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    int m;
    int c;
    cin >> n;
    cin >> m;
    cin >> c;

    int nr = 1;

     while(n != 0){

        int no = 0;
        int max_ = 0;
        vector <int> count_(n + 1);

        vector <int> device(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> device[i];
        }

        vector <int> power (m);
        for(int i = 0; i < m; i++){
            cin >> power[i];
        }

        for(int i = 0; i < m; i++){
            count_[power[i]] += 1;
            if(count_[power[i]] % 2 == 0){
                no -= device[power[i]];
            }else{
                no += device[power[i]];
                if(no > max_){
                    max_ = no;
                }
            }

            if(no > c){
                break;
            }
        }

        if(no > c){
            cout << "Sequence " << nr << endl;
            cout << "Fuse was blown." << endl;
        }else{
            cout << "Sequence " << nr << endl;
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << max_ << " amperes." << endl;
        }



        nr += 1;
        cout << endl;
        cin >> n;
        cin >> m;
        cin >> c;
     }


    return 0;
}

#include <vector>
#include <bitset>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;


int main()
{
    int case_ = 0;
    string input;
    cin >> input;
    while(!cin.eof() && input.size() > 0){
        case_+=1;
        vector<int> v(input.size());
        if(input[0] == '1'){
                v[0] = 1;
        }

        for(int x=1;x<input.size();x++){
            if(input[x] == '1'){
                v[x] = 1 + v[x-1];
            }else{
                v[x] = v[x-1];
            }
        }

        int n;
        cin >> n;
        cout << "Case " << case_ << ":" << '\n';

        for(int x = 0; x < n; x++){
            int i;
            int j;
            cin >> i >> j;
            int f = min(i,j);
            int l = max(i,j);
            bool ok = false;

            if(f == 0){
                ok = (v[l] == l + 1 || v[l] == 0);
            }else{
                ok = (v[l] - v[f-1] == l - f + 1 || v[l] - v[f-1] == 0);
            }

            if(ok){
                cout << "Yes" << '\n';
            }else{
                cout << "No" << '\n';
            }
        }
        cin >> input;
    }

    return 0;
}




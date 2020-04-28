#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    for(int x = 0; x < n; x++){
        string s;
        cin >> s;
        bool ok = true;
        for(int i = 0; i < s.size(); i++){
            bool a = true;
            bool b = true;
            bool c = true;

            if(s[i] == '?'){
                if(i > 0){
                    if(s[i - 1] == 'a'){
                        a = false;
                    }
                    if(s[i - 1] == 'b'){
                        b = false;
                    }
                    if(s[i - 1] == 'c'){
                        c = false;
                    }
                }

                if(i < s.size() - 1){
                    if(s[i + 1] == 'a'){
                        a = false;
                    }
                    if(s[i + 1] == 'b'){
                        b = false;
                    }
                    if(s[i + 1] == 'c'){
                        c = false;
                    }
                }

                if(a){
                    s[i] = 'a';
                }else{
                    if(b){
                        s[i] = 'b';
                    }else{
                        s[i] = 'c';
                    }
                }
            }
            else{
                if(i < s.size() - 1){
                    if(s[i] == s[i + 1]){
                        ok = false;
                        break;
                    }
                }
            }
        }

        if(ok){
            cout << s << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}

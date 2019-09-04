#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i =0; i < n; i++){
        unsigned int nr1;
        cin >> nr1;

        unsigned int nr2;
        cin >> nr2;

        if(nr1 < nr2){
            cout  << "<" <<endl;
        }else{
            if(nr1 > nr2){
                cout << ">" <<endl;
            }else{
                cout << "=" <<endl;
            }
        }
    }

    return 0;
}

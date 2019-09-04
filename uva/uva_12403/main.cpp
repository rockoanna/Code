#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;

    for(int i = 0; i < n; i++){
        string in;
        cin >> in;
        if(in[0] == 'r'){
            cout << sum << endl;
        }else{
            int nr;
            cin>>nr;
            sum += nr;
        }
    }

    return 0;
}

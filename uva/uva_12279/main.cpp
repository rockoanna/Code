#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int case_nr = 1;

    while(n != 0){
        int count_0 = 0;
        int crt;
        for(int i = 0; i < n; i++){
            cin >> crt;
            if(crt == 0){
                count_0 +=1;
            }
        }
        cout << "Case " << case_nr << ": " << n - 2*count_0 << endl;
        cin >> n;
        case_nr += 1;
    }


    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        int nr_calls;
        cin >> nr_calls;
        int count_j = 0;
        int count_m = 0;

        for(int j = 0; j < nr_calls; j++){
            int c;
            cin >> c;
            count_m += ((c / 30) + 1)*10;
            count_j += ((c / 60) + 1)*15;
        }

        if(count_j < count_m){
            cout << "Case " << i << ": " << "Juice " << count_j << endl;
        }else{
            if(count_j > count_m){
                cout << "Case " << i << ": " << "Mile " << count_m << endl;
            }else{
                cout << "Case " << i << ": " << "Mile Juice " << count_m << endl;
            }
        }


    }


    return 0;
}

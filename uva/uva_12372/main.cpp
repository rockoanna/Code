#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int case_nr = 1;

    for(int i = 0; i < n; i++){
        int l;
        int w;
        int h;
        cin >> l;
        cin >> w;
        cin >> h;
        if(l > 20 || w > 20 || h > 20){
            cout << "Case " << case_nr << ": " << "bad" <<endl;
        }else{
            cout << "Case " << case_nr << ": " << "good" <<endl;
        }
        case_nr += 1;
    }


    return 0;
}

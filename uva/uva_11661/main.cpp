#include <string>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    while(n != 0)
    {

        string highway;
        getline(cin, highway);
        int last_store_pos = -1;
        int last_type = 0;
        int min_delta = numeric_limits<int>::max();
        for(int i = 0; i< n; i++)
        {
            if(highway[i] == 'Z')
            {
                min_delta = 0;
                break;
            }

            if(highway[i] == '.')
            {
                continue;
            }

            if(highway[i] == 'R')
            {
                if(last_type == -1){
                    int candidate = i - last_store_pos;
                    min_delta = min(candidate, min_delta);
                }
                last_store_pos = i;
                last_type = 1;
                continue;
            }


            if(highway[i] == 'D')
            {
                if(last_type == 1){
                    int candidate = i - last_store_pos;
                    min_delta = min(candidate, min_delta);
                }
                last_store_pos = i;
                last_type = -1;
            }




        }
        cout << min_delta << '\n';
        cin >> n;
        cin.ignore();
    }


    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    for(int i = 0; i < 1000000; i++){
        n += i;
    }

    cout << n << endl;



    return 0;
}

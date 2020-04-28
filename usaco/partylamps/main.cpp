#include <iostream>
#include <bitset>

using namespace std;

int main()

{
    for(int8_t i = 0; i < 16; i++){
        auto a = std::bitset<8>(i);
        cout << a<< endl;
        cout << a[2]<< endl;
        cout << a[4]<< endl;
    }



    return 0;
}

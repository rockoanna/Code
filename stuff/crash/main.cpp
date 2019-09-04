#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    long total =0;
    for(long i=0; i <10000000000;i++){
        total+=i;
    }
    cout<<total;
    return 0;
}

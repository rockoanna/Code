#include <iostream>

using namespace std;


int digits_sum(int n)
{
    int count_ = 0;
    while(n != 0){
        count_ += n % 10;
        n = n / 10;
    }
    return count_;
}


int main()
{
    int n;
    cin >> n;

    while(n != 0){
        while(n > 9){
            n = digits_sum(n);
        }
        cout << n << endl;
        cin >> n;
    }


    return 0;
}

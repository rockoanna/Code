#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n)
{
    bool res = true;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            res = false;
            break;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 2; i < n + 1; i++)
    {
        if(is_prime(i) == true){
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}

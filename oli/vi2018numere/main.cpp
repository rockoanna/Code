#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int dig_count(int n){
    int _count =0;
    while(n != 0){
        _count+=1;
        n/=10;
    }
    return _count;
}

int pal_count(int digits){
    if(digits == 1 ){
        return 9;
    }
    if(digits % 2 == 1){
        return pal_count(digits-1) * 10;
    }else{
        return pal_count(digits-1);
    }

}

bool is_palindrome(int n)
{
    vector<int> digits;
    int x = 0;
    int n_c = n;

    while(n_c != 0)
    {
        digits.push_back(n_c % 10);
        n_c = n_c / 10;
    }

    for(auto d : digits)
    {
        x = x * 10 + d;
    }

    if(x == n)
    {
        return true;
    }

    return false;
}

int req3_1(int digits){
    int crt_number = pow(10,digits-1) + 1;
    int stop = pow(10,digits) ;
    int res = 0;
    while(crt_number < stop){
        if(crt_number % 10 == 0){
            crt_number+=1;
        }else{
            if(!is_palindrome(crt_number)){
                res+=2;
                crt_number+=1;
            }else{
                res+=1;
                crt_number+=1;
            }
        }
    }
    return res;

}

int main()
{
    int n;
    cin >> n;

    if(n == 1)
    {
        int x;
        cin >> x;

        cout << (x - 1) * 10 << '\n';
    }
    else
    {
        if(n == 2)
        {
            int x;
            cin >> x;

            int x1 = x / 10;
            if(x1 % 10 == 0)
            {
                cout << 0 << " ";
            }
            else
            {
                if(is_palindrome(x1) == false)
                {
                    cout << 2 << " ";
                }
                else
                {
                    cout << 1 << " ";
                }
            }

            int x2 = x / 100;
            if(x2 % 10 == 0)
            {
                cout << 0 << " ";
            }
            else
            {
                if(is_palindrome(x2) == false)
                {
                    cout << 2 << " ";
                }
                else
                {
                    cout << 1 << " ";
                }
            }

            int x3 = x / 1000;
            if(x3 % 10 == 0)
            {
                cout << 0 << '\n';
            }
            else
            {
                if(is_palindrome(x3) == false)
                {
                    cout << 2 << '\n';
                }
                else
                {
                    cout << 1 << '\n';
                }
            }

        }
        else
        {
            if(n == 3)
            {
                int x;
                cin >> x;

                cout << pal_count(x) << endl;


            }
        }
    }

    return 0;
}

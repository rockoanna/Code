#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    int x = max(a,b);
    int y = min(a,b);
    while(y != 0)
    {
        int tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

vector<int> div(int a)
{
    vector<int> v;
    for(int i = 1; i * i <= a; i++)
    {
        if(a % i == 0)
        {
            v.push_back(i);
            if(a / i != i)
            {
                v.push_back(a / i);
            }
        }
    }

    return v;
}

auto prime_fact(uint64_t a)
{
    vector<uint64_t>  res;
    if(a <= 2)
    {
        res.push_back(a);
        return res;
    }

    auto n = a;

    while(n % 2 == 0)
    {
        res.push_back(2);
        n = n / 2;
    }

    for(int i = 3; i * i <= n; i+=2)
    {
        while(n % i == 0)
        {
            res.push_back(i);
            n = n/i;
        }
    }

    if(n >= 3)
    {
        res.push_back(n);
    }

    return res;
}

vector<bool> primes(uint64_t n)
{
    vector<bool> v(n, true);
    v[0] = false;
    v[1] = false;

    for(int i = 2; i < n; i++)
    {
        if(v[i] == true)
        {
            for(auto j=i*i; j<n; j+=i)
            {
                v[j] = false;
            }
        }
    }
    return v;
}

bool is_prime(int n)
{
    if(n <= 1)
    {
        return false;
    }

    if(n <= 3)
    {
        return true;
    }

    if(n % 2 == 0)
    {
        return false;
    }

    if(n % 3 == 0)
    {
        return false;
    }

    for(int i = 5; i * i <= n; i+=2)
    {
        if(n % i == 0)
        {
            return false;
        }
    }

    return true;
}

#define tp typedef
tp uint64_t u64;
tp int64_t i64;

bool bsearch(vector<u64>&v, int n)
{
    i64 low = 0;
    i64 high = v.size() - 1;
    bool found = false;
    while(low <= high)
    {
        i64 mid = (low + high) / 2;
        if(v[mid] == n)
        {
            return true;
        }
        if(v[mid] > n)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}

u64 bpow(u64 a, u64 b, u64 m)
{
    if(b == 0)
    {
        return 1;
    }

    u64 res = 1;
    if(b % 2 == 0)
    {
        res = bpow(a, b / 2, m) % m;
        res = (res * res) % m;
    }
    else
    {
        res = bpow(a, (b - 1) / 2, m) % m;
        res = (res * res) % m;
        res = (res * a) % m;
    }

    return res;
}

int main()
{
//    vector<u64> v;
//    for(int i = 0; i < 100; i++)
//    {
//        v.push_back(rand()%1000);
//    }
//    sort(v.begin(), v.end());
//
//    for(int i = 0; i < 100; i++)
//    {
//        cout << v[i] << endl;
//    }
//
//    int n;
//    cin >> n;
//    while(n != 0)
//    {
//        bool found = binary_search(v.begin(), v.end(), n);
//        if(found)
//        {
//            cout << "FOUND :)" <<endl;
//        }
//        else
//        {
//            cout << "NOT FOUND :(" <<endl;
//        }
//
//        bool xfound = bsearch(v, n);
//        if(xfound)
//        {
//            cout << "XFOUND :)" <<endl;
//        }
//        else
//        {
//            cout << "NOT XFOUND :(" <<endl;
//        }
//
//        cin >> n;
//    }

    int n;
    cin >> n;
    int e;
    cin >> e;

    cout << bpow(n, e, 10000001) << endl;
    cout << pow(n, e) << endl;
    return 0;
}

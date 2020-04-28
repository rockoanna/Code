#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool b_search(vector<int>&v, int el)
{
    int low = 0;
    int high = v.size() - 1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if (v[mid] == el)
        {
            return true;
        }
        if (v[mid] > el)
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

int main()
{
    vector<int>v = {3, 5, 8, 10, 66, 88};
    cout << b_search(v, 3) << endl;
    cout << b_search(v, 70) << endl;
    cout << b_search(v, 66) << endl;
    cout << b_search(v, 88) << endl;
    cout << b_search(v, 4) << endl;
    cout << b_search(v, 100) << endl;
    cout << b_search(v, 0) << endl;

    cout << binary_search(v.begin(),v.end(), 3) << endl;
    cout << binary_search(v.begin(),v.end(), 70) << endl;
    cout << binary_search(v.begin(),v.end(), 66) << endl;
    cout << binary_search(v.begin(),v.end(), 88) << endl;
    cout << binary_search(v.begin(),v.end(), 4) << endl;
    cout << binary_search(v.begin(),v.end(), 100) << endl;
    cout << binary_search(v.begin(),v.end(), 0) << endl;
    return 0;
}

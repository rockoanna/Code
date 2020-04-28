#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<int> intersection(set<int>& s1, set<int>& s2)
{
    set<int> res;

    for(auto e : s1)
    {
        auto rf = s2.find(e);
        if(rf != s2.end())
        {
            res.insert(e);
        }
    }

    return res;
}

set<int> difference(set<int>& s1, set<int>& s2)
{
    set<int> res;

    for(auto e : s1)
    {

        if(s2.count(e) == 0)
        {
            res.insert(e);
        }
    }

    return res;
}

int main()
{
    set<int> s1 = {1, 44444, 5, 19, 99, 12, 1000};
    set<int> s2 = {1, 13, 100, 99, 0};
    set<int> res = difference(s1, s2);

    for(auto el : res)
    {
        cout << el << " ";
    }

    cout << endl;


    return 0;
}


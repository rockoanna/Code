/*
ID: oanna.p1
TASK: beads
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef int16_t i16;

inline int mod(a,b){
    return ((a %b)+b)%b;
}


int main()
{
    //ifstream cin {"beads.in"};
    //ofstream cout {"beads.out"};

    i16 n;
    cin >> n;

    string s;
    cin >> s;

    i16 max_ = 0;

    bool has_r =false;
    bool has_b =false;
    for(auto c:s)
    {
        if(c=='r')
        {
            has_r=true;
        }
        else if(c=='b')
        {
            has_b=true;
        }

    }

    if(!has_b || !has_r)
    {
        cout<<n<<endl;
        return 0;
    }

    for(i16 i = 0;  i < n; i++)
    {
        //cout<<"********************"<<i<<endl;
        i16 count_ = 0;

        i16 left = i;
        char col = s[left];
        for(int x=0; x<n; x++)
        {
            i16 idx =left % n;
            if(s[idx] == col || s[idx] =='w' || col=='w')
            {
                count_ += 1;
                if(col =='w')
                {
                    col = s[idx];
                }
                left += 1;
            }
            else
            {
                //cout<< "stop at index "<<idx<<" "<<s[idx]<<endl;
                break;
            }

        }

        //cout<<count_<<endl;
        i16 last = ((i - 1) % n + n) %n;
        i16 right = last;
        col = s[right];
        for(int x=0; x<=n-count_; x++)
        {
            i16 idx =(right % n +n) %n;
            if(s[idx] == col || s[idx] == 'w'|| col=='w')
            {
                count_ += 1;
                if(col == 'w')
                {
                    col = s[idx];
                }
                right -=1;
            }
            else
            {
                //cout<< "stop at index "<<idx<<" "<<s[idx]<<endl;
                break;
            }
        }
        //cout<<count_<<endl;
        max_ = max(max_, count_);

    }

    cout << max_ << endl;

    return 0;
}

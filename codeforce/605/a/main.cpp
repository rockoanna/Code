#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int x =0 ; x < n; x++)
    {
        vector<int> bff(3);
        cin >> bff[0]>> bff[1]>> bff[2];


        int res  =-1;
        for(int x1=-1; x1<2; x1++)
        {
            for(int x2=-1; x2<2; x2++)
            {
                for(int x3=-1; x3<2; x3++)
                {
                    int val=abs(bff[0]+x1 -bff[1]-x2) +abs(bff[1]+x2 -bff[2]-x3) + abs(bff[0]+ x1 -bff[2]-x3);
                    if(res < 0 ){
                        res =val;
                    }else{
                        res = min(res,val);
                    }
                }
            }
        }
        cout << res << endl;

    }


    return 0;
}

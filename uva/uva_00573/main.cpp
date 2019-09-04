#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int h;
    cin >> h;
    int u;
    cin >> u;
    int d;
    cin >> d;
    int f;
    cin >> f;



    while(h != 0)
    {
        double fatigue = (f / 100.0) * u;
        int day = 0;
        double crt_step = u;
        double count_ = 0;

        while(true)
        {
            day +=1;
            count_+=max(crt_step,0.0);
            if(count_ > h)
            {
                cout << "success on day " << day << endl;
                break;
            }
            count_ -= d;
            if(count_ < 0)
            {
                cout << "failure on day " << day << endl;
                break;
            }
            crt_step -= fatigue;
        }



        cin >> h;
        cin >> u;
        cin >> d;
        cin >> f;
    }
    return 0;
}

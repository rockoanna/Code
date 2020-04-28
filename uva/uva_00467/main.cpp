#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

struct lights
{
    string color;
    int seconds;
};

int main()
{
    // ofstream cout("out.txt");
    int tn = 0;
    string s;
    while(getline(cin , s))
    {
        tn += 1;
        vector<int> signals;
        stringstream s2(s);

        int n;
        while(s2 >> n)
        {
            signals.push_back(n);
        }

        int len = signals.size();
        vector<lights> time(len);
        for(int i = 0; i < len; i++)
        {
            time[i].color = "GREEN";
            time[i].seconds = 0;
        }

        int crt = 1;
        bool time_out = false;

        while(true)
        {
            int count_ = 0;
            bool ok = false;
            for(int i = 0; i < len; i++)
            {
                ok = ok || time[i].seconds > 0;

                if(time[i].color == "GREEN")
                {
                    if(crt - time[i].seconds == signals[i] - 5)
                    {
                        time[i].color = "YELLOW";
                        time[i].seconds = crt;
                    }
                    else
                    {
                        count_ += 1;
                    }
                }
                else
                {
                    if(time[i].color == "YELLOW")
                    {
                        if(crt - time[i].seconds == 5){
                            time[i].color = "RED";
                            time[i].seconds = crt;
                        }
                    }else{
                        if(crt - time[i].seconds == signals[i]){
                            time[i].color = "GREEN";
                            time[i].seconds = crt;
                            count_ += 1;
                        }
                    }
                }
            }

            if(count_ == len && ok){
                break;
            }

            if(crt == 3600){
                time_out = true;
                break;
            }

            crt += 1;

        }

        if(!time_out){
            cout << "Set " << tn << " synchs again at " << crt / 60 << " minute(s) and " <<  crt  % 60 << " second(s) after all turning green." << endl;
        }else{
            cout << "Set " << tn << " is unable to synch after one hour." << endl;
        }


    }

    return 0;
}

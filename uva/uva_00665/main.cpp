#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    cin.ignore();

    for(int x = 0; x < n; x++)
    {

        int nr_coins;
        cin >> nr_coins;

        int balance;
        cin >> balance;

        vector<int> false_coin(nr_coins + 1);
        false_coin[0] = 0;
        vector<vector<int>> unbalanced;

        for(int i = 0; i < balance; i++)
        {
            int n1;
            cin >> n1;

            vector<int> coins(n1 * 2);

            for(int j = 0; j < n1*2; j++)
            {
                cin >> coins[j];
            }
            string s;
            cin >> s;
            if(s == "=")
            {
                for(int j = 0; j < n1 * 2; j++)
                {
                    false_coin[coins[j]] = 1;

                }
            }
            else
            {
                unbalanced.push_back(coins);
            }
        }

        bool found = false;
        for(auto ub :unbalanced)
        {
            bool first_arm_ok = true;
            for(int i=0; i<ub.size()/2; i++)
            {
                if(false_coin[ub[i]] != 1)
                {
                    first_arm_ok  = false;
                    break;
                }
            }
            bool sec_arm_ok = true;
            for(int i=ub.size()/2; i<ub.size(); i++)
            {
                if(false_coin[ub[i]] != 1)
                {
                    sec_arm_ok  = false;
                    break;
                }
            }
            if(first_arm_ok && !sec_arm_ok)
            {
                int wrongs =0;
                int last_wrong =-1;
                for(int i=ub.size()/2; i<ub.size(); i++)
                {
                    if(false_coin[ub[i]] != 1)
                    {
                        wrongs +=1;
                        last_wrong =i;
                    }
                }
                if(wrongs ==1)
                {
                    cout << ub[last_wrong] << endl;
                    found = true;
                    break;
                }
            }
            if(!first_arm_ok && sec_arm_ok)
            {
                int wrongs =0;
                int last_wrong =-1;
                for(int i=0; i<ub.size()/2; i++)
                {
                    if(false_coin[ub[i]] != 1)
                    {
                        wrongs +=1;
                        last_wrong =i;
                    }
                }
                if(wrongs ==1)
                {
                    cout << last_wrong << endl;
                    found = true;
                    break;
                }
            }
        }

        if(!found)
        {
            cout << 0 << endl;
        }

        if(x + 1 != n)
        {
            cout << endl;
        }

        cin.ignore();
    }




    return 0;
}

#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<char, char> dial {{'A', '2'}, {'B', '2'}, {'C', '2'}, {'D', '3'}, {'E', '3'}, {'F', '3'}, {'G', '4'}, {'H', '4'}, {'I', '4'}, {'J', '5'}, {'K', '5'}, {'L', '5'},
                    {'M', '6'}, {'N', '6'}, {'O', '6'}, {'P', '7'}, {'R', '7'}, {'S', '7'}, {'T', '8'}, {'U', '8'}, {'V', '8'}, {'W', '9'}, {'X', '9'}, {'Y', '9'}};

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    for(int x = 0; x < n; x++)
    {
        int nr;
        cin >> nr;


        map<string, int> ph_b;

        for(int i = 0; i < nr; i++)
        {
            string phone;
            cin >> phone;
            string clean_phone;
            for(int j = 0; j < phone.size(); j++)
            {
                if(phone[j] == '-')
                {
                    continue;
                }

                if(phone[j] < 'Z' && phone[j] >= 'A'  )
                {
                    clean_phone += (dial[phone[j]]);
                }
                else
                {
                    clean_phone.push_back(phone[j]);
                }
                if(clean_phone.size() == 3)
                {
                    clean_phone += ('-');
                }

            }
            ph_b[clean_phone]+=1;
        }

        int printed = 0;
        for(auto kv : ph_b)
        {
            if(kv.second > 1)
            {
                cout<<kv.first<<" "<<kv.second<<endl;
                printed +=1;
            }
        }
        if (printed ==0)
        {
            cout<<"No duplicates."<<endl;
        }
    }

    return 0;
}

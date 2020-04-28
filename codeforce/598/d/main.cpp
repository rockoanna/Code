#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        long len;
        cin >> len;
        cin.ignore();

        long m;
        cin >> m;
        cin. ignore();

        string s;
        getline(cin, s);

        long start = 0;
        while(start < len && s[start] == '0')
        {
            start += 1;
        }

        long pos = start;
        for(long j = start + 1; j < len; j++)
        {
//            if(j >= s.size()){
//                cout <<"BUGGGG "<<j<<" "<<s.size() << " " << len << endl;
//            }
            if(s[j] == '0')
            {
                long x = min(j - pos, m);
                s[j - x] = '0';
                s[j] = '1';
                m -= x;
                pos = j - x + 1;

                if(m == 0)
                {
                    break;
                }

            }
        }

        cout << s << endl;
    }


    return 0;
}

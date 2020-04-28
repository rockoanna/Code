#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for(int x = 0; x < n; x++)
    {
        if(x > 0){
            cout << endl;
        }
        string s;
        getline(cin, s);//skip blank line
        getline(cin, s);
        int len =0;
        for(auto ch :s)
        {
            if(!isspace(ch))
            {
                len++;
            }
        }

        vector<string> v(len + 1);
        for(int i = 0; i < len; i++)
        {
            cin >> v[i + 1];
        }

        stringstream ss(s);
        int val;
        while(ss >> val)
        {
            cout << v[val] << endl;
        }
//        int nr = 0;
//        vector<int> numbers(len);
//        for(int i = 0; i < s.size(); i++)
//        {
//            if(s[i] != ' ')
//            {
//                if(s[i - 1] == ' ')
//                {
//                    nr = s[i] - '0';
//                }
//                else
//                {
//                    nr = nr * 10 + (s[i] - '0');
//                }
//
//                if(s[i + 1] == ' ')
//                {
//                    numbers.push_back(nr);
//                    nr = 0;
//                }
//            }
//        }
//
//        for(int i = 1; i < len + 1; i++){
//            cout << v[numbers[i]] << endl;;
//        }
    }


    return 0;
}

#include <array>
#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

typedef unsigned char byte;

unordered_map <int, byte> h {{0, '0'},{1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}, {10, 'A'}, {11, 'B'}, {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}};

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    for(int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        array<int, 100> mem;
        mem.fill(0);
        int pos = 0;

        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] == '+')
            {
                if(mem[pos] == 255)
                {
                    mem[pos] = 0;
                }
                else
                {
                    mem[pos] += 1;
                }
                continue;
            }

            if(s[j] == '-')
            {
                if(mem[pos] == 0)
                {
                    mem[pos] = 255;
                }
                else
                {
                    mem[pos] -= 1;
                }
                continue;
            }

            if(s[j] == '>')
            {
                if(pos == 99)
                {
                    pos = 0;
                }
                else
                {
                    pos += 1;
                }
                continue;
            }

            if(s[j] == '<')
            {
                if(pos == 0)
                {
                    pos = 99;
                }
                else
                {
                    pos -= 1;
                }
                continue;
            }


        }

        cout << "Case " << i << ": ";
        for(int j = 0; j < 100; j++)
        {
            cout << (h[mem[j] / 16])<< (h[mem[j] % 16]);
            if(j < 99){
                cout << " ";
            }

        }

            cout << endl;


    }

    return 0;

}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int set_nr = 0;

    while(n != 0)
    {
        set_nr += 1;

        vector<int> stacks(n);
        int blocks = 0;
        int moves = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> stacks[i];
            blocks += stacks[i];
        }

        blocks = blocks / n;

        for(int i = 0; i < n; i++)
        {
            if(stacks[i] > blocks)
            {
                moves += stacks[i] - blocks;
            }
        }

        cout << "Set #" << set_nr << endl;
        cout << "The minimum number of moves is " << moves << "." << endl;

        cin >> n;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> song= {"Happy","birthday", "to","you", "Happy", "birthday", "to", "you","Happy", "birthday","to","Rujia","Happy","birthday","to", "you"};
    int len = song.size();
    int n;
    cin >> n;
    vector<string> people(n);

    for(int i = 0; i < n; i++)
    {
        cin >> people[i];
    }

    int s = 0;
    bool keep_sing = true;
    while(keep_sing)
    {
        for(int i = 0; i < n; i++)
        {
            if(s % len == 0 && s >= n)
            {

                keep_sing = false;
                break;
            }
            cout << people[i] << ": " << song[s % len] << endl;
            s += 1;
        }
    }
    return 0;
}

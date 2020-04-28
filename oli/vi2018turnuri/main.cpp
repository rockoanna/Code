#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct blocks
{
    int length;
    string color;
};

bool operator < (blocks& b1, blocks& b2)
{
    if(b1.length < b2.length)
    {
        return true;
    }

    return b1.color < b2.color;
}

int main()
{
    int n;
    cin >> n;

    int nr_c;
    cin >> nr_c;

    vector<blocks> towers(nr_c);

    for(int i = 0; i < nr_c; i++)
    {
        cin >> towers[i].length;
        cin >> towers[i].color;

    }

    if(n == 1)
    {
        string s = towers[0].color;
        int crt_l = towers[0].length;

        vector<int> v;
        int tower_h = crt_l;
        int t = 0;

        for(int i = 1; i < nr_c; i++)
        {
            string c = towers[i].color;
            int l = towers[i].length;

            if(c != s)
            {
                if(l < crt_l)
                {
                    tower_h += l;
                    s = c;

                }
                else
                {
                    v.push_back(tower_h);
                    tower_h = l;
                    s = c;
                    t += 1;
                }
            }
            else
            {
                v.push_back(tower_h);
                tower_h = l;
                s = c;
                t += 1;
            }

            crt_l = towers[i].length;
        }

        v.push_back(tower_h);
        t += 1;

        int max_ = -1;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] > max_)
            {
                max_ = v[i];
            }
        }

        cout << t << " " << max_ << endl;
    }
    else
    {
        sort(towers.begin(), towers.end());
        reverse(towers.begin(), towers.end());
        string crt_color = towers[0].color;
        int l = towers[0].length;
        int count_ = 1;

        for(int i = 1; i < nr_c; i++)
        {
            if(towers[i].color != crt_color)
            {
                if(towers[i].length < l)
                {
                    l = towers[i].length;
                    crt_color = towers[i].color;
                    count_ += 1;
                }
            }
        }

        cout << count_ << endl;
    }

    return 0;
}

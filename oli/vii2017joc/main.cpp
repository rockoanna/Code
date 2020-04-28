#include <iostream>
#include <vector>

using namespace std;

int winner(vector<vector<int>>& m)
{
    int won = 0;

    for(int i = 0; i < m.size(); i++)
    {
        if(won != 0)
        {
            break;
        }
        won = m[i][0];
        if(won  == 0)
        {
            continue;
        }
        for(int j = 1; j < m[i].size(); j++)
        {
            if(m[i][j] != m[i][0])
            {
                won = 0;
                break;
            }

        }
    }
    if(won != 0)
    {
        return won;
    }

    for(int i = 0; i < m[0].size(); i++)
    {
        if(won != 0)
        {
            break;
        }

        won = m[0][i];

        if(won  == 0)
        {
            continue;
        }

        for(int j = 1; j < m[i].size(); j++)
        {
            if(m[j][i] != m[0][i])
            {
                won = 0;
                break;
            }

        }
    }

    return won;
}


void print_matrix(vector<vector<int>>& m)
{
    for(auto v: m)
    {
        for(auto x:v)
        {
            cout << x <<  " ";
        }
        cout << endl;
    }
}


int main()
{
    int n;
    cin >> n;

    int l;
    cin >> l;
    int rounds;
    cin >> rounds;

    int g_count = 0;
    int b_count = 0;

    int max_ = 0;

    for(int r = 0; r < rounds; r++)
    {
        vector<vector<int>> m;
        m.reserve(l);
        for(int i = 0; i < l; i++)
        {
            m.push_back(vector<int>(l));
        }

        for(int x = 0; x < l*l; x++)
        {
            int pos;
            cin >> pos;

            int i = (pos-1) / l;
            int j = (pos-1) % l;

            m[i][j] = x % 2 == 0 ? 1 :-1;

            if(n == 2)
            {
                if(winner(m) != 0)
                {
                    if(x + 1 > max_)
                    {
                        max_ = x + 1;
                    }
                    break;
                }
            }
            else
            {

                int won = winner(m);
//                if(won != 0)
//                {
//                    print_matrix(m);
//                    cout << "won " << won << endl;
//                    break;
//                }

                if(won != 0)
                {
                    if(won == 1)
                    {
                        if(r % 2 == 0)
                        {
                            //fata
                            g_count += 1;
                        }
                        else
                        {
                            //baiat
                            b_count += 1;
                        }
                    }
                    else
                    {
                        if(won == -1)
                        {
                            if(r % 2 == 1)
                            {
                                //fata
                                g_count += 1;
                            }
                            else
                            {
                                //baiat
                                b_count += 1;
                            }
                        }

                    }

                    break;
                }
            }
        }
    }

    if(n == 1)
    {
        cout << g_count << " " << b_count << endl;
    }
    else
    {
        cout << max_ << endl;
    }
    return 0;
}

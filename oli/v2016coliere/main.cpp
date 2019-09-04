#include <fstream>
#include <deque>
#include <vector>

using namespace std;

deque<int> number_to_digits(int n)
{
    deque<int> res;
    do
    {
        res.push_front(n % 10);
        n = n / 10;
    }
    while(n != 0);
    return res;
}

int bead_no(int n)
{
    deque<int> nr = number_to_digits(n);

    int max_ = 0;
    int max_pos = 0;

    int min_ = 10000;
    int min_pos = 0;

    for(uint32_t i = 0; i < nr.size(); i++)
    {

        if(nr[i] > max_)
        {
            max_ = nr[i];
            max_pos = i;
        }

        if(nr[i] < min_)
        {
            min_ = nr[i];
            min_pos = i;
        }
    }

    if(min_pos > max_pos)
    {
        return max_*10 + min_;
    }
    else
    {
        return min_*10 + max_;
    }

}

int bead_kind(int n)
{
    if(n / 10 < n % 10)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int solve_one(vector<int> beads)
{

    int res = 0;
    for(int i = 0; i < beads.size(); i++)
    {
        if(bead_kind(bead_no(beads[i])) == 1)
        {
            res += 1;
        }
    }
    return res;
}

int solve_two(vector<int> beads)
{
    int count_ = 0;
    vector<int> bead_k;

    for(int i = 0; i < beads.size(); i++)
    {
        bead_k.push_back(bead_kind(bead_no(beads[i])));
    }

    for(int i = 0; i < bead_k.size(); i++)
    {
        if(i == 0 || bead_k[i] != bead_k[i-1])
        {
            count_ += 1;
        }

    }

    if(count_ % 2 == 0)
    {
        return count_;
    }
    else
    {
        return count_ - 1;
    }
}

int main()
{

    ifstream fin("colier.in");
    ofstream fout("colier.out");
    int req;
    fin >> req;

    if(req == 1)
    {
        int no;
        fin >> no;

        vector<int>res(no);
        for(int i = 0; i < res.size(); i++)
        {
            fin >> res[i];
        }
        fout << solve_one(res);
    }
    else
    {
        int nr;
        fin >> nr;

        vector<int>res(nr);
        for(int i = 0; i < res.size(); i++)
        {
            fin >> res[i];
        }
        fout << solve_two(res);
    }
    return 0;
}

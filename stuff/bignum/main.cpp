#include <iostream>
#include <deque>
#include <cmath>
#include <tuple>

using namespace std;


typedef deque<int> num;

num nr_to_digits(string& n)
{
    num d;
    for(int i = 0; i < n.size(); i++)
    {
        n[i] = n[i] - '0';
        d.push_back(n[i]);
    }

    return d;
}

num sub(const num& t1, const num& t2)
{
    int d1 = t1.size();
    int d2 = t2.size();

    bool x = false;

    if(d1 == d2)
    {
        for(int i = 0; i < d1; i++)
        {
            if(t1[i] == t2[i])
            {
                x = true;
            }
            else
            {
                x = false;
                break;
            }
        }
    }

    if(x == true)
    {
        return {0};
    }

    deque<int> ds = (d1 >= d2 ? t1 : t2 );
    deque<int> n = (d1 < d2 ? t1 : t2 );

    deque<int> res;
    int delta = ds.size()- n.size();

    int m = 0;
    for(int i = ds.size() - 1; i >= 0; i--)
    {
        int down = i - delta >= 0 ? n[i - delta] : 0;
        int s = ds[i] - m - down;
        if(s < 0)
        {
            s = ds[i] + 10 - n[i] - m;
            res.push_front(s);
            m = 1;
        }
        else
        {
            res.push_front(s);
            m = 0;
        }
    }

    return res;
}


deque<int> add(const deque<int>& t1, const deque<int>& t2)
{

    deque<int> res;
    int d1 = t1.size();
    int d2 = t2.size();

    int delta = d2 >= d1 ? d2 - d1: d1 - d2;
    const deque<int> &add_up = (d1 >= d2 ? t1 : t2 );
    const deque<int> &add_down = (d1 < d2 ? t1 : t2 );


    int ex = 0;
    for(int i = add_up.size() - 1; i >= 0; i--)
    {
        int down = i - delta >= 0 ? add_down[i - delta] : 0;
        int y = add_up[i] + down + ex;
        if(y > 9)
        {
            ex = 1;
            res.push_front(y % 10);
        }
        else
        {
            res.push_front(y);
            ex = 0;
        }

    }

    if(ex > 0)
    {
        res.push_front(ex);
    }
    return res;
}

deque<int> multiply_one(const deque<int>& t1, int digit)
{
    if(digit == 0)
    {
        return {0};
    }

    deque<int> res;
    int ex = 0;
    for(int i = t1.size() - 1; i >= 0; i--)
    {
        int y = t1[i] * digit + ex;
        if(y > 9)
        {
            res.push_front(y % 10);
            ex = y / 10;
        }
        else
        {
            res.push_front(y);
            ex = 0;
        }
    }
    if(ex != 0)
    {
        res.push_front(ex);
    }
    return res;
}

tuple<num, int> div_one(const deque<int>& t1, int digit)
{
    if(digit == 1)
    {
        return {t1,0};
    }

    deque<int> res;
    int r = t1[0];

    for(int i = 0; i < t1.size(); i++)
    {
        auto dr = r / digit;
        if(dr != 0 || res.size() > 0){ //don't append zero first digit
            res.push_back(dr);
        }

        if(i + 1 != t1.size())
        {
            r = (r % digit) * 10 + t1[i + 1];
        }
    }
    if (res.size() == 0){
        res.push_back(0);
    }
    return {res,r % digit};
}

deque<int> multiply(const deque<int>& t1, const deque<int>& t2)
{
    deque<int> res= {0};
    int zeroes = 0;
    for(int i = t2.size() - 1; i >= 0; i--)
    {
        auto rt = multiply_one(t1,t2[i]);
        for(int j=0; j< zeroes ; j++)
        {
            rt.push_back(0);
        }
        res  = add(res,rt);
        zeroes+= 1;

    }
    return res;
}


const int QUOTIENT = 0;
const int REM = 1;


int main()
{

    string n;
    cin >> n;

    //string x;
    int x;
    cin >> x;



    deque<int> nr1 = nr_to_digits(n);
    //deque<int> nr2 = nr_to_digits(x);
    auto res = div_one(nr1, x);

    for(int i = 0; i < get<QUOTIENT>(res).size(); i++)
    {
        cout << get<QUOTIENT>(res)[i];
    }

    cout << " r " << get<REM>(res);

    cout << endl;

    return 0;
}





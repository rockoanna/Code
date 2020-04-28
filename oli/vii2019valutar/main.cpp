#include <bits/stdc++.h>

using namespace std;

typedef int64_t i64;
typedef int32_t i32;
typedef uint64_t u64;
typedef uint32_t u32;
typedef string st;
typedef stringstream ss;

typedef double db;

typedef vector<i64> vl;
typedef vector<i32> vi;
typedef vector<char> vc;
typedef vector<db> vd;
typedef vector<st> vs;

typedef map<st,i32> st2i;
typedef map<st,i64> st2l;
typedef map<st,db> st2d;

typedef map<i64,i64> l2l;
typedef map<i64,i32> l2i;

typedef map<i32,i32> i2i;
typedef map<i32,i64> i2l;

inline u64 dice(u64 a, u64 b, u64 nr, u64 n)
{
    return (a * nr + b) % n + 1;
}

inline bool okay(int i, u64 p, vector<u64>& lei, vector<u64>& euro, tuple<char, u64, u64>& v, vector<u64>& pass)
{
    u64 pos = p + 1;
    if(get<0>(v) == 'A')
    {
        return true;
    }

    if(get<0>(v) == 'R')
    {
        pass[i] += 1;
        return true;
    }

    if(get<0>(v) == 'G')
    {
        if(lei[i] >= pos * get<1>(v))
        {
            lei[i] -= pos * get<1>(v);
            euro[i] += pos;
            return true;
        }
        else
        {
            return false;
        }
    }

    if(get<0>(v) == 'V')
    {
        if(euro[i] >= pos)
        {
            euro[i] -= pos;
            lei[i] += pos * get<2>(v);
            return true;
        }
        else
        {
            return false;
        }
    }

}

u64 game(u64 a, u64 b, u64 nr, u64 n, u64 p, u64 l, u64 e, u64 x, vector<tuple<char, u64, u64>>& v)
{
    cout << endl;

    int final_ = p;
    vector<u64> pos(p);
    vector<u64> pass(p);
    vector<u64> lei(p, l);
    vector<u64> euro(p, e);
    vector<bool> in(p, true);


    while(x > 0)
    {

        for(u64 i = 0; i < p && x > 0; i++)
        {
            if(in[i])
            {
                x -= 1;
                nr = dice(a, b, nr, n);
                pos[i] += nr;
                pos[i] %= n;

                bool k = okay(i, pos[i], lei, euro, v[pos[i]], pass);
                if(!k)
                {
                    if(pass[i] > 0)
                    {
                        pass[i] -= 1;
                    }
                    else
                    {
                        final_ -= 1;
                        in[i] = false;

                    }
                }
                cout <<"Out " << i+1 << " runda "<<x<<" pos "<<pos[i]+1<<" lei "<<lei[i]<<" euro "<<euro[i] <<" activ "<<in[i] <<endl;
            }
        }
        cout<<"===================================================================================="<<endl;

        if(final_ == 0){
            break;
        }
    }
    return final_;
}

int main()
{
    u64 c;
    cin >> c;

    u64 a;
    cin >> a;
    u64 b;
    cin >> b;
    u64 nr;
    cin >> nr;

    u64 n;
    cin >> n;
    u64 p;
    cin >> p;

    u64 l;
    cin >> l;
    u64 e;
    cin >> e;

    u64 x;
    cin >> x;

    vector<tuple<char, u64, u64>> v(n);
    for(u64 i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        u64 y;
        cin >> y;

        u64 z;
        cin >> z;

        v[i] = {c, y, z};
    }

    if(c == 1)
    {
        cout << game(a, b, nr, n, p, l, e, x, v);
    }
    else
    {
        ///
    }

    return 0;
}
//
//1
//3 2 7
//5 3 2 3 8
//A 1 1
//G 5 4
//G 6 4
//V 6 5
//R 2 3



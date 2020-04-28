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

inline vector<i64> start(vector<i64>& v, i64 len)
{
    vector<i64> b(len);
    vector<pair<i64, i64>> in;

    in.reserve(len);
    pair<i64,i64> x = {v[0],1};
    for(int i = 1; i < len; i++)
    {

        if(v[i] > x.first)
        {
            x.first = v[i];
            b[i] += x.second;
            x.second += 1;

            while(!in.empty())
            {
                auto lst = in.back();
                if(lst.first < v[i])
                {
                    b[i] += lst.second;
                    x.second +=lst.second;
                    in.pop_back();
                }
                else
                {
                    break;
                }
            }

        }
        else
        {
            in.push_back(x);
            x = {v[i],1};
        }
    }

    return b;
}

//inline vector<i64> finish(vector<i64>& v, i64 len)
//{
//    vector<i64> e(len);
//
//    i64 lb = v[len - 1];
//    for(int i = len - 2; i > -1; i--)
//    {
//        if(v[i] > lb)
//        {
//            lb = v[i];
//            e[i] += (len - i - 1);
//        }
//        else
//        {
//            if(v[i] > v[i + 1])
//            {
//                i64 j = i + 1;
//                while(v[i] > v[j])
//                {
//                    e[i] += 1;
//                    j++;
//                }
//            }
//        }
//    }
//
//    return e;
//}

inline tuple<i64, i64> find_m(vector<i64>& v)
{
    i64 len = v.size();

    vector<i64> b = start(v, len);
    reverse(v.begin(),v.end());
    vector<i64> e = start(v, len);

    i64 mx = -1;
    i64 n = 0;

    for(int i = 0; i < len; i++)
    {
        i64 x = (b[i] + 1) * (e[len - i - 1] + 1);
        if(mx == x)
        {
            n += 1;
        }
        else
        {
            if(mx < x)
            {
                mx = x;
                n = 1;
            }
        }
    }

    return {mx, n};
}

int main()
{
    ifstream cin {"maxp.in"};
    ofstream cout {"maxp.out"};

    i64 n;
    cin >> n;
//    cin.ignore();
//
//    string s;
//    getline(cin, s);
//
//    ss sin(s);
    vector<i64> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        //std::cout << "i: " << v[i] << endl;
    }

    auto f = find_m(v);

    cout << get<0>(f) << endl;
    cout << get<1>(f);

    return 0;
}

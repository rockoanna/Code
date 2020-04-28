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

int main()
{
    ios::sync_with_stdio(false);

    int h;
    cin >> h;

    int l;
    cin >> l;

    vector<vector<int>> v(h);
    vector<vector<bool>> d(h);

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < l; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
            d[i].push_back(false);
        }
    }

    int res = 0;
    for(int i = 0; i < h; i++)
    {
        int p = 0;
        for(int j = 0; j < l; j++)
        {
            int t = v[i][j];

            if(t == 1)
            {
                p = t;
                continue;
            }

            if(t > p)
            {
                bool j0;
                if(j > 0)
                {
                    j0 = true;
                }
                else
                {
                    j0 = false;
                }

                bool i0;
                if(i > 0)
                {
                    i0 = true;
                }
                else
                {
                    i0 = false;
                }

                bool ie;
                if(i + 1 != h)
                {
                    ie = true;
                }
                else
                {
                    ie = false;
                }

                bool je;
                if(j + 1 != l)
                {
                    je = true;
                }
                else
                {
                    je = false;
                }

                if(!je || t > v[i][j + 1])
                {
                    if(!j0 || !ie || t > v[i + 1][j - 1])
                    {
                        if(!ie || t > v[i + 1][j])
                        {
                            if(!ie || !je || t > v[i + 1][j + 1])
                            {
                                if(!i0 || !j0 || t > v[i - 1][j - 1])
                                {
                                    if(!i0 || t > v[i - 1][j])
                                    {
                                        if(!i0 || !je || t > v[i - 1][j + 1])
                                        {
                                            res += 1;
                                            d[i][j] = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            p = t;
        }
    }


//    vector<int> adj = {-1, 0, 1};
//    int res = 0;
//
//    for(int i = 0; i < h; i++)
//    {
//        for(int j = 0; j < l; j++)
//        {
//            bool okay = true;
//            for(auto oi : adj)
//            {
//                if(okay)
//                {
//                    for(auto oj : adj)
//                    {
//                        if(oi != 0 || oj != 0)
//                        {
//                            int crti = i + oi;
//                            int crtj = j + oj;
//
//                            if(crti >= 0 && crti < h && crtj >= 0 && crtj < l)
//                            {
//                                if(v[crti][crtj] >= v[i][j])
//                                {
//                                    okay = false;
//                                    break;
//                                }
//                            }
//                        }
//                    }
//
//                }
//                else
//                {
//                    break;
//                }
//            }
//
//            if(okay){
//                res += 1;
//               // cout << i << " " << j << endl;
//            }
//            d[i][j] = okay;
//        }
//    }

    cout << res << endl;
    int mn = min(h, l);
    int md = 0;
    int count_ = 0;

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < l; j++)
        {
            if(d[i][j])
            {
                for(int xj = j + 2; xj < mn; xj++)
                {
                    if(d[i][xj])
                    {
                        int xi = i + xj - j;
                        if(xi < h)
                        {
                            if(d[xi][j] && d[xi][xj])
                            {
                                count_ += 1;
                                md = max(md, xj - j + 1);
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << count_ << endl;
    cout << md << endl;
    return 0;
}

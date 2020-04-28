#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
#include <cmath>

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

inline i32 next_pow(i32 n)
{
    i32 res = 1;
    while(res < n)
    {
        res *= 2;
    }

    return res;
}

void create_tree(vi &v, vi &seg_tree)
{
    u32 s_l = seg_tree.size();
    u32 x = s_l / 2;

    u32 vl = v.size();
    for(int i=s_l-1; i >=0; i--)
    {
        if(i >= x)
        {
            if(i - x < vl)
            {
                seg_tree[i] = v[i - x];
            }
        }
        else
        {
            seg_tree[i] = seg_tree[i * 2 + 1] + seg_tree[i * 2 + 2];
        }
    }
}

i64 sum (i32 idx, i32 vl, i32 vr, vi &seg_tree, i32 l, i32 r)
{
    if (l == r)
    {
        return seg_tree[seg_tree.size()/2 + l];
    }

    if(vl == l && vr == r)
    {
        return seg_tree[idx];
    }

    i32 mid = (vl + vr) / 2;
    if(r <= mid)  //I only go left
    {
        return sum(idx * 2 + 1, vl, mid, seg_tree, l, r);
    }
    else if(l > mid)
    {
        return sum(idx * 2 + 2, mid + 1, vr, seg_tree, l, r);
    }
    else
    {
        return sum(idx * 2 + 1, vl, mid, seg_tree, l, mid) + sum(idx * 2 + 2, mid + 1, vr, seg_tree, mid + 1, r);
    }

}

i64 sum_range (vi &seg_tree, i32 l, i32 r)
{
    return sum(0, 0, seg_tree.size() / 2, seg_tree, l, r);
}

inline i32 get_parent(i32 x)
{
    if(x == 0)
    {
        return -1;
    }
    if(x % 2 == 0)
    {
        return (x - 2) / 2;
    }

    return (x - 1) / 2;
}

vi get_path_to_root(i32 x)
{
    vi res;
    x = get_parent(x);
    while(x != -1)
    {
        res.push_back(x);
        x = get_parent(x);
    }
    return res;
}

array<int, 1000001> memo{0};

inline i32 div_nr(i32 x)
{

    if(memo[x] != 0){
        return memo[x];
    }
    i32 res = 0;
    for(int i = 1; i * i <= x; i++)
    {
        if(i * i == x)
        {
            res += 1;
            break;
        }

        if(x % i == 0)
        {
            res += 2;
        }
    }

    memo[x] = res;
    return res;
}

void update(i32 idx, i32 nv, vi &seg_tree)
{
    auto sgidx = (seg_tree.size() / 2) + idx;
    int delta = nv - seg_tree[sgidx];
    if (delta ==0){
        return;
    }
    seg_tree[sgidx] = nv;

    auto p = get_parent(sgidx);
    while(p != -1)
    {
        seg_tree[p] += delta;
        p = get_parent(p);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int q;
    cin >> q;
    cin.ignore();

    vi v(n);
    string s;
    getline(cin, s);
    stringstream ss(s);

    for(int i = 0; i < n; i++)
    {
        ss >> v[i];
    }

    i32 p2 = next_pow(n);
    vi seg_tree(p2 * 2 - 1);
    create_tree(v, seg_tree);

    for(int i = 0; i < q; i++)
    {
        int t;
        cin >> t;

        int l;
        int r;
        cin >> l;
        cin >> r;

        if(t == 2)
        {
            cout << sum_range(seg_tree, l - 1, r - 1)<< endl;
        }
        else
        {
            for(int j = l; j <= r; j++)
            {
                if (v[j - 1] > 2){
                    int d = div_nr(v[j - 1]);
                    v[j - 1] = d;
                    update(j - 1, d, seg_tree);
                }
            }
        }
    }

    return 0;
}

//int main()
//{
//    ofstream cout {"d.txt"};
//    for(int i = 1; i < 1000001; i++){
//        cout << div_nr(i) << ", ";
//    }
//}

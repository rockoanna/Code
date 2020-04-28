#include <iostream>
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

bool is_leaf(u64 id, vi& seg_tree, u64 vs)
{
    return id >= seg_tree.size() / 2 && id < seg_tree.size() / 2 + vs;
}

i64 sum (i32 idx, i32 vl, i32 vr, vi &seg_tree, u32 l, u32 r)
{
    if (l == r)
    {
        return seg_tree[seg_tree.size()/2 + l];
    }

    if(vl == l && vr == r)
    {
        return seg_tree[idx];
    }

    u32 mid = (vl + vr) / 2;
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

inline i32 get_parent(u32 x)
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

vi get_path_to_root(u32 x)
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

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vi v(n);
    for(i32 i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    i32 p = next_pow(n);
    i32 ts = p* 2 - 1;

    vi segtree(ts);
    create_tree(v, segtree);

    int q;
    cin >> q;

    for(i32 x = 0; x < q; x++)
    {
        int l;
        cin >> l;
        int r;
        cin >> r;

        cout << sum(0, 0, p - 1, segtree, l, r) << endl;

    }

    return 0;
}

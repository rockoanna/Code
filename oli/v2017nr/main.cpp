#include <array>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int left(int row, int n)
{
    return n + row;
}

int right(int row, int n)
{
    return left(row, n) + 1;
}

int solve_one(vector<int>directions)
{
    int nr = 1;
    for(int i = 0; i < directions.size(); i++){
        if(directions[i] == 1){
            nr = left(i + 1, nr);
        }else{
            nr = right(i + 1, nr);
        }
    }
    return nr;
}

array<int, 3> row_for_no(int n)
{
    if (n==1){
        array <int, 3> res = {1, 1, 2};
        return res;
    }
    int f = 1;
    int l = f + 1;

    for(int i = 2; i < 10001; i++){
            f = f + i - 1 ;
            l = f + i;
            if(n >= f && n < l){
                array <int, 3> res = {i,f,l};
                return res;
            }
    }
    array <int, 3> res = {0};
    return res;
}

int left_up(int n, int row)
{
    return n - row;
}

int right_up(int n, int row)
{
    return left_up(n,row) + 1;
}

int solve_two(int k)
{
    int sum = k;
    int elem = k;
    array<int,3>row_k = row_for_no(k);

    while(row_k[0] > 1){
        int p1 = left_up(elem, row_k[0]);
        int p2 = right_up(elem, row_k[0]);
        if(p2 < row_k[1]){
            elem = p2;
        }else{
            elem = p1;
        }
        sum += elem;
        row_k[0] -= 1;
        row_k[2] = row_k[1];
        row_k[1] = row_k[2] - row_k[0];
    }

    return sum;


}

int main()
{
    int req;
    cin >> req;
    if(req == 1){
        int len;
        cin >> len;
        vector<int>steps(len);
        for(int i = 0; i < len; i++){
            cin >> steps[i];
        }
        cout << solve_one(steps) << endl;

    }else{
        int no;
        cin >> no;
        cout << solve_two(no);
    }

    return 0;
}

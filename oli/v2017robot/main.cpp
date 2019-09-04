#include <deque>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;


int solve_one(string cmds)
{
    int res = 0;
    for(auto c : cmds){
        if(c == 'A'){
            res += 1;
        }
    }

    return res;

}

string solve_two(string cmds)
{
    string res = " ";
    int pos = 0;
    for(int i = 0; i < cmds.size(); i++){
        char c = cmds[i];
        if(c == 'A'){
            res.push_back(pos + '0');
        }else{
            if(c <= '0' && c >= '9'){
                int move_ = c - '0';

                if(cmds[i - 1] == 's'){
                    move_ = -move_;
                }
                pos += move_;
                pos = pos % 10;

                if(pos < 0){
                    pos += 10;
                }

            }
        }
    }
    return res;
}

deque<int> number_to_digits(int n)
{
    deque<int>res;
    do{
        res.push_front(n % 10);
        n = n / 10;
    }while(n != 0);
    return res;
}

string solve_three(int n)
{
    string res = "";
    deque<int>digits = number_to_digits(n);
    int crt_pos = 0;
    for(int i = 0; i < digits.size(); i++){
        if(crt_pos  == digits[i]){
            res.push_back('A');
        }else{
        int left_m;
        int right_m;
        if(digits[i] < crt_pos){
            left_m = crt_pos - digits[i];
            right_m = 10 - left_m;
        }else{
            right_m = digits[i]-crt_pos;
            left_m = 10 - right_m;
        }
        if(right_m <= left_m){
            res.push_back('D');
            res.push_back('0' + right_m);
        }else{
            res.push_back('S');
            res.push_back('0' + left_m);
        }
        res.push_back('A');
        crt_pos = digits[i];
        }

    }
    res.push_back('T');
    return res;
}


string solve_three2(string cmds)
{
    string res = "";
    int crt_pos = 0;
    for(auto c:cmds){
        int d = c -'0';
        if(crt_pos  == d){
            res.push_back('A');
        }else{
        int left_m;
        int right_m;
        if(d < crt_pos){
            left_m = crt_pos - d;
            right_m = 10 - left_m;
        }else{
            right_m = d - crt_pos;
            left_m = 10 - right_m;
        }
        if(right_m <= left_m){
            res.push_back('D');
            res.push_back('0' + right_m);
        }else{
            res.push_back('S');
            res.push_back('0' + left_m);
        }
        res.push_back('A');
        crt_pos = d;
        }

    }
    res.push_back('T');
    return res;
}

int main()
{
    int req;
    cin >> req;

    if(req == 1){
     string cmds;
     cin >> cmds;
     int res = solve_one(cmds);
     cout<< res << endl;
    }else {
        if (req ==2){
            string cmds;
            cin >> cmds;
            string res = solve_two(cmds);
            cout<< res << endl;
        }else{
            string output;
            cin >> output;
            for(auto c:output){
                if (c <'0' && c >'9'){
                    return;
                }
            }
            string res = solve_three2(output);
            cout << res;
        }
    }

    return 0;
}

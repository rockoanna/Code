#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int loan_duration;
    cin >> loan_duration;
    while(loan_duration > 0){
        double dp;
        cin >> dp;
        double loan;
        cin >> loan;
        int dep_n;
        cin >> dep_n;

        int prev_m = -1;
        vector<double>dep;
        dep.reserve(loan_duration);
        for(int i = 0; i < dep_n; i++){
            int month;
            double dep_f;
            cin >> month;
            cin >> dep_f;
            if(prev_m > -1){
                for(int j = prev_m + 1; j < month; j++){
                    dep.push_back(dep[prev_m]);
                }
            }
            dep.push_back(dep_f);
            prev_m = month;
        }
        double mp = loan / loan_duration;
        double cv = (dp + loan)*(1 - dep[0]);
        int crt_month = 0;
        while(loan > cv){
            crt_month += 1;
            loan-= mp;
            if(crt_month < dep.size()){
                cv = cv * (1 - dep[crt_month]);
            }else{
                cv = cv * (1 - dep[dep.size() - 1]);
            }
        }
        if(crt_month == 1){
            cout << crt_month << " month" <<endl;

        }else{
            cout << crt_month << " months" << endl;
        }
        cin >> loan_duration;
    }

    return 0;
}

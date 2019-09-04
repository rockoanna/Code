#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for(int x = 0; x < n; x++)
    {
        int count_m = 0;
        int count_f = 0;

        string s;
        getline(cin, s);
        stringstream line_str(s);
        string tracks;

        while(line_str >> tracks){
            if(tracks[0] == 'M'){
                count_m += 1;
            }else{
                count_f += 1;
            }

            if(tracks[1] == 'F'){
                count_f += 1;
            }else{
                count_m += 1;
            }
        }

        if(count_f == count_m && count_f != 1){
            cout << "LOOP" << '\n';
        }else{
            cout << "NO LOOP" << '\n';
        }

    }

    return 0;

    }


//int main2(){
//
// string line="MF   FF dfsdfsd dsfsdfsd        \n";
// for(int i =0; i<line.size();i+=3){
//        string str = line.substr(i ,2);
// //       cout <<str<<":"<<endl;
// }
//
//
//
//
//  stringstream line_str(line);
//  string tmp;
//  while(line_str >> tmp){
//        cout <<tmp<<":"<<endl;
//  }
//
//
//
//
//}

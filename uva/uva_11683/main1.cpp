#include <vector>
#include <iostream>

using namespace std;

int mainx()
{

    int h;
    int l;
    cin >> h;

    while(h != 0)
    {
        cin >> l;
        vector<vector<bool>> m(h);
        for(int i = 0; i < h; i++)
        {
            m[i].resize(l);
        }

        int el;
        int total = 0;
        for(int i = 0; i < l; i++){
            cin >> el;
            for(int j=0;j < h -el;j++){
                m[j][i] = true;
                if(i==0 || m[j][i-1] == false ){
                    total+=1;
                }
            }
           // cout<<i<<endl;
        }

//         for(auto v : m){
//            for(int i = 0; i < l; i++){
//                if(v[i]){
//                    cout<<'o';
//                }else{
//                    cout<<'x';
//                }
//            }
//            cout<<endl;
//         }
//        int total  = 0;
//        for(int x = 0; x < h; x++)
//        {
//            if(m[x][0] == true){
//                    total+=1;
//            }
//            for(int i = 1; i < l; i++)
//            {
//                if(m[x][i] == true && m[x][i-1] == false )
//                {
//                   total+=1;
//                }
//
//            }
//        }

        cout << total<<endl;
        cin >> h;
    }


    return 0;
}

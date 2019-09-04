#include <vector>
#include <iostream>

using namespace std;

inline bool is_ordered(vector<int> &line){
        bool sorted = true;
        bool rsorted = true;

        for(int j = 1; j < line.size(); j++){
            if(sorted && line[j-1] > line
               [j]){
                sorted = false;
            }

            if(rsorted && line[j-1] < line[j]){
                rsorted = false;
            }
        }
        return sorted || rsorted;
}

int main()
{
    int n;
    cin >> n;
    cout << "Lumberjacks:" << endl;
    for(int i = 0; i < n; i++){
        vector<int>line(10);
        for(int j = 0; j < 10; j++){
            cin >> line[j];
        }

        bool sorted = is_ordered(line);
        if(sorted){
            cout << "Ordered" << endl;
        }else{
            cout << "Unordered" << endl;
        }
    }


    return 0;
}

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int nr_students;
        cin >> nr_students;
        vector<int>speed(nr_students);
        for(int j = 0; j < nr_students; j++){
            cin >> speed[j];
        }

        sort(speed.rbegin(), speed.rend());
        cout << "Case " << i + 1 << ": " << speed[0] << endl;

    }

    return 0;
}

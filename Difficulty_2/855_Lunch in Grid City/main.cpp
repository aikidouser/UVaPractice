#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    int test_case = 0;

    cin >> test_case;
    for(int i=0; i<test_case; i++){

        int s, a, f;
        int out_x, out_y;
        cin >> s >> a >> f;

        vector<int> x;
        vector<int> y;

        for(int j=0; j<f; j++){

            int c, d;
            cin >> c >> d;
            x.push_back(c);
            y.push_back(d);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        out_x = x[(f-1)/2];
        out_y = y[(f-1)/2];

        cout << "(Street: " << out_x << ", Avenue: " << out_y << ")" << endl;

//        ofstream ofs;
//        ofs.open("output.txt", ios_base::app);
//        if (!ofs.is_open()){
//            cout << "Failed to open file.\n";
//        } else {
//            ofs << "(Street: " << out_x
//                << ", Avenue: " << out_y << ")" << endl;
//        }
    }
    return 0;
}

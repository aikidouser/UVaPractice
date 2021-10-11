// 105 The Skyline Problem
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int L, H, R;
    vector<int> output;
    vector<vector<int>> buildings, skyline;

    while(cin >> L >> H >> R){
        vector<int> temp;
        temp.push_back(L);
        temp.push_back(H);
        temp.push_back(R);
        buildings.push_back(temp);
    }
    skyline.resize(buildings.back()[2] + 2);
    for(auto building : buildings){
        for (int j = building[0]; j < building[2]; j++){
            skyline[j].push_back(building[1]);
        }
    }
    for (size_t i = 1; i < skyline.size(); i++){
        vector<int>::iterator it = max_element(skyline[i].begin(), skyline[i].end());

        if(it != skyline[i].end()){
            output.push_back(*it);
        }else{
            output.push_back(0);
        }
    }
    for (size_t i = 0; i < output.size(); i++){
        if (i == 0){
            // vector<int> temp;
            // temp.push_back(i + 1);
            // temp.push_back(output[i]);
            // answer.push_back(temp);
            cout << i + 1 << " " << output[i];
            continue;
        }
        if(output[i] != output[i-1])
            cout << " " << i + 1 << " " << output[i];
    }
    cout << endl;

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
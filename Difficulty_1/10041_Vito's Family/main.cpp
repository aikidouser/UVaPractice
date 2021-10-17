#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    int data_num=0;
    vector<int> final_out;

    cin >> data_num;

    for(int i=0; i<data_num; i++){
        int rela_num=0, mid=0, output=0;
        int min_num=99999, max_num=-1;
        vector <int> vec;
        string line, s;

        cin >> rela_num;
        for(int j=0; j<rela_num; j++){
            int temp=0;
            cin >> temp;
            vec.push_back(temp);
        }
        sort(vec.begin(), vec.end());

        mid = vec[vec.size() / 2];

//        if(vec.size() % 2 == 0){
//            mid = vec[vec.size() / 2];
//
//        }else if(vec.size() % 2 == 1){
//            mid = vec[(vec.size() - 1) / 2];
//        }

        output=0;
        for(auto v : vec){
            output += abs(mid - v);
        }

        final_out.push_back(output);
    }
//    for(auto out : final_out){
//        cout << out << endl;
//    }
    for(int i=0; i<final_out.size(); i++){
        cout << final_out[i] << endl;
    }
    return 0;
}

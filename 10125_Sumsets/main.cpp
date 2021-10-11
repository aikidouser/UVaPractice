#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int num_eles = 0;
    vector<int> output;

    while(cin >> num_eles){

        if(!num_eles)
            break;
        bool solution = false;
        vector<int> input_set;

        for(int i=0; i<num_eles; i++){

            int in_ele;

            cin >> in_ele;
            input_set.push_back(in_ele);
        }
        sort(input_set.begin(), input_set.end());

        for(int d=input_set.size()-1; d>=0; d--){

            for(int a=0; a<input_set.size() && !solution; a++){

                if(a == d)
                    continue;

                for(int b=a+1; b<input_set.size() && !solution; b++){

                    if(b == d)
                        continue;

                    for(int c=b+1; c<input_set.size() && !solution; c++){

                        if(c == d)
                            continue;

                        int sum = input_set[a] + input_set[b] + input_set[c];

                        if(sum == input_set[d]){

                            // output.push_back(input_set[d]);
                            cout << input_set[d] << endl;
                            solution = true;
                            break;
                        }
                    }
                }
            }
        }
        if(!solution)
            cout << "no solution" << endl;
    }

//    for(auto i : output){
//
//        if(i != INT_MAX)
//            cout << i << endl;
//        else if(i == INT_MAX)
//
//    }
    return 0;
}

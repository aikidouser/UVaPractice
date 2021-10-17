#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool if_not_repeat(string str){
    vector<int> n(10, 0);

    for(auto c : str){

        if(!n[c - '0']){

            n[c-'0'] = 1;

        }else{

            return false;
        }
    }
    return true;
}


int main()
{
    int input=0;
    vector< vector<string> > final_output;

    while(cin >> input && input){

        vector<string> temp_output;
        bool if_miss = true;
        string miss = "There are no solutions for " + to_string(input) + ".";
        string divi = " / ";
        string equ = " = " + to_string(input);


        for(int i=12345; i<=98765; i++){

            if(i % input == 0){

                string i_input = to_string(i/input);
                if(i_input.size() <= 3)                 //if i / input smaller than 1000, it means that there must need two zero like 00XXX.

                    continue;

                else if(i_input.size() == 4)            //0XXXX

                    i_input = "0" + i_input;

                string check = to_string(i) + i_input;
                bool if_break = false;

                if(if_not_repeat(check)){

                    if_miss = false;
                    temp_output.push_back(to_string(i) + divi + i_input + equ);
                }
            }
        }

        if(!if_miss){

            final_output.push_back(temp_output);

        }else{

            temp_output.push_back(miss);
            final_output.push_back(temp_output);
        }
    }

    for(int i = 0; i < final_output.size(); i++){

        for(int j=0; j<final_output[i].size(); j++){

            cout << final_output[i][j];
            if((j != final_output[i].size() - 1)){
                cout << endl;
            }
        }
        cout << endl;

        if(i != final_output.size() - 1){
            cout << endl;
        }
    }
    return 0;
}

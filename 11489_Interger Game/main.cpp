#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int input_times=0;
    vector <string> final_out;
    cin >> input_times;

    for(int i=0; i<input_times; i++){

        int sum=0;
        vector <int> dig_count(3, 0);
        string input;

        cin >> input;
        for(auto ch : input){

            int dig = ch - '0';

            sum += dig;

            dig_count[dig % 3]++;
        }

        if(sum % 3 && dig_count[sum % 3]){

            dig_count[0]++;
        }

        if(dig_count[0] % 2){

            final_out.push_back("S");

        }else{

            final_out.push_back("T");
        }
    }

    int c=1;
    for(vector<string>::iterator it=final_out.begin(); it!=final_out.end(); it++){

        cout << "Case " << c++ << ": " << *it;
        //if(it != final_out.end()-1)
        cout << endl;
    }
    return 0;
}

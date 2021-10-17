#include <iostream>
#include <vector>

using namespace std;

int main(){

    int input;
    vector<int> coint_type = {5, 10, 25, 50};
    vector<int> output_table(7490, 1);

    for(int i=0; i<coint_type.size(); i++){
        for(int j=coint_type[i]; j<output_table.size(); j++){

            output_table[j] += output_table[j-coint_type[i]];
        }
    }

//    ofstream ofs;
    while(cin >> input && input != EOF){

        cout << output_table[input] << endl;

//        ofs.open("output.txt", ios_base::app);
//        if (!ofs.is_open()){
//            cout << "Failed to open file.\n";
//        } else {
//            ofs << output_table[input] << endl;
//        }

    }
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int num_regions = 0;
    vector<int> final_outputs;

    while(cin >> num_regions){

        if(!num_regions)
            break;

        // start from m = 1, del 1 because of the vec.begin()
        int output_m = 0;
        vector<int> regions;
        while(true){

            bool m_success = false;
            vector<int> tpr_vec;
            vector<int>::iterator suicide;

            // init
            for(int i=0; i<num_regions; i++)

                regions.push_back(i);

            regions.erase(regions.begin());         // start from region 1
            while(true){

                if(output_m >= regions.size()){

                    suicide = regions.begin() + (output_m % regions.size());

                }else{

                    suicide = regions.begin() + output_m;
                }

                // fail
                if(*suicide == 12){

                    if(regions.size() == 1)

                        m_success = true;

                    break;
                }

                tpr_vec.assign(regions.begin(), suicide);
                regions.erase(regions.begin(), suicide + 1);

                if(tpr_vec.empty())

                    continue;

                regions.reserve(regions.size() + tpr_vec.size());
                regions.insert(regions.end(), tpr_vec.begin(), tpr_vec.end());
            }

            // the current m fail, try next one
            if(m_success){

                final_outputs.push_back(++output_m);
                break;

            }else{

                output_m++;
                regions.clear();
            }
        }
    }
    for(auto x : final_outputs){

        cout << x << endl;
    }
    return 0;
}

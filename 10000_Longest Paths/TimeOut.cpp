#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> longest(vector<vector<int>>, int, int);

int main()
{
    int nodes_num=0;
    int case_time=0;
    vector<string> outputs;

    while(cin >> nodes_num){

        if(nodes_num == 0){
            break;
        }
        int start_point=0;      // 1 <= start_point <= nodes_num
        int p=0, q=0;           // p -> q
        int dest=0, len=0;
        vector<int> result;
        vector< vector<int> > graph_vec(++nodes_num);


        ++case_time;
        cin >> start_point;
        while(cin >> p >> q){

            if(!p && !q)
                break;

            graph_vec[p].push_back(q);
        }

        result = longest(graph_vec, start_point, 0);
        dest = result[0];
        len = result[1] - 1;

//        printf("Case %d: The longest path from %d has length %d, finishing at %d\n\n",
//               case_time, start_point, len, dest);

        outputs.push_back("Case " + to_string(case_time)
                          + ": The longest path from " + to_string(start_point)
                          + " has length " + to_string(len)
                          + ", finishing at " + to_string(dest) + ".");
    }
    for(auto i : outputs)
        cout << i << endl << endl;

    return 0;
}

vector<int> longest(vector<vector<int>> g_vec, int s_point, int len){

    vector<int> result;

    //cout << "s: " << s_point << endl;

    if(!g_vec[s_point].size()){

        //cout << "size=0" << endl;
        result.push_back(s_point);
        result.push_back(len + 1);

        return result;

    }else{

        //cout << "continue" << endl;

        int max_len=-1, tpr_len=0, e_point=0, tpr_e=0;

        for(auto node : g_vec[s_point]){

            result = longest(g_vec, node, len);
            tpr_e = result[0];
            tpr_len = result[1];
            result.clear();
            // cout << "re: " << tpr_e << " " << tpr_len << endl;
            //cout << max_len << endl;

            if(tpr_len > max_len){

                max_len = tpr_len;
                e_point = tpr_e;

            }else if(tpr_len == max_len){

                if(e_point > tpr_e)
                    e_point = tpr_e;
            }
        }
        result.push_back(e_point);
        result.push_back(max_len + 1);

        return result;
    }
}

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int main()
{
    int points = 0;
    int case_num = 0;

    while(cin >> points && points){

        int s_point = 0;
        int p, q;

        vector<int> dist(points+1, 0);
        vector<vector<int>> graph(points+1);
        queue<int> next;
        vector<bool> inqueue(points+1, false);

        cin >> s_point;

        while(cin >> p >> q && p && q){

            graph[p].push_back(q);
        }

        next.push(s_point);
        while(!next.empty()){

            int current_node = next.front();
            next.pop();
            inqueue[current_node] = false;

            for(int i=0; i<graph[current_node].size(); i++){

                int next_node = graph[current_node][i];

                if(dist[current_node]+1 > dist[next_node]){

                    dist[next_node] = dist[current_node] + 1;
                }
                if(!inqueue[next_node]){

                    next.push(next_node);
                    inqueue[next_node] = true;
                }
            }
        }

        int max_dist = -1, final_node = 0;
        for(int i=1; i<dist.size(); i++){

            if(dist[i] > max_dist){

                max_dist = dist[i];
                final_node = i;
            }
        }
        cout << "Case " << ++case_num
             << ": The longest path from " << s_point
             << " has length " << max_dist
             << ", finishing at "<< final_node << "." << endl << endl;

//        ofstream ofs;
//        ofs.open("output.txt", ios_base::app);
//        if (!ofs.is_open()){
//            cout << "Failed to open file.\n";
//        } else {
//            ofs << "Case " << ++case_num
//                << ": The longest path from " << s_point
//                << " has length " << max_dist
//                << ", finishing at "<< final_node << "." << endl << endl;
//        }

    }
    return 0;
}

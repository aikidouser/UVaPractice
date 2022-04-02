#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    int T, N, M;
    cin >> T;
    for (int i = 0; i < T; i++) {
        vector<string> polits;
        map<string, set<string> > hate_graph;
        vector<set<string> > output(4);
        vector<set<string> > check(4);

        // output.clear();
        // check.clear();
        // polits.clear();
        // hate_graph.clear();

        cin >> N >> M;
        for (int j = 0; j < N; j++) {
            string temp;

            cin >> temp;
            polits.push_back(temp);
        }
        sort(polits.begin(), polits.end());

        for (int j = 0; j < M; j++) {
            string temp1, temp2;

            cin >> temp1 >> temp2;
            if (temp2 == min(temp1, temp2)) {
                swap(temp1, temp2);
            }
            // cout << temp1 << " " << temp2 << endl;
            hate_graph[temp1].insert(temp2);
        }

        // map<string, set<string> >::iterator it;
        // for (it = hate.begin(); it != hate.end(); it++) {
        //     set<string>::iterator it_set;
        //     for (it_set = it->second.begin(); it_set != it->second.end(); it_set++) {
        //         cout << *it_set << " ";
        //     }
        //     cout << endl;
        // }
        cout << "Case #" << i + 1 << endl;
        for (int j = 0; j < polits.size(); j++) {
            for (int k = 0; k < 4; k++) {
                // cout << "k: " << k << endl;
                // cout << "polits[j]: " << polits[j] << endl;
                if (check[k].count(polits[j]) == 0) {
                    output[k].insert(polits[j]);
                    check[k].insert(hate_graph[polits[j]].begin(), hate_graph[polits[j]].end());
                    break;
                }
            }
        }

        for (int j = 0; j < 4; j++) {
            for (auto k : output[j])
                cout << k << " ";
            cout << endl;
        }
        cout << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
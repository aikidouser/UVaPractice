#include <iostream>
#include <set>

using namespace std;

int main() {
    int N, M;
    set<int> cd_set;

    while (cin >> N >> M, N || M) {
        int cd, same = 0;

        for (int i = 0; i < N; i++) {
            cin >> cd;
            cd_set.insert(cd);
        }
        for (int i = 0; i < M; i++) {
            cin >> cd;
            if (cd_set.find(cd) != cd_set.end()) {
                same++;
            }
        }
        cout << same << endl;
        cd_set.clear();
    }
    return 0;
}

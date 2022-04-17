#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    int f_num = 0, n = 0, m = 0;

    while (cin >> n >> m && n && m) {
        vector<int> row(m + 2, 0);
        vector<vector<int> > minesweeper(n + 2, row);

        if (f_num != 0) cout << endl;
        cout << "Field #" << ++f_num << ":" << endl;
        for (int i = 1; i <= n; i++) {
            string temp;

            cin >> temp;
            for (int j = 1; j <= m; j++) {
                if (temp[j - 1] == '*') {
                    minesweeper[i][j] = '*';

                    for (int a = -1; a <= 1; a++) {
                        for (int b = -1; b <= 1; b++) {
                            if ((a == b && b == 0) ||
                                (minesweeper[i + a][j + b] == '*'))
                                continue;

                            minesweeper[i + a][j + b]++;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (minesweeper[i][j] == '*')
                    cout << (char)minesweeper[i][j];
                else
                    cout << minesweeper[i][j];
            }
            cout << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}

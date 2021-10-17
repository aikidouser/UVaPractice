// UVa 141 The Spot Game
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char move;
    int N = 0, input_i = 0, input_j = 0, lose = 0;
    set<vector<vector<bool> > > check;
    vector<vector<bool> > board;

    while (cin >> N && N) {
        vector<bool> temp(N, 0);
        vector<vector<bool> > initializer;
        vector<vector<bool> > board_turn;
        lose = 0;
        check.clear();
        board.clear();

        for (int i = 0; i < N; i++) {
            board.push_back(temp);
            board_turn.push_back(temp);
            initializer.push_back(temp);
        }

        for (int x = 0; x < N * 2; x++) {
            cin >> input_i >> input_j >> move;
            if (move == '+') {
                board[input_i - 1][input_j - 1] = true;
                // cout << input_i - 1 << " " << input_j - 1 << " +" << endl;
            } else if (move == '-') {
                board[input_i - 1][input_j - 1] = false;
                // cout << input_i - 1 << " " << input_j - 1 << " -" << endl;
            }
            // cout << "-------------------" << endl;
            // for (auto i : board) {
            //     for (auto j : i)
            //         cout << j << " ";
            //     cout << endl;
            // }

            if (check.count(board) && lose == 0)
                lose = x + 1;
            // cout << "lose: " << lose << endl;

            for (int y = 0; y < 4; y++) {
                check.insert(board);
                // board turn
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        if (board[i][j] == true) {
                            board_turn[j][N - i - 1] = true;
                        }
                    }
                }
                board = board_turn;
                // for (auto i : board_turn) {
                //     for (auto j : i)
                //         cout << j << " ";
                //     cout << endl;
                // }
                board_turn = initializer;
                // cout << "-------------------" << endl;
            }
        }
        if (lose > 0)
            cout << "Player " << lose % 2 + 1 << " wins on move " << lose << endl;
        else
            cout << "Draw" << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
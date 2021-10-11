// UVa 108 Maximum Sum
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, n, sum, maxSum;
    vector<vector<int>> array, columnSum;

    while (cin >> N) {
        array.clear();
        maxSum = INT_MIN;
        columnSum.clear();
        columnSum.resize(N);
        for (int i = 0; i < N; i++)
            columnSum[i].resize(N);

        for (int i = 0; i < N; i++) {
            vector<int> temp;
            for (int j = 0; j < N; j++) {
                cin >> n;
                temp.push_back(n);
            }
            array.push_back(temp);
        }

        for (int i = 0; i < N; i++) {
            vector<int> temp;
            for (int j = 0; j < N; j++) {
                if (i == 0) {
                    columnSum[i][j] = array[i][j];
                } else {
                    columnSum[i][j] = columnSum[i - 1][j] + array[i][j];
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                sum = 0;
                for (int k = 0; k < N; k++) {
                    if (i == 0) {
                        sum += columnSum[j][k];
                    } else {
                        sum += columnSum[j][k] - columnSum[i - 1][k];
                    }
                    if (sum > maxSum)
                        maxSum = sum;
                    if (sum < 0)
                        sum = 0;
                }
            }
        }
        cout << maxSum << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
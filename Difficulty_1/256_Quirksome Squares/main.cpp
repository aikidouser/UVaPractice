// UVa 256 Quirksome Squares
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int digit = 0, square = 0, low = 0, high = 0;
    vector<int> digits = {10, 100, 1000, 10000};
    vector<vector<int> > answers;

    for (size_t i = 0; i < digits.size(); i++) {
        vector<int> temp;
        for (int j = 0; j < digits[i]; j++) {
            square = j * j;
            low = square % digits[i];
            high = square / digits[i];
            if (low + high == j)
                temp.push_back(square);
        }
        answers.push_back(temp);
    }

    cout.fill('0');
    while (cin >> digit) {
        for (auto i : answers[(digit / 2) - 1])
            cout << setw(digit) << i << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
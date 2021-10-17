// 382 Perfection
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int input = 0;
    cout << "PERFECTION OUTPUT" << endl;
    while (cin >> input && input) {
        vector<int> divisor;
        int sum_of_divisor = 0;

        for (int i = 1; i < input; i++) {
            if (input % i == 0)
                divisor.push_back(i);
        }

        for (auto i : divisor) {
            sum_of_divisor += i;
        }
        cout << setw(5) << input << "  ";
        if (sum_of_divisor == input)
            cout << "PERFECT" << endl;
        else if (sum_of_divisor < input)
            cout << "DEFICIENT" << endl;
        else if (sum_of_divisor > input)
            cout << "ABUNDANT" << endl;
    }
    cout << "END OF OUTPUT" << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
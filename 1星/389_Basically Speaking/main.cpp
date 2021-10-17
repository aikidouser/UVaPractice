#include <math.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);

    string input;
    int ori, tar;

    while (cin >> input >> ori >> tar) {
        // cout << input << endl;
        int sum = 0;
        string output = "";

        for (size_t i = 0; i < input.size(); i++) {
            int number = 0, digit = 0;

            if ('0' <= input[i] && input[i] <= '9')
                number = input[i] - 48;
            else if ('A' <= input[i] && input[i] <= 'F')
                number = input[i] - 55;

            digit = input.size() - 1 - i;
            sum += number * pow(ori, digit);
        }

        do {
            int number = sum % tar;
            if (number <= 9)
                number += 48;
            else
                number += 55;
            output.push_back(number);

            sum /= tar;
        } while (sum);
        if (output.size() > 7) {
            cout << setw(7) << "ERROR" << endl;
        } else {
            reverse(output.begin(), output.end());
            cout << setw(7) << output << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
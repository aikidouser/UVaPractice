// Uva 299 Train Swapping
#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int test_case = 0, length = 0;
    vector<int> trains;

    cin >> test_case;
    while (test_case--) {
        int temp, swap_time = 0;
        trains.clear();

        cin >> length;
        for (int i = 0; i < length; i++) {
            cin >> temp;
            trains.push_back(temp);
        }

        for (int i = 0; i < length - 1; i++) {
            for (int j = 0; j < length - 1 - i; j++) {
                if (trains[j] > trains[j + 1]) {
                    swap(trains[j], trains[j + 1]);
                    ++swap_time;
                }
            }
        }
        cout << "Optimal train swapping takes " << swap_time << " swaps.\n";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
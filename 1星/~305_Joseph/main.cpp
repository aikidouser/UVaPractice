#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int input = 0;
    vector<int> test_case(14, 0);

    for (int k = 1; k <= 14; k++) {
        int m = k + 1;

        while (true) {
            int n = k * 2, exec = -1;

            while (n > k) {
                exec += m;
                exec %= n;
                if (exec < k)
                    break;
                n--;
                exec--;
            }
            if (n <= k) {
                test_case[k - 1] = m;
                break;
            }
            m++;
        }
    }
    while (cin >> input && input) {
        cout << test_case[input - 1] << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
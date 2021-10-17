#include <iostream>

using namespace std;

int main() {
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);

    int start, end;

    while (cin >> start >> end && (start != -1 && end != -1)) {
        int diff = 0;

        if (start > end)
            swap(start, end);

        diff = end - start;
        start += 100;
        if (start - end < diff) {
            cout << start - end << endl;
        } else {
            cout << diff << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
// 264 UVa Count on Cantor
#include <iostream>
#include <vector>

using namespace std;

struct fraction {
    int x;
    int y;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i = 1, term = 0;
    fraction temp;
    vector<fraction> answers;

    while (answers.size() < 10000000) {
        for (int j = 0; j < i; j++) {
            if (i % 2 == 1) {
                temp.x = i - j;
                temp.y = 1 + j;
            } else if (i % 2 == 0) {
                temp.x = 1 + j;
                temp.y = i - j;
            }
            // cout << "test: " << temp.x << " " << temp.y << endl;
            answers.push_back(temp);
        }
        i++;
    }

    while (cin >> term) {
        cout << "TERM " << term << " IS ";
        cout << answers[term - 1].x << "/" << answers[term - 1].y << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
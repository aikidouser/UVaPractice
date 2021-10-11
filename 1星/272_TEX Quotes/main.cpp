// Uva 272 TEX Quotes
#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    bool if_pair = true;
    string input_line = "";
    char c;

    while (cin.get(c)) {
        if (c == '"') {
            if (if_pair) {
                cout << "``";
                if_pair = false;
            } else {
                cout << "''";
                if_pair = true;
            }
        } else {
            cout << c;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
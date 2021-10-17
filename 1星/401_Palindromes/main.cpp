#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string input;
    const set<char> mirror_char = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y', '1', '8'};
    map<char, char> reverse_char;
    reverse_char['E'] = '3';
    reverse_char['J'] = 'L';
    reverse_char['L'] = 'J';
    reverse_char['S'] = '2';
    reverse_char['Z'] = '5';
    reverse_char['2'] = 'S';
    reverse_char['3'] = 'E';
    reverse_char['5'] = 'Z';

    while (cin >> input) {
        bool if_pal = true, if_mir = true;

        for (size_t i = 0; i <= input.size() / 2; i++) {
            int p = input.size() - 1 - i;

            // cout << input[i] << ' ' << input[p] << endl;
            if (input[i] != input[p]) {
                if_pal = false;

                if (reverse_char[input[i]] != input[p])
                    if_mir = false;

            } else if (input[i] == input[p]) {
                if (!mirror_char.count(input[i]))
                    if_mir = false;
            }
        }

        cout << input;
        if (if_mir && if_pal)
            cout << " -- is a mirrored palindrome." << endl;
        else if (!if_pal && if_mir)
            cout << " -- is a mirrored string." << endl;
        else if (if_pal && !if_mir)
            cout << " -- is a regular palindrome." << endl;
        else if (!if_pal && !if_mir)
            cout << " -- is not a palindrome." << endl;
        cout << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
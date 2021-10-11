#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool sortByValue(const pair<char, int> &a,
                 const pair<char, int> &b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int line_num = 0;
    map<char, int> output;
    vector<pair<char, int> > my_vector;

    cin >> line_num;
    cin.ignore();
    for (int i = 0; i < line_num; i++) {
        string input = "";

        getline(cin, input);
        cerr << input << endl;
        for (auto i : input) {
            if ('a' <= i && i <= 'z')
                i -= 32;
            if ('A' <= i && i <= 'Z') {
                if (output.count(i)) {
                    output[i]++;
                } else {
                    output[i] = 1;
                }
            }
        }
    }
    map<char, int>::iterator it;
    for (it = output.begin(); it != output.end(); it++) {
        my_vector.push_back(make_pair(it->first, it->second));
    }
    sort(my_vector.begin(), my_vector.end(), sortByValue);
    for (auto i : my_vector) {
        cout << i.first << " " << i.second << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
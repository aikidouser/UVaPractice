// UVa 263 Number Chains
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int input = 0, descending = 0, ascending = 0, diff = 0, chain_length = 0;
    vector<int> num_seq;
    set<int> check;
    bool if_same = false;

    while (cin >> input && input) {
        num_seq.clear();
        check.clear();
        if_same = false;
        chain_length = 0;

        cout << "Original number was " << input << endl;
        while (!if_same) {
            descending = 0;
            ascending = 0;
            chain_length++;

            while (input) {
                num_seq.push_back(input % 10);
                input /= 10;
            }
            sort(num_seq.begin(), num_seq.end());
            // descending
            for (int i = 0, j = 1; i < num_seq.size(); i++, j *= 10)
                descending += num_seq[i] * j;
            // cout << "descending: " << descending << endl;
            // ascending
            for (int i = num_seq.size() - 1, j = 1; i >= 0; i--, j *= 10)
                ascending += num_seq[i] * j;
            // cout << "ascending: " << ascending << endl;
            diff = descending - ascending;
            cout << descending << " - " << ascending << " = " << diff << endl;
            if (check.count(diff))
                if_same = true;
            check.insert(diff);
            input = diff;
            num_seq.clear();
        }
        cout << "Chain length " << chain_length << endl
             << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
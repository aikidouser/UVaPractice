#include <iostream>
#include <vector>

using namespace std;

int main() {
    (void)!freopen("output.txt", "w", stdout);

    for (int a = 2; a <= 200; a++) {
        for (int b = 2; b < a; b++) {
            for (int c = b; c < a; c++) {
                for (int d = c; d < a; d++) {
                    if (a * a * a == b * b * b + c * c * c + d * d * d) {
                        cout << "Cube = " << a << ", ";
                        cout << "Triple = (" << b << "," << c << "," << d << ")" << endl;
                    }
                }
            }
        }
    }

    fclose(stdout);

    return 0;
}

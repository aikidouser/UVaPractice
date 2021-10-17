// UVA 145 Gondwanaland Telecom
#include <stdio.h>
#include <string.h>

#include <iomanip>
#include <iostream>
#include <map>

using namespace std;

struct schedule {
    float dRate;  // 8:01 - 18:00
    float eRate;  // 18:01 - 22:00
    float nRate;  // 22:01 - 8:00
    float all;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char step;
    string numCalled, sStartHour, sStartMinute, sEndHour, sEndMinute;
    float charge;
    int startHour = 0, startMinute = 0, endHour = 0, endMinute = 0;
    int cutMinute[4] = {480, 1080, 1320, 1440}, sums[4] = {0};
    bool rev = false;
    map<char, schedule> schedules;

    schedules['A'] = {0.10, 0.06, 0.02, 0.10 * 600 + 0.06 * 240 + 0.02 * 600};
    schedules['B'] = {0.25, 0.15, 0.05, 0.25 * 600 + 0.15 * 240 + 0.05 * 600};
    schedules['C'] = {0.53, 0.33, 0.13, 0.53 * 600 + 0.33 * 240 + 0.13 * 600};
    schedules['D'] = {0.87, 0.47, 0.17, 0.87 * 600 + 0.47 * 240 + 0.17 * 600};
    schedules['E'] = {1.44, 0.80, 0.30, 1.44 * 600 + 0.80 * 240 + 0.30 * 600};

    while (cin >> step && step != '#') {
        cin >> numCalled >> sStartHour >> sStartMinute >> sEndHour >> sEndMinute;
        startHour = stoi(sStartHour);
        startMinute = stoi(sStartMinute);
        endHour = stoi(sEndHour);
        endMinute = stoi(sEndMinute);
        rev = false;
        memset(sums, 0, sizeof(sums));

        // reverse if cross day
        if (startHour > endHour || (startHour == endHour && startMinute > endMinute)) {
            rev = true;
            int temp = startHour;
            startHour = endHour;
            endHour = temp;
            temp = startMinute;
            startMinute = endMinute;
            endMinute = temp;
        }
        startMinute += 60 * startHour;
        endMinute += 60 * endHour;

        for (size_t i = 0; i < sizeof(cutMinute) / sizeof(cutMinute[0]); i++) {
            if (startMinute == endMinute) {
                sums[0] = 600;
                sums[1] = 600;
                sums[2] = 240;
                break;
            }

            if (startMinute > cutMinute[i]) {
                continue;
            } else if (startMinute < cutMinute[i]) {
                if (endMinute > cutMinute[i]) {
                    sums[i] = cutMinute[i] - startMinute;
                    startMinute = cutMinute[i];

                } else if (endMinute <= cutMinute[i]) {
                    sums[i] = endMinute - startMinute;
                    break;
                }
            }
        }
        sums[0] = sums[0] + sums[3];
        charge = (sums[0] * schedules[step].nRate) + (sums[1] * schedules[step].dRate) + sums[2] * schedules[step].eRate;

        if (rev) {
            charge = schedules[step].all - charge;
            sums[0] = 600 - sums[0];
            sums[1] = 600 - sums[1];
            sums[2] = 240 - sums[2];
        }
        cout.precision(2);
        cout << setw(10) << numCalled
             << setw(6) << sums[1]
             << setw(6) << sums[2]
             << setw(6) << sums[0]
             << setw(3) << step
             << setw(8) << fixed << charge << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
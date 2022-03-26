#include <iostream>

using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int max_cycle = 0, cycle = 0, start, end;

    while(cin >> start >> end){
        max_cycle = 0;
        int a, b;
        if(start > end){
            a = end;
            b = start;
        }else{
            a = start;
            b = end;
        }

        for (int i = a; i <= b; i++){
            int t = i;
            cycle = 1;

            while(t != 1){
                if(t % 2 == 1)
                    t = 3 * t + 1;
                else
                    t /= 2;
                cycle++;
            }
            if(cycle > max_cycle)
                max_cycle = cycle;
        }
        cout << start << " " << end << " " << max_cycle << endl;
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}

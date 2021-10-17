#include <iostream>

using namespace std;

int main()
{
    int test_case=0;

    cin >> test_case;

    for(int i=0; i<test_case; i++){

        int drink=0, bottle=0;
        int e=0, f=0, c=0;

        cin >> e >> f >> c;

        bottle = e + f;
        drink = bottle/c;

        while(bottle >= c){

            bottle = bottle / c + bottle % c;
            drink = drink + bottle / c;
        }
        cout << drink << endl;
    }
    return 0;
}

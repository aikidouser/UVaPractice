#include <iostream>

using namespace std;

int places[10001] = {0};
int Rightest = 0;
int main()
{
    int L, H, R;
    while(cin >> L >> H >> R){
        if(R > Rightest) Rightest = R;

        for(int i=L; i<R; i++){
            if(places[i] < H) places[i] = H;
        }
    }
    bool first = true;
    for(int i=1; i<=Rightest; i++){
        if(first && places[i]!=0){      // ???
            cout << i;
            first = false;
            continue;
        }

        if(!first && places[i-1]!=places[i]){
            cout << " " << places[i-1] << " " << i;
        }
    }
    cout << " " << 0 <<endl;
    return 0;
}
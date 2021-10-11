#include <iostream>
#include <vector>

using namespace std;

struct cherry{

    int x;
    int y;
};

int main()
{
    int N = 0;
    vector<vector<int>> out;

    while(scanf("%d", &N) && N){

        bool success = false;
        vector<cherry> cherries;

        for(int i=0; i<2*N; i++){

            int x, y;
            cherry tpr;

            scanf("%d %d", &x, &y);
            tpr.x = x;
            tpr.y = y;
            cherries.push_back(tpr);
        }

        for(int A=-500; A<=500 && !success; A++){
            for(int B=-500; B<=500 && !success; B++){

                int lucy = 0, lily = 0;

                for(auto i : cherries){

                    int jud = A * i.x + B * i.y;

                    if(jud > 0)
                        lucy++;
                    else if(jud < 0)
                        lily++;
                }

                if(lucy == lily && lucy == N){
                    printf("%d %d\n", A, B);
                    success = true;
                }
            }
        }
    }
    return 0;
}

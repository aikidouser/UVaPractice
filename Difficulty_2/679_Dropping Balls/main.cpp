#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int test_case = 0, end_flag = 0;
    vector<int> output;

    scanf("%d", &test_case);

    for(int i=0; i<test_case; i++){

        int depth = 0, balls_num = 0;
        int start = 0, length = 0;
        scanf("%d %d", &depth, &balls_num);

        start = pow(2, depth - 1);
        length = start;

        for(int j=0; j<depth-1; j++){

            length /= 2;
            if(balls_num % 2){      // odd

                // start = start;
                balls_num = (balls_num + 1) / 2;

            }else{                  // even

                start += length;
                balls_num /= 2;
            }
        }
        output.push_back(start);
    }
    scanf("%d", &end_flag);

    for(auto i : output){

        cout << i << endl;
    }

    return 0;
}

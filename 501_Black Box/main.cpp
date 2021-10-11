#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

	int case_num;

	cin >> case_num;

	while(case_num--){
		int M = 0, N = 0;
		queue<int> A_q;
		vector<int> black_box;

		cin >> M >> N;
		while(M--){
			int temp = 0;
			cin >> temp;
			A_q.push(temp);
		}

		int get_order = 0;
		while(N--){
			int get_size = 0;

			cin >> get_size;

            while(black_box.size() < get_size){
                auto iter = lower_bound(black_box.begin(), black_box.end(), A_q.front());
                black_box.insert(iter, A_q.front());
                A_q.pop();
            }
            if(black_box.size() == get_size)
                cout << black_box[get_order++] << endl;
		}
		if(case_num) cout << endl;
	}
}

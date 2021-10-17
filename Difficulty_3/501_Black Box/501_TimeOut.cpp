#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

	int case_num;

	cin >> case_num;

	for(int i=0; i<case_num; i++){
		int M = 0, N = 0;
		queue<int> A_q;
		vector<int> u_q, black_box;

		cin >> M >> N;
		for(int j=0; j<M; j++){
			int temp = 0;
			cin >> temp;
			A_q.push(temp);
		}
		for(int j=0; j<N; j++){
			int temp = 0;
			cin >> temp;
			u_q.push_back(temp);
		}

		for(int j=0; j<u_q.size(); j++){
			bool if_sort = false;

			while(!A_q.empty()){
				bool if_out=false;

				black_box.push_back(A_q.front());
				A_q.pop();
				if_sort = false;

				while(black_box.size() == u_q[j]){
					if(!if_sort){
						sort(black_box.begin(), black_box.end());
						if_sort = true;
					}
					cout << black_box[j] << endl;
					if_out = true;
					if(u_q[j] == u_q[j+1] && j != u_q.size()-1){
						j++;
					}else{
						break;
					}
				}
				if(if_out)
					break;
			}
		}
		cout << endl;
	}
}

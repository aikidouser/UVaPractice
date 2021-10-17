#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int swap = 0, N = 0;
	vector<int> seq;
	vector<string> outputs;

	while(cin >> N && N){
		swap = 0;
		
		for(int i=0; i<N; i++){
			int temp = 0;
			
			cin >> temp;
			seq.push_back(temp);
		}
		for(int p_seq=1; p_seq<N; p_seq += p_seq){
			vector<int> seqb(N);
			
			for(int start = 0; start<N; start += 2*p_seq){
				int start1 = start, start2 = min(start + p_seq, N), seq_end = min(start + p_seq * 2, N);
				int end_1 = start2, end_2 = seq_end;
				int k = start;

				while(start1 < end_1 && start2 < end_2){
					if(seq[start1] < seq[start2]){
						seqb[k++] = seq[start1++];
					
					}else if(seq[start1] > seq[start2]){
						swap += end_1 - start1;
						seqb[k++] = seq[start2++];
					}
				}
				while(start1 < end_1){
					seqb[k++] = seq[start1++];
				}
				while(start2 < end_2){
					seqb[k++] = seq[start2++];
				}
			}
			seq = seqb;
		}
		if(swap & 1)
			cout << "Marcelo" << endl;
			// outputs.push_back("Marcelo");
			
		else
			// outputs.push_back("Carlos");
			cout << "Carlos" << endl;
		seq.clear();
	}
	// for(auto i : outputs)
		// cout << i << endl;
	// while(true){};
	return 0;
}
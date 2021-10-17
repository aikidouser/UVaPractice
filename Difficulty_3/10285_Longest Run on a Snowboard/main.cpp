#include <iostream>
#include <vector>

using namespace std;

int max_run;
vector<vector<int>> run_table;

int longest_run(vector<vector<int>> height, int i, int j){
	int local_max = 0;
	
	// printf("i: %d, j: %d\n", i, j);
	
	if(i-1 >= 0){
		if(!run_table[i-1][j] && height[i][j] > height[i-1][j]){
			longest_run(height, i-1, j);
		}
		if(height[i][j] > height[i-1][j]){
			if(local_max < run_table[i-1][j]){
				local_max = run_table[i-1][j];
			}
		}
	}
	if(j-1 >= 0){
		if(!run_table[i][j-1] && height[i][j] > height[i][j-1]){
			longest_run(height, i, j-1);
		}
		if(height[i][j] > height[i][j-1]){
			if(local_max < run_table[i][j-1]){
				local_max = run_table[i][j-1];
			}
		}			
	}	
	if(i+1 < height.size()){
		if(!run_table[i+1][j] && height[i][j] > height[i+1][j]){
			longest_run(height, i+1, j);
		}
		if(height[i][j] > height[i+1][j]){
			if(local_max < run_table[i+1][j]){
				local_max = run_table[i+1][j];
			}
		}
	}
	if(j+1 < height[0].size()){
		if(!run_table[i][j+1] && height[i][j] > height[i][j+1]){
			longest_run(height, i, j+1);
		}
		if(height[i][j] > height[i][j+1]){
			if(local_max < run_table[i][j+1]){
				local_max = run_table[i][j+1];
			}
		}
	}
	run_table[i][j] = local_max + 1;
	// printf("runtable[%d][%d] = %d\n", i, j, run_table[i][j]);
	// for(auto x : run_table){
		// for(auto y : x)
			// cout << y << " ";
		// cout << endl;
	// }
	
	return run_table[i][j];
}

int main(){
	
	int num_case;
	vector<int> temp;
	vector<vector<int>> height;
	
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	
	cin >> num_case;
	while(num_case--){
		// cout << "case: " << num_case << endl;
		
		int R, C;
		max_run = -1;
		string name;
		
		cin >> name >> R >> C;
		vector<int> init_vector(5, 0);
		run_table.resize(R);
		height.resize(R);
		
		for(int i=0; i<R; i++){
			run_table[i].clear();
			// run_table[i].assign(init_vector.begin(), init_vector.end());
			run_table[i].resize(C, 0);
			for(int j=0; j<C; j++){
				int h;
				
				cin >> h;
				temp.push_back(h);
			}
			height[i].assign(temp.begin(), temp.end());
			temp.clear();
		}
		// cout << name;
		// cout << " finish input" << endl;

		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				if(!run_table[i][j]){
					// cout << "ready to start" << endl;
					longest_run(height, i, j);
				}
				if(run_table[i][j] > max_run)
					max_run = run_table[i][j];
			}
		}
		// cout << "finish" << endl;
		cout << name << ": " << max_run << endl;
	}
	// fclose(stdin);
	// fclose(stdout);
	return 0;
}
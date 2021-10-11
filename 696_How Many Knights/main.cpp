#include <iostream>

using namespace std;

int main(){
	
	int M_rows = 0, N_columns = 0;
	
	while(cin >> M_rows >> N_columns && (M_rows || N_columns)){
		int knights_num = 0;
		
		// M or N == 0
		if(!(M_rows || N_columns)){
			
			knights_num = 0;
		
		}else if(M_rows == 1 || N_columns == 1){
			knights_num = M_rows + N_columns - 1;
		
		}else if(M_rows == 2 || N_columns == 2){
			int l=0;
			
			if(M_rows == 2)
				l = N_columns;
			else
				l = M_rows;
			
			if(l % 4 == 1){
				knights_num = 2 + 4 * (l / 4);
			
			}else{
				if(l % 4 == 0)
					knights_num = 4 + 4 * (l / 4 - 1);
				else
					knights_num = 4 + 4 * (l / 4);
			}
		}else{
			knights_num = (M_rows * N_columns + 1) / 2;
		}
		printf("%d knights may be placed on a %d row %d column board.\n", knights_num, M_rows, N_columns);
	}
	return 0;
}
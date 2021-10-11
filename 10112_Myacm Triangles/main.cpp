#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct point{
	char label;
	int x, y;
};

float area_calculate(point p1, point p2, point p3){
	return abs(0.5 * ((p3.y - p1.y)*(p2.x - p1.x) - (p2.y - p1.y)*(p3.x - p1.x)));
}

bool check_if_in(point test_p, point p1, point p2, point p3, int area){
	int test_area = 0;
	
	test_area = area_calculate(test_p, p1, p2)
				+ area_calculate(test_p, p2, p3)
				+ area_calculate(test_p, p3, p1);
	
	// cout << test_area << " " << area << endl;
	if(test_area == area)
		return true;
	else
		return false;
}

int main(){
	int monu_num = 0;
	vector<string> outputs;
	
	while(cin >> monu_num && monu_num){
		float max_area = -1;
		string output = "";
		vector<point> monuments;
		
		for(int i=0; i<monu_num; i++){
			point temp;
			
			cin >> temp.label >> temp.x >> temp.y;
			monuments.push_back(temp);
		}
		
		for(int i=0; i<monu_num; i++){
			for(int j=i+1; j<monu_num; j++){
				for(int k=j+1; k<monu_num; k++){
					float area = 0;
					bool if_inside = false;
					
					area = area_calculate(monuments[i], monuments[j], monuments[k]);
					// cout << monuments[i].label << monuments[j].label << monuments[k].label << " area: " << area << endl;
					
					if(area > max_area){
						// cout << "area: " << area << " > max_area: " << max_area << endl;
						for(int l=0; l<monu_num; l++){
							if(l == i || l == j || l == k)
								continue;
							
							// cout << "check l: " << monuments[l].label << endl;
							if(check_if_in(monuments[l], monuments[i], monuments[j], monuments[k], area)){
								// cout << check_if_in << endl;
								if_inside = true;
								break;
							}
						}
						if(!if_inside){
							// cout << "!if_inside" << endl;
							max_area = area;
							output.clear();
							output.push_back(monuments[i].label);
							output.push_back(monuments[j].label);
							output.push_back(monuments[k].label);
							// cout << output << endl;
						}
					}
				}
			}
		}
		cout << output << endl;
		outputs.push_back(output);
	}
	return 0;
}
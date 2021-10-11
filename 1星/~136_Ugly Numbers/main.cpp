// UVa 136 Ugly Numbers
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <functional>

using namespace std;

int main(){
    freopen("output.txt", "w", stdout);

    int n2, n3, n5, smallest = 0;
    set<unsigned long long> check;
    priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long> > pq;

    pq.push(1);
    check.insert(1);
    for (int i=0; i<1500; i++){
        smallest = pq.top();
        pq.pop();
        n2 = smallest * 2;
        n3 = smallest * 3;
        n5 = smallest * 5;

        if(!check.count(n2)){
            pq.push(n2);
            check.insert(n2);
        }
        if(!check.count(n3)){
            pq.push(n3);
            check.insert(n3);
        }
        if(!check.count(n5)){
            pq.push(n5);
            check.insert(n5);
        }
    }
    cout << "The 1500'th ugly number is " << smallest << "." << endl;
    fclose(stdout);

    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int D[9];
	for(int i=0; i<9; ++i)
		cin>>D[i]; 
	
	sort(D,D+9);
	
	int sum = 0;
	for(auto i:D)
		sum += i;
	
	for(int i=0; i<9; ++i){
		for(int j=0; j<9; ++j){
			if(sum-D[i]-D[j] == 100){
				for(int k=0; k<9; ++k)
					if(k!=i && k!=j) cout << D[k] << '\n'; 
				return 0; 
			}
		}
	}
	
	
	return 0;
}
	

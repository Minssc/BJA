#include<iostream>
#include<string>
using namespace std;

short ARR[1001][1001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	string A,B;
	cin>>A>>B; 
	
	int M = 0;
	for(int i=0; i<A.size(); ++i){
		for(int j=0; j<B.size(); ++j){
			if(A[i] == B[j])
				ARR[i+1][j+1] = ARR[i][j]+1; 
			else
				ARR[i+1][j+1] = max(ARR[i][j+1], ARR[i+1][j]); 
			
			if(ARR[i+1][j+1]>M)
				M = ARR[i+1][j+1]; 
		}
	}
	
	cout<<M; 

	
	return 0;
}

#include<iostream>
using namespace std;
int D[10][1001]; 

int main(){
	int N; cin>>N; 
	for(int i=0; i<10; ++i) D[i][1] = 1; 
	
	for(int i=2; i<=N; ++i){
		for(int j=0; j<10; ++j){
			for(int k=j; k<10; ++k){
				D[j][i] += D[k][i-1];
				D[j][i] %= 10007; 		
			}
		}
	}
	
	int sum = 0;
	for(int i=0; i<10; ++i) sum += D[i][N];
	cout<<sum%10007;
	
	return 0;
}
/*=2
0 1 2 3 4 5 6 7 8 9 
11 12 13 14 15 16 17 18 19 
22 23 24 25 26 27 28 29
33 34 35 36 37 38 39 
 
*/

#include<iostream>
using namespace std;

int P[1001]; 
int D[1001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N;	
	cin>>N;
	for(int i=1; i<=N; ++i)
		cin>>P[i]; 
		
	D[1] = P[1];

	for(int i=2; i<=N; ++i){
		D[i] = max(D[i-1]+D[1], P[i]);
		P[i] = D[i]; 
	}
	
	for(int i=1; i<=N; ++i)
		cout<<D[i]<< ' ';
	
	cout<<D[N]; 
	
	
	return 0;
}
/*
5
10 9 8 7 6

11111	50
122		28
113		28
23		17
14		17
5		6

D[1] = P[1]
D[2] = max(2*D[1], P[2]);
D[3] = max(D[1]+D[2], P[3]); 
D[4] = max(D[1]+D[3],P[4]); 

*/

#include<iostream>
#include<algorithm>
using namespace std;
int D[50]; 
int P[10]; 
int N;

void pickNum(int a, int c){
	P[c] = D[a]; 
	if(c==6){
		for(int i=1; i<=6; ++i)
			cout << P[i] << ' ';
		cout<<'\n'; 
		return;	
	}
	for(int i=a+1; i<N; ++i)
		pickNum(i,c+1); 
	
	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	
	while(true){
		cin>>N;
		if(!N) break; 
		for(int i=0; i<N; ++i)
			cin>>D[i]; 
		sort(D,D+N); 
		
		for(int i=0; i<N; ++i)
			pickNum(i, 1);
		cout<<'\n';
	}

	
	return 0;
}

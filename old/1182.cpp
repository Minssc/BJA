#include<iostream>
using namespace std;
int N,S;
int D[22]; 
int CNT; 

void pickMe(int idx, int sum, int cnt){
	if(idx>N)
		return;
	if(cnt && sum==S)
		CNT++; 
		
	pickMe(idx+1, sum, 0);
	pickMe(idx+1, sum+D[idx], 1); 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	cin>>N>>S; 
	for(int i=0; i<N; ++i)
		cin>>D[i];
	
	pickMe(0, 0, 0);
	
	cout<<CNT; 
	return 0;
}

#include<iostream>
#include<deque>

using namespace std;
deque<int> D[4]; 
bool S[4]; 

void spin(int n, int d){
	if(n<0 || n>=4 || S[n]) return; 
	S[n] = 1; 
	
	if(n+1<4 && D[n][2] != D[n+1][6]) spin(n+1, -d); 
	if(n-1>=0 && D[n][6] != D[n-1][2]) spin(n-1, -d); 
	
	if(d==1) D[n].push_front(D[n].back()), D[n].pop_back();	
	else D[n].push_back(D[n].front()), D[n].pop_front();
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	for(int i=0; i<4; ++i){
		int v; cin>>v; 
		for(int j=0; j<8; ++j){
			D[i].push_front(v&1);
			v/=10; 	
		}
	}
	
	int k; cin>>k;
	for(int i=0; i<k; ++i){
		int a, b; cin>>a>>b;
		spin(a-1,b); 		
		for(int j=0; j<4; ++j) S[j] = 0;  
	}
	
	int score = 1; 
	int result = 0; 
	for(int i=0; i<4; ++i){
		if(D[i][0]) result += score; 
		score*=2; 
	}
	cout<<result; 
	
	return 0;
}


#include<iostream>
using namespace std;

int D[12]; 
int DD[5]; 
int MAX=-1234567890,MIN=1234567890; 
int S[12]; 
int N;

void dfs(int type, int cnt){
	if(DD[type]<=0) return; 
	DD[type]--; 
	S[cnt] = type; 
	
	if(cnt==N-1){
		int lv = D[0]; 
		for(int i=1; i<=N-1; ++i){
			switch(S[i]){
				case 0: // +
				lv = lv + D[i]; 
				break;
				case 1: // -
				lv = lv - D[i]; 
				break;
				case 2: // x
				lv = lv * D[i]; 
				break;
				case 3: // /
				lv = lv / D[i]; 
			}
		}
		if(lv>MAX)
			MAX = lv;
		if(lv<MIN)
			MIN = lv; 
	//	cout << MAX << "/" << MIN << endl; 
	}
	else{
		for(int i=0; i<4; ++i)
			dfs(i, cnt+1); 
	}	
	
	DD[type]++; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=0; i<N; ++i)
		cin>>D[i]; 
		
	for(int i=0; i<4; ++i)
		cin>>DD[i]; 
	
	for(int i=0; i<4; ++i)
		dfs(i,1); 
	
	cout<<MAX<<'\n';
	cout<<MIN<<'\n'; 
	
	return 0;
}

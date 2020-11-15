#include<iostream>
#include<algorithm>
using namespace std;

int S[22][22]; 
int T1[11];
int T2[11]; 
int N;
int MDIFF = 1234567890;

void dfs(int cidx, int cnt){
	if(cidx > N) return; 
	if(cnt == N/2){
		int sum = 0; 
		for(int i=0; i<N/2; ++i)
			for(int j=i+1; j<N/2; ++j)
				sum += S[T1[i]][T1[j]] + S[T1[j]][T1[i]];
		
		int t2i = 0;
		for(int i=1; i<=N; ++i){
			int *f = find(T1, T1+N/2, i);
			if(f==T1+N/2)
				T2[t2i++] = i;
		}
		int sum2 = 0; 
		for(int i=0; i<N/2; ++i)
			for(int j=i+1; j<N/2; ++j)
				sum2 += S[T2[i]][T2[j]] + S[T2[j]][T2[i]];
		
		MDIFF = min(abs(sum2-sum),MDIFF);
		return; 	
	}
	
	T1[cnt] = cidx+1;
	dfs(cidx+1, cnt+1);
	dfs(cidx+1, cnt);
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=1; i<=N; ++i) for(int j=1; j<=N; ++j)
		cin>>S[i][j]; 	
	
	
	dfs(0,0);
	
	cout<<MDIFF<<endl;	
	
	return 0;
}

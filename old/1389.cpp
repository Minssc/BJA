#include<iostream>

using namespace std;
int N,M; 
int D[101][101]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M; 
	for(int i=0; i<M; ++i){
		int a,b; cin>>a>>b; a--,b--; 
		D[a][b]=1,D[b][a]=1; 	
	}
	
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			for(int k=0; k<N; ++k)
				if(D[j][i]&&D[i][k])
					if(!D[j][k]) D[j][k]=D[j][i]+D[i][k]; 
					else D[j][k]=min(D[j][k],D[j][i]+D[i][k]); 
				
	int mkbv=123456789, ans=0; 
	for(int i=0; i<N; ++i){
		int kbv=0; 
		for(int j=0; j<N; ++j)
			if(i!=j) kbv+=D[i][j]; 	
		
		if(kbv<mkbv){
			ans=i; 
			mkbv=kbv; 	
		}
	}
	
	cout<<ans+1; 
	
	return 0;
}


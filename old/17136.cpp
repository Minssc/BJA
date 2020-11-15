#include<iostream>

using namespace std;
const int N=10; 
int D[11][11]; 
int P[6]; 
int ANS=1234567890,T; 

void place(int r, int c){
	if(c==N&&r==N){
		ANS=min(ANS,T);
		return; 
	}else if(c==N){
		place(r+1,0);
		return; 
	}else if(!D[r][c]){
		place(r,c+1);
		return; 	
	}
	
	for(int s=5; s>=1; --s){
		if(P[s]>=5||r+s>N||c+s>N) continue; 
			
		if(!([&](){
			for(int i=0; i<s; ++i)
				for(int j=0; j<s; ++j)
					if(!D[r+i][c+j]) return false; 
			return true; 
		}())) continue; 
		
		for(int i=0; i<s; ++i) for(int j=0; j<s; ++j) D[r+i][c+j]=0; 
		P[s]++, T++;
		
		place(r,c+s); 
		
		for(int i=0; i<s; ++i) for(int j=0; j<s; ++j) D[r+i][c+j]=1; 
		P[s]--, T--; 
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) cin>>D[i][j]; 
	
	place(0,0); 
	
	if(ANS==1234567890) cout<<-1<<'\n';
	else cout<<ANS<<'\n'; 
	return 0;
}


#include<iostream>
#include<algorithm>

using namespace std;
int L,C; 
char D[16]; 
char P[16];
bool V[16];  

void solve(int lidx, int cnt){
	if(cnt==L){
		int aeiou=0; 
		for(int i=0;i<L;++i)
			if(P[i]=='a'||P[i]=='e'||P[i]=='i'||P[i]=='o'||P[i]=='u') aeiou++;
		
		if(aeiou>=1&&(L-aeiou)>=2){ 
			for(int i=0; i<L; ++i)
				cout<<P[i];
			cout<<'\n'; 
		}
		return;
	}
	for(int i=lidx; i<C; ++i){
		if(V[i]) continue; 
		V[i]=1; P[cnt]=D[i];
		solve(i+1,cnt+1); 
		V[i]=0; P[cnt]=0; 
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>L>>C; 
	for(int i=0; i<C; ++i) cin>>D[i]; 
	sort(D,D+C); 
	
	solve(0,0); 
	return 0;
}


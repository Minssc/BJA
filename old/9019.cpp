#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cstring>

#define MF_D(x) ((2*x)%10000)
#define MF_S(x) (((x-1)<0)?9999:(x-1))
#define MF_L(x) ((x/1000+x*10)%10000)
#define MF_R(x) ((x%10)*1000+(x/10))
#define pis pair<int,string> 

using namespace std;
int A,B; 
bool V[10001]; 

void solve(){
	memset(V,0,sizeof(V)); 
	cin>>A>>B; 
	
	queue<pis> Q; 
	Q.push({A,""}); 
	V[A]=1; 
	
	while(!Q.empty()){
		auto n=Q.front(); Q.pop();
		
		int t=0; 
		for(auto i:{MF_D(n.first),MF_S(n.first),MF_L(n.first),MF_R(n.first)}){
			t++; 
			if(V[i]) continue; 
			V[i]=1; 
			string ns=n.second; 
			if(t==1) ns+='D';
			else if(t==2) ns+='S';
			else if(t==3) ns+='L';
			else if(t==4) ns+='R'; 
				
			if(i==B){
				cout<<ns<<'\n'; ; 
				return; 	
			}
			Q.push({i,ns}); 
		}
	} 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int tc; cin>>tc; 
	for(int t=0; t<tc; ++t)
		solve(); 
	
	return 0;
}


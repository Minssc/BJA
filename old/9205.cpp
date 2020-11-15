#include<iostream>
#include<queue> 
#include<cstring> 

using namespace std;

struct point{
	int r,c; 	
	
	int dist(const point &t){
		return (abs(r-t.r)+abs(c-t.c)); 	
	}
	
	bool operator==(const point &t) const{
		return r==t.r&&c==t.c; 	
	}
};

point D[101]; 
bool V[101]; 
point HOME,TARG; 

void solve(){
	int n; cin>>n; 
	cin>>HOME.r>>HOME.c;
	for(int i=0; i<n; ++i) cin>>D[i].r>>D[i].c; 
	cin>>TARG.r>>TARG.c; 
	D[n++]=TARG; 
	memset(V,0,sizeof(V));
		
	queue<point> Q; 
	Q.push(HOME); 
	
	while(!Q.empty()){
		point p=Q.front(); Q.pop(); 
		if(p==TARG){
			cout<<"happy"<<'\n'; 
			return; 	
		}
		
		for(int i=0; i<n; ++i){
			point &np=D[i]; 
			if(!V[i]){
				if(p.dist(np)<=20*50){
					V[i]=1; 
					Q.push(np); 
				}
			}
		}
	}
	
	cout<<"sad"<<'\n'; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int tc; cin>>tc;
	for(int t=0; t<tc; ++t)
		solve(); 
	
	return 0;
}


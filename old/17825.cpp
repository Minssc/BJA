#include<iostream>
#include<vector>

using namespace std;
int N=10;
int D[10]; 
int maxv; 
int P[10]; 

struct horse{
	int p, t;
	bool fin;  		
};

vector<int> B[4] = {
	{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40},
	{0,2,4,6,8,10,13,16,19,25,30,35,40},
	{0,2,4,6,8,10,12,14,16,18,20,22,24,25,30,35,40},
	{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,28,27,26,25,30,35,40}	
};

int sim(){
	horse Horse[4] = {}; 
	int ssum = 0; 
	for(int i=0; i<N; ++i){
		auto &h = Horse[P[i]-1]; 
		if(h.fin) continue; 
		h.p+=D[i]; 
		if(h.p>=B[h.t].size()){
			h.fin=B[h.t].size()-1; 
			h.fin = true; 
			continue; 
		}
		
		int score = B[h.t][h.p]; 
		
		if(score==10) h.t=1;
		else if(score==20) h.t=2;
		else if(h.t==0&&score==30) h.t=3; 
		
		for(int j=1; j<=4; ++j){
			if(P[i]==j) continue; 
			auto &hh = Horse[j-1]; 
			if(score==25||score==35||score==40){
				if(score==B[hh.t][hh.p]) return 0; 	
			}else if(score==30||score==28||score==26||score==22||score==24){
				if(h.t==hh.t && h.p==hh.p) return 0; 
			}else if(score==B[hh.t][hh.p]&&!hh.fin) return 0; 
		}
		ssum+=score; 
	}
	return ssum; 
}

void pick(int idx){
	if(idx>9){
		maxv = max(maxv,sim()); 
	}else{
		for(int i=1; i<=4; ++i){
			P[idx]=i;
			pick(idx+1); 
			P[idx]=0;	
		}
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	for(int i=0; i<N; ++i) cin>>D[i]; 
	
	pick(0); 
	cout<<maxv;
    
	return 0;
}


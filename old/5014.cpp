#include<iostream>
#include<queue>
using namespace std;
int F,S,G,U,D;
int C[10000001]; 

void bfs(){
	queue<int> Q;
	Q.push(S);
	C[S] = 1; 
	
	while(!Q.empty()){
		int f = Q.front();Q.pop(); 
		for(auto &i:{U,-D}){
			int nf = f+i;	
			if(nf == G){
				cout<<C[f];
				return;	
			}
			if(C[nf] || nf>F || nf<=0) continue; 
			C[nf] = C[f]+1; 
			Q.push(nf);	
		}
	}
	cout<<"use the stairs"; 
}

int main(){
	cin>>F>>S>>G>>U>>D;
	if(S==G){
		cout<<0;
		return 0; 
	}
	bfs(); 
	return 0;
}

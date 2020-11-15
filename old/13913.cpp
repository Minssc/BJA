#include<iostream>
#include<queue> 
#include<vector> 

using namespace std;
int N,K; 
int D[100001]; 
int T[100001]; 

void chase(){
	queue<int> Q; 
	Q.push(N); 
	D[N]=1; 
	T[N]=-1;
	
	while(!Q.empty()){	
		auto p=Q.front(); Q.pop(); 
		for(auto i:{1,-1,p}){
			int np=p+i; 
			if(np<0||np>100000||D[np]) continue; 	
			D[np]=D[p]+1; 
			T[np]=p; 
			
			Q.push(np); 
		}
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>K;
	chase(); 
	
	vector<int> v; 
	int cur=K; 
	do{
		v.push_back(cur); 
	}while((cur=T[cur])!=-1); 
	
	cout<<D[K]-1<<'\n'; 
	for(auto rit=v.rbegin();rit!=v.rend();++rit)
		cout<<*rit<<' ';
	return 0;
}


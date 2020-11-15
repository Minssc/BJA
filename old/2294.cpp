#include<iostream>
#include<queue>
#include<set>
//#include<algorithm>
using namespace std;

int N,K;
//int D
//int D[101]; 
set<int, greater<int>> D; 
int C[100001]; 
//
void bfs(){
	queue<int> Q;
	for(auto it=D.begin(); it!= D.end(); ++it){
		Q.push(*it);
		C[*it] = 1; 	
	}
	
	while(!Q.empty()){
		auto n = Q.front(); Q.pop(); 	
		
		for(auto it=D.begin(); it!= D.end(); ++it){
			auto nn = n+*it; 
			if(nn>K) continue; 
			if(C[nn] && C[nn] <= C[n] + 1) continue; 
			C[nn] = C[n]+1;
//			if(nn = K)
//				return;  
			Q.push(nn);  	
			
		}
	}
}
//
//int dp(int x){
//	if(D[x]) return D[x]; 
//	else{
//			
//		
//	}
//}


int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>K; 
	for(int i=0; i<N; ++i){
		int a; cin>>a; 
		D.insert(a); 	
	}
	bfs(); 
//	for(int i=1; i<=K; ++i)
//		cout << C[i]<< ' '; 
	cout<<(C[K] ? C[K] : -1); 
//	sort(D,D+N,greater<int>()); 
//	
//	int cnt = 0; 
//	for(int i=0; i<N; ++i){
//		cnt += K/D[i]; 
//		K %= D[i]; 
//	}
//	
//	cout << cnt;
	return 0;
}

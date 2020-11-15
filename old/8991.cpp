#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
bool D[10001][10001]; 
bool CR[10001]; 
bool CL[10001]; 

void solution(){
	int N,M; cin>>N>>M; 
	memset(CR,0,sizeof(CR));
	memset(CL,0,sizeof(CL));
	memset(D,0,sizeof(D)); 
	
	for(int i=0; i<M; ++i){
		int student, nvote; cin>>student>>nvote;
//		core.push_back(student); 
		CR[student] = 1; 
		for(int j=0; j<nvote; ++j){
			int vote; cin>>vote; 
//			D[student].push_back(vote); 
			D[student][vote] = 1; 
		}
	}
	
//	for(auto &i:core){ //check if i liked someone outside the core
//		for(auto &ii:D[i]){
//			if(find(core.begin(), 	
//			
//		}
//	}
//	for(int i=1; i<=N; ++i)
//		if(CR[i])
//			cout<< i << " is a core\n"; 
	for(int i=1; i<=N; ++i){
		if(!CR[i]) continue; 
		for(int j=1; j<=N; ++j){
			if(!D[i][j]) continue; 
			if(!CR[j]){
				CR[i] = 0; 
				break;
			}
		}
	}
//	cout<<"AFTER "<<'\n';
//	for(int i=1; i<=N; ++i)
//		if(CR[i])
//			cout<< i << " is a core\n"; 
			

	for(int i=1; i<=N; ++i){
		if(!CR[i]) continue; 
		for(int j=1; j<=N; ++j){
			if(!D[i][j]) continue;
			if(CL[i]) continue; 
			if(D[j][i]){
				CL[i] = 1; 
				for(int k=1; k<=N; ++k){
					if(!D[i][k]) continue; 
					CL[k] = 1; 	
				}
				break;
			}
		}
		if(!CL[i])
			CR[i] = 0; 
	}
	
//	cout<<"AFTER "<<'\n';
//	for(int i=1; i<=N; ++i)
//		if(CR[i])
//			cout<< i << " is a core\n"; 
	int sum = 0; 
	for(int i=1; i<=N; ++i) if(CR[i]) sum++;
	cout<<sum<<'\n'; 
//		cout << i << " has voted" << '\n'; 	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	int T;cin>>T;
	for(int t=1; t<=T; ++t)
		solution();
	
	return 0;
}

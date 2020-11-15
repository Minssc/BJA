#include<iostream>
#include<stack>
using namespace std;
int D[500001]; 
int C[500001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N; cin>>N; 
	for(int i=1; i<=N; ++i) cin>>D[i]; 
	D[0] = 1234567890; 
	stack<int> ST; 
	int M = 1234567890;
	
	for(int i=N; i>=0; --i){
		while(!ST.empty()){
			int t = ST.top();
			if(D[i]>D[t]){
				D[t] = i; 
				ST.pop(); 
			}else
				break; 
		}
		
		ST.push(i); 
	}
	for(int i=1; i<=N; ++i)
		cout<<D[i] <<' ';
	cout<<'\n'; 
	
	return 0;
}

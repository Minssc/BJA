#include<iostream>
#include<stack>
#include<string>
using namespace std;
int D[100001]; 

int main(){
	cin.tie(0),ios_base::sync_with_stdio(0);
	int N; cin>>N;
	for(int i=0; i<N; ++i) cin>>D[i]; 
	stack<int> ST;
	string S = "";
	int idx = 1;
	for(int i=0; i<N; ++i){
		if(idx<=D[i])
			for(int j=idx; j<=D[i]; ++j){
				ST.push(idx++);
				S+='+'; 
			}
		
		if(!ST.empty() && ST.top() == D[i]){
			ST.pop();
			S+='-';	
		}
	}
	
	if(ST.empty())
		for(auto &c:S)
			cout<<c<<'\n';
	else
		cout<<"NO";
	
	return 0;
}

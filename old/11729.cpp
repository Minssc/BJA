#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> PV; 

void hanoi(int n, int from, int via, int to){
	if(n==1) PV.push_back(make_pair(from,to));
	else{
		hanoi(n-1, from, to, via);
		PV.push_back(make_pair(from, to));
		hanoi(n-1, via, from, to); 
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	int N;
	cin>>N; 
	hanoi(N,1,2,3); 
	
	cout<< PV.size() << '\n'; 
	for(auto p:PV)
		cout << p.first << ' ' << p.second << '\n'; 
	
	
	return 0;	
}

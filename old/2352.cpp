#include<iostream>
#include<vector>
using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int N,D;
	cin>>N;
	vector<int> V;;
	//cin>>V;
	cin>>D;
	V.push_back(D); 
	
	for(int i=1; i<N; ++i){
		int D;
		cin>>D; 
		
		if(V.back() < D)
			V.push_back(D);
		else
			*lower_bound(V.begin(), V.end(), D) = D; 
	}

	cout<<V.size(); 
	
	return 0;
}

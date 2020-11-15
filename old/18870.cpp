#include<iostream>
#include<vector> 
#include<algorithm>
#include<set>

using namespace std;
int N;
int D[1000001]; 
vector<int> GV;
set<int> ST; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=0; i<N; ++i){
		cin>>D[i];
		GV.push_back(D[i]); 
//		ST.insert(D[i]); 
//		if(ST.find(D[i])==ST.end()){
//			ST.insert(D[i]);  
//			GV.push_back(D[i]); 
//		}
	}
	
//	GV.assign(ST.begin(),ST.end()); 
	sort(GV.begin(),GV.end()); 
	GV.erase(unique(GV.begin(),GV.end()),GV.end()); 
	
	for(int i=0; i<N; ++i)
		cout<<lower_bound(GV.begin(),GV.end(),D[i])-GV.begin()<<' ';
	
	
	// cout<<distance(ST.begin(),ST.find(D[i]))<<' '; 
	
	return 0;
}


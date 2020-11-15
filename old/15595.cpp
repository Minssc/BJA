#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<iomanip>
using namespace std;
int N;
unordered_map<string, int> GM; 
unordered_set<string> OK; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N; 
	for(int i=0; i<N; ++i){
		int nid,res,mem,time,lang,leng;
		string uid;
		cin>>nid>>uid>>res>>mem>>time>>lang>>leng; 
		if(uid=="megalusion") continue; 
		
		if(res==4) OK.insert(uid); 
		else if(OK.find(uid)==OK.end()) GM[uid]++; 
	}
	int s=OK.size();
	
	if(s){
		int sum = 0; 
		for(auto &p:GM)
			if(OK.find(p.first)!=OK.end()) sum+=p.second; 	
		
		cout<<setprecision(16)<<(double)s/(s+sum)*100<<'\n'; 
	}else
		cout<<0; 
	
	return 0;
}


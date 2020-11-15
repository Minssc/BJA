#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	string t,p; 
	getline(cin,t), getline(cin,p);  
	vector<int> result;
	
	int phash=0, thash=0, m=1; 
	for(int i=0, tn=t.size(), pn=p.size(); i<=tn-pn; ++i){
		if(i==0){
			for(int j=0; j<pn; ++j){
				thash+=t[j]*m;
				phash+=p[j]*m;
				if(j<pn-1) m*=2; 
			}	
		}else thash = 2*(thash-t[i])+t[pn+i]*m;
		cout<<phash<<','<<thash<<'\n'; 
		if(phash == thash){
			bool found = true; 
			for(int j=0; j<pn; ++j){
				if(t[i+j] != p[j]){
					found = false;
					break; 	
				}
			}
			
			if(found) result.push_back(i+1); 
		}
	}
	
	cout<<result.size()<<'\n';
	for(auto &i:result)
		cout<<i<<'\n'; 
	return 0;
}


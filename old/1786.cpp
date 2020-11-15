#include<iostream>
#include<string>
#include<vector>
using namespace std;
int KMPT[1000001]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	string T,P; 
	getline(cin,T), getline(cin,P); 
	
	for(int i=1, j=0, pn = P.size(); i<pn; ++i){
		while(j>0 && P[i] != P[j]) j = KMPT[j-1];
		if(P[i]==P[j]) KMPT[i] = ++j; 	
	}
	
	vector<int> result;
	for(int i=0,j=0; i<T.size(); ++i){
		while(j>0 && T[i] != P[j]) j = KMPT[j-1];
		
		if(T[i] == P[j]){
			if(j==P.size()-1){
				result.push_back(i-P.size()+2); 
				j=KMPT[j]; 	
			}else
				j++; 
		}
	}
	
	cout<<result.size()<<'\n';
	for(auto &i:result)
		cout<<i<<'\n'; 
	return 0;
}


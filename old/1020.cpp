#include<iostream>
#include<vector>
using namespace std;
// 1 000 000 000 000 000 000 
//2 3 4 5 5 5 5 6 6 7 
/*

*/
int nPlus[10] = {6,2,5,5,4,5,6,3,7,5}; 
vector<int> OV,NV;

int minNext(int tv, int clen){
	if(tv<clen*2 || tv>clen*7) return 0; 
	int val = 1;
	int ctv = 0; 
	int cv = -1; 
	for(int i=0; i<clen; ++i){
		for(int j=0; j<10; ++j)
			if(ctv - nPlus[j] >= 2){ 	
				cv = j;
				break; 
			}
			
		if(cv == -1) return 0; // no candidate 
		ctv -= nPlus[cv]; 
		
		
		val*=10; 	
	}
	return 0; 
}

int main(){
	char c;
	while(cin>>c) OV.push_back(c-'0'); 
	
	for(int i=OV.back()+1; i<10; ++i){
		if(nPlus[i] == nPlus[OV.back()]){
			cout<<i-OV.back()<<'\n'; 
			return 0; 
		}
	}
	int tv = 0; 
	for(auto &i:OV)
		tv += nPlus[i]; 
	
//	NV = OV; 
//	int tTime = 0; 
//	for(auto it = OV.rbegin(); it!=OV.rend()-1; ++it){
//		for(auto iit = OV.rbegin(); itt!=it+1; ++iit){
//				
//		}	
//	}
	
//	cout<<tTime<<'\n'; 
	return 0;
}

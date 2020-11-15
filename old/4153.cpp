#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	
	while(true){
		int P[3]; 
		for(int i=0; i<3; ++i) {
			cin>>P[i]; 
			if(!P[i]) return 0; 
		}
		
		sort(P,P+3,greater<int>()); 
		if(P[0]*P[0] == (P[1]*P[1] + P[2]*P[2]))
			cout<<"right"<<'\n';
		else
			cout<<"wrong"<<'\n'; 
		
	}
	
	return 0;
}

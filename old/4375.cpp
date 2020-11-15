#include<iostream>
using namespace std;

int main(){
	int N;
//	freopen("input/4375.txt","r",stdin);
	while(cin>>N){
		int t=1;
		int cnt = 1; 
		
		while(true){
			if(t%N == 0)
				break; 	
					
			t = t*10%N+1; 
			cnt++;
		}
		
		cout<<cnt<<'\n'; 
	}
	
	return 0;	
}

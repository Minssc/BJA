#include<iostream>
using namespace std;
int M[11];
int m[11]; 

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int K;
	cin>>K;
	M[0] = 9;
	m[0] = 0; 
	
	for(int i=1; i<=K; ++i){
		char b;
		cin>>b; 
		
		if(b == '>'){
			M[i] = M[i-1]-1; 
			for(int j=i-2; j>=0; --j)
				if(M[j] == M[i])
					M[i]--; 
					
			m[i] = m[i-1];
			for(int j=i-1; j>=0; --j)
				if(m[j]>=m[j+1])
					m[j]++;
				else 
					break;
				
		}else{//<
			M[i]=M[i-1];
			M[i-1]--;
			for(int j=i-2; j>=0; --j)
				if(M[j]<=M[j+1])
					M[j]--;
				else
					break;
			
			m[i] = m[i-1]+1; 
			
			for(int j=i-2; j>=0; --j){
				if(m[j]==m[i])
					m[i]++; 	
			}
		}
		
	}
	
	for(int i=0; i<=K; ++i)
		cout<<M[i];
	cout<<'\n';
	
	for(int i=0; i<=K; ++i)
		cout<<m[i];
	cout<<'\n';
	
	return 0;
}
/*
>	<	<	<	>
> < < < >
9 5 6 7 8 4
1 0 2 3 5 4
>>>>
98765
><>
9786 
><><
97856
97856
103254

*/

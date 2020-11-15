#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 
    int N, m=1, mm=1;
    cin>>N; 
    
    for(int i=0; i<N;){
    	m = mm; 
    	
    	for(int j=0; j<N; ++j){
    		if(m)
    			cout<<'*';
			else
				cout<<' ';
				
			m = !m; 
		}
		cout<<endl; 
		if(!mm)
			i++; 
		mm = !mm; 
	}
    
    return 0; 
}

#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 
    int N, m=1;
    cin>>N; 
    
    for(int i=1; i>0; i+=m){
    	for(int j=i-1; j>0; --j)
    		cout<<' ';	
        for(int j=0; j<N*2-1-(i-1)*2;++j)
            cout<< '*';
        cout<<endl;
        if(i==N)
        	m*=-1; 
    }
    
    return 0; 
}

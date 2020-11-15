#include<iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false); 
    
    int A,B,V;
    cin>>A>>B>>V;
    if(A>=V){
    	cout<<1;
    	return 0;
    }
    
    int C = 0, cnt = 0;
    while(true){
    	C+=A;
		if(C >= V){
			cout<<endl;
			cout<< ++cnt;
			cout<<endl;
			break;
		}
		C-=B;
    	cnt++; 
    }
    /*
    5 4 9 8 13 // 3 
    */
    int N = (V-A)/(A-B);
    V -= N*(A-B);
    //cout<<"WAT"<<endl;
    while(true){
    	V-=A;
    	N++;
		if(V<=0){
			cout<< N<<endl;
			return 0; 
		}
		V+=B; 
    }
    
    
    
    //cout << ((V-A)/(A-B)) + 1;
    return 0; 
}

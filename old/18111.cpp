#include<iostream>
using namespace std;
#define nl '\n'

int D[501][501]; 
int M,N,B;

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>M>>N>>B;
	int maxh = 0, minh = 256; 
	for(int i=0; i<M; ++i) for(int j=0; j<N; ++j){
		cin>>D[i][j]; 
		maxh = max(D[i][j],maxh);
		minh = min(D[i][j],minh); 
	}
	
	int bestH=0,minT=1234567890; 
	for(int h=minh; h<=maxh; ++h){
		int r=0,p=0;
		for(int i=0; i<M; ++i){
			for(int j=0; j<N; ++j){
				if(h-D[i][j] > 0){
					p += h-D[i][j]; 
				}else{
					r += D[i][j]-h;
				}
			}
		}
		
		
		if(B+r>=p){
			if(r*2+p<=minT){
				minT = r*2+p;
				bestH = h; 	
			}
		}
	}
	
	cout<<minT<<' '<<bestH<<nl; 
	
	return 0;	
}

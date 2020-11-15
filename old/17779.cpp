#include<iostream>
#include<algorithm>

using namespace std;
int N; 
int D[21][21]; 
int mdiff = 1234567890; 

void wtf(int x, int y, int d1, int d2){
	int sum[5] = {}; 
	for(int i=1; i<=N; ++i)
		for(int j=1; j<=N; ++j)
			if(i<x+d1 && j<=y && !(i>=x&&j>=y-i+x)) sum[0]+=D[i][j];
			else if(i<=x+d2 && y<j && !(i>=x && j<=y+i-x)) sum[1]+=D[i][j];
			else if(x+d1<=i && j<y-d1+d2 && !(i<=x+d1+d2 && j>=y-d1+d2-(x+d1+d2-i))) 	sum[2]+=D[i][j];
			else if(x+d2<i && y-d1+d2<=j && !(i<=x+d1+d2&&j<=y-d1+d2+(x+d1+d2-i))) sum[3]+=D[i][j];
			else sum[4]+=D[i][j];
			
	sort(sum,sum+5);
	mdiff = min(mdiff,sum[4]-sum[0]); 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=1; i<=N; ++i) for(int j=1; j<=N; ++j) cin>>D[i][j]; 
	
	for(int x=2; x<=N-2; ++x)
		for(int y=2; y<=N-1; ++y)
			for(int d1=1; d1<=y-1&&d1<=N-x-1;++d1)
				for(int d2=1; d2<=N-y&&d2<=N-x-1;++d2)
					wtf(x,y,d1,d2); 		
	
	cout<<mdiff; 
	
	return 0;
}


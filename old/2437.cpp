#include<cstdio>
#include<algorithm>
using namespace std;

int D[1001]; 

int main(){
	//freopen("input/2437.txt","r",stdin); 
	int N;
	scanf("%d",&N); 
	for(int i=0; i<N; ++i)
		scanf("%d",&D[i]); 
	
	sort(D,D+N); 
	
	int sum = 0; 
	for(int i=0; i<=N; ++i){
		if(D[i] <= sum+1)
			sum += D[i]; 
		else
			break;	
	}
	printf("%d\n",sum+1); 
	
	return 0;
}

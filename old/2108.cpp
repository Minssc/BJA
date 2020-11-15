#include<iostream>
#include<algorithm> 
#include<vector>
#include<cmath>
using namespace std;

int COUNT[8001]; 

int main(){
	cin.tie(NULL), ios_base::sync_with_stdio(false);
	int N;
	cin>>N;
	int *A = new int[N];
	
	int sum = 0; 

	for(int i=0; i<N; ++i){
		cin>>A[i]; 
		sum += A[i]; 
		COUNT[A[i]+4000]++;
	}
	
	cout << round((double)sum / N) << '\n';
	
	sort(A, A+N);
	
	cout << A[N/2] << '\n';
	
	int mfv = A[0]+4000;
	
	vector<int> MARR;
	for(int i=0; i<8001; ++i){
		if(COUNT[i] && COUNT[i] >= COUNT[mfv]){
			if(COUNT[i] == COUNT[mfv]){
				MARR.push_back(i-4000);
			}
			else{
				MARR.clear();
				MARR.push_back(i-4000);
			}
			mfv = i; 
		}
	}
	sort(MARR.begin(),MARR.end()); 
	
	cout << (MARR.size() > 1 ? MARR[1] : MARR.front()) << '\n';
	
	cout << A[N-1] - A[0] << '\n';
	
	
	return 0;
}

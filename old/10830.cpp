#include<iostream>
#include<vector>

using namespace std;
int N;
unsigned long long B;  
vector<vector<int>> A; 

vector<vector<int>> mMat(vector<vector<int>> &a, vector<vector<int>> &b){
	vector<vector<int>> r(N,vector<int>(N,0)); 
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			for(int k=0; k<N; ++k)
				r[i][j] += a[i][k]*b[k][j]; 
			r[i][j]%=1000; 
		}
	}
	return r; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>B;
	A.resize(N,vector<int>(N)); 
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) cin>>A[i][j]; 
	
	vector<vector<int>> r(N,vector<int>(N,0)); 
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			if(i==j) r[i][j] = 1; 	
		
	while(B>0){	
		if(B%2)	r = mMat(r,A);
		A = mMat(A,A);
		B/=2; 
	}
	
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j)
			cout<<r[i][j]<<' ';
		cout<<'\n';
	}
	
	return 0;
}


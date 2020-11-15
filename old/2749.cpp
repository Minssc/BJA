#include<iostream>
#include<vector>

#define ull unsigned long long
using namespace std;

vector<vector<int>> mMat(vector<vector<int>> &a, vector<vector<int>> &b){
	vector<vector<int>> r(2,vector<int>(2,0)); 
	for(int i=0; i<2; ++i){
		for(int j=0; j<2; ++j){
			ull temp=0; 
			for(int k=0; k<2; ++k)
				temp+=(ull)a[i][k]*b[k][j];
			r[i][j]=temp%1000000; 
		}
	}
	return r; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	unsigned long long n; cin>>n;
	
	if(n<=1){
		cout<<n<<'\n'; 
		return 0; 	
	}
	
	vector<vector<int>> r={{1,0},{0,1}}; 
	vector<vector<int>> a={{1,1},{1,0}}; 
	
	while(n>0){	
		if(n%2)	r = mMat(r,a);
		a = mMat(a,a);
		n/=2; 
	}
	
	cout<<r[0][1]<<'\n'; 
	return 0;
}


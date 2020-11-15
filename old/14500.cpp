#include<iostream>
#include<vector>
using namespace std;
int N,M;
int D[501][501]; 

struct tetromino{
	int w,h;
	vector<vector<int>> d; 
	void flipdiag(){
		int temp; 
		
		for(int i=0; i<this->h; ++i){
			for(int j=0; j<this->w/2; ++j){
				temp = this->d[i][j]; 
				this->d[i][j] = this->d[i][this->w-j-1]; 
				this->d[i][this->w-j-1] = temp; 
			}
		}
	}
	
	void spin(){
		vector<vector<int>> nv(w,vector<int>(h)); 
		for(int i=0; i<this->h; ++i){
			for(int j=0; j<this->w; ++j){
//				nv[this->w-j-1][i] = this->d[i][j]; 
				nv[j][i] = this->d[i][j]; 
			}
		}
		this->d = nv; 
		int temp = this->w;
		this->w = this->h;
		this->h = temp; 
	}
	
	int add(int r, int c){
		int sum = 0; 
		for(int i=0; i<this->h; ++i){
			for(int j=0; j<this->w; ++j){
				if(this->d[i][j])
					sum += D[r+i][c+j]; 		
			}
		}
		return sum; 
	}
	
	void print(){
	
		for(int j=0; j<this->h; ++j){
			for(int k=0; k<this->w; ++k){
				cout<<this->d[j][k]<<' ';
			}
			cout<<'\n';
		}
		cout<<'\n'; 	
		
	}
};

tetromino S[5];

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M; 
	S[0].w = 2, S[0].h = 2;
	S[0].d = {{1,1},{1,1}};
	
	S[1].w = 4, S[1].h = 1;
	S[1].d = {{1,1,1,1}};
	
	S[2].w = 3, S[2].h = 2;
	S[2].d = {{1,1,1},{1,0,0}};
	
	S[3].w = 3, S[3].h = 2;
	S[3].d = {{0,1,1},{1,1,0}};
	
	S[4].w = 3, S[4].h = 2;
	S[4].d = {{1,1,1},{0,1,0}}; 
	
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) cin>>D[i][j]; 
	
	int msum = 0; 
	for(int s=0; s<5; ++s){
		auto &t = S[s]; 
		
		for(int k=0; k<4; ++k){
			for(int i=0; i<=N-t.h; ++i) for(int j=0; j<=M-t.w; ++j) msum = max(msum, t.add(i,j)); 
			t.flipdiag();
			for(int i=0; i<=N-t.h; ++i) for(int j=0; j<=M-t.w; ++j) msum = max(msum, t.add(i,j)); 
			t.spin(); 
		}
		
	}
	cout<<msum<<'\n'; 
	
	return 0;
}


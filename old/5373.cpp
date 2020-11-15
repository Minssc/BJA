#include<iostream>
#include<cstring>

using namespace std;
struct face{
	char dat[3][3]; 	
	void init(char c){
		memset(this->dat,c,sizeof(dat)); 
	}
	
	void print(){
		for(int i=0; i<3; ++i){
			for(int j=0; j<3; ++j)
				cout<<this->dat[i][j];
			cout<<'\n'; 
		}
	}
	
	void rotate(const char &dir){
		char ndat[3][3]; 
		if(dir=='+')
			for(int i=0; i<3; ++i) for(int j=0; j<3; ++j) ndat[j][3-i-1] = this->dat[i][j]; 	
		else
			for(int i=0; i<3; ++i) for(int j=0; j<3; ++j) ndat[3-j-1][i] = this->dat[i][j]; 
		memcpy(this->dat,ndat,sizeof(this->dat)); 
	}
};

struct cube{
	face top,bottom,front,back,left,right;
	cube(){
		this->top.init('w');
		this->bottom.init('y');
		this->front.init('r');
		this->back.init('o');
		this->left.init('g');
		this->right.init('b'); 
	}
	
	void rotate(const char &face, const char &dir){
		switch(face){
			case 'U':{
				this->top.rotate(dir); 
				if(dir=='+'){
					char temp[3]; 
					for(int i=0; i<3; ++i) temp[i] = this->front.dat[0][i]; 
					for(int i=0; i<3; ++i) this->front.dat[0][i] = this->right.dat[0][i]; 
					for(int i=0; i<3; ++i) this->right.dat[0][i] = this->back.dat[0][i]; 
					for(int i=0; i<3; ++i) this->back.dat[0][i] = this->left.dat[0][i]; 
					for(int i=0; i<3; ++i) this->left.dat[0][i] = temp[i]; 
				}else{
					char temp[3]; 
					for(int i=0; i<3; ++i) temp[i] = this->front.dat[0][i]; 
					for(int i=0; i<3; ++i) this->front.dat[0][i] = this->left.dat[0][i]; 
					for(int i=0; i<3; ++i) this->left.dat[0][i] = this->back.dat[0][i]; 
					for(int i=0; i<3; ++i) this->back.dat[0][i] = this->right.dat[0][i]; 
					for(int i=0; i<3; ++i) this->right.dat[0][i] = temp[i]; 
				}
				break;
			}case 'D':{
				this->bottom.rotate(dir); 
				if(dir=='-'){
					char temp[3]; 
					for(int i=0; i<3; ++i) temp[i] = this->front.dat[2][i]; 
					for(int i=0; i<3; ++i) this->front.dat[2][i] = this->right.dat[2][i]; 
					for(int i=0; i<3; ++i) this->right.dat[2][i] = this->back.dat[2][i]; 
					for(int i=0; i<3; ++i) this->back.dat[2][i] = this->left.dat[2][i]; 
					for(int i=0; i<3; ++i) this->left.dat[2][i] = temp[i]; 
				}else{
					char temp[3]; 
					for(int i=0; i<3; ++i) temp[i] = this->front.dat[2][i]; 
					for(int i=0; i<3; ++i) this->front.dat[2][i] = this->left.dat[2][i]; 
					for(int i=0; i<3; ++i) this->left.dat[2][i] = this->back.dat[2][i]; 
					for(int i=0; i<3; ++i) this->back.dat[2][i] = this->right.dat[2][i]; 
					for(int i=0; i<3; ++i) this->right.dat[2][i] = temp[i]; 
				}
				break;
			}case 'F':{
				this->front.rotate(dir); 
				if(dir=='+'){
					char temp[3]; 
					for(int i=0; i<3; ++i) temp[i] = this->top.dat[2][i]; 
					for(int i=0; i<3; ++i) this->top.dat[2][i] = this->left.dat[2-i][2]; 
					for(int i=0; i<3; ++i) this->left.dat[i][2] = this->bottom.dat[2][2-i]; 
					for(int i=0; i<3; ++i) this->bottom.dat[2][i] = this->right.dat[i][0]; 
					for(int i=0; i<3; ++i) this->right.dat[i][0] = temp[i]; 
				}else{
					char temp[3]; 
					for(int i=0; i<3; ++i) temp[i] = this->top.dat[2][i]; 
					for(int i=0; i<3; ++i) this->top.dat[2][i] = this->right.dat[i][0]; 
					for(int i=0; i<3; ++i) this->right.dat[i][0] = this->bottom.dat[2][i]; 
					for(int i=0; i<3; ++i) this->bottom.dat[2][i] = this->left.dat[2-i][2]; 
					for(int i=0; i<3; ++i) this->left.dat[i][2] = temp[2-i]; 
				}
				break;
			}case 'B':{
				this->back.rotate(dir); 
				if(dir=='-'){
					char temp[3]; 
					for(int i=0; i<3; ++i) temp[i] = this->top.dat[0][i]; 
					for(int i=0; i<3; ++i) this->top.dat[0][i] = this->left.dat[2-i][0]; 
					for(int i=0; i<3; ++i) this->left.dat[i][0] = this->bottom.dat[0][2-i]; 
					for(int i=0; i<3; ++i) this->bottom.dat[0][i] = this->right.dat[i][2]; 
					for(int i=0; i<3; ++i) this->right.dat[i][2] = temp[i]; 
				}else{
					char temp[3]; 
					for(int i=0; i<3; ++i) temp[i] = this->top.dat[0][i]; 
					for(int i=0; i<3; ++i) this->top.dat[0][i] = this->right.dat[i][2]; 
					for(int i=0; i<3; ++i) this->right.dat[i][2] = this->bottom.dat[0][i]; 
					for(int i=0; i<3; ++i) this->bottom.dat[0][i] = this->left.dat[2-i][0]; 
					for(int i=0; i<3; ++i) this->left.dat[i][0] = temp[2-i]; 
				}
				break;
			}case 'L':{
				this->left.rotate(dir); 
				if(dir=='+'){
					char temp[3]; 
					for(int i=0; i<3; ++i) temp[i] = this->top.dat[i][0]; 
					for(int i=0; i<3; ++i) this->top.dat[i][0] = this->back.dat[2-i][2]; 
					for(int i=0; i<3; ++i) this->back.dat[i][2] = this->bottom.dat[i][2]; 
					for(int i=0; i<3; ++i) this->bottom.dat[i][2] = this->front.dat[2-i][0]; 
					for(int i=0; i<3; ++i) this->front.dat[i][0] = temp[i]; 
				}else{
					char temp[3]; 
					for(int i=0; i<3; ++i) temp[i] = this->top.dat[i][0]; 
					for(int i=0; i<3; ++i) this->top.dat[i][0] = this->front.dat[i][0]; 
					for(int i=0; i<3; ++i) this->front.dat[i][0] = this->bottom.dat[2-i][2]; 
					for(int i=0; i<3; ++i) this->bottom.dat[i][2] = this->back.dat[i][2]; 
					for(int i=0; i<3; ++i) this->back.dat[i][2] = temp[2-i]; 
				}
				break;
			}case 'R':{
				this->right.rotate(dir); 
				if(dir=='-'){
					char temp[3]; 
					for(int i=0; i<3; ++i) temp[i] = this->top.dat[i][2]; 
					for(int i=0; i<3; ++i) this->top.dat[i][2] = this->back.dat[2-i][0]; 
					for(int i=0; i<3; ++i) this->back.dat[i][0] = this->bottom.dat[i][0]; 
					for(int i=0; i<3; ++i) this->bottom.dat[i][0] = this->front.dat[2-i][2];  
					for(int i=0; i<3; ++i) this->front.dat[i][2] = temp[i]; 
				}else{
					char temp[3]; 
					for(int i=0; i<3; ++i) temp[i] = this->top.dat[i][2]; 
					for(int i=0; i<3; ++i) this->top.dat[i][2] = this->front.dat[i][2]; 
					for(int i=0; i<3; ++i) this->front.dat[i][2] = this->bottom.dat[2-i][0]; 
					for(int i=0; i<3; ++i) this->bottom.dat[i][0] = this->back.dat[i][0]; 
					for(int i=0; i<3; ++i) this->back.dat[i][0] = temp[2-i]; 
				}
				break;
			}
		}
	}
	
};

void solve(){
	int n;cin>>n;
	cube Cube;
	for(int i=0; i<n; ++i){
		char a,b; cin>>a>>b; 
		Cube.rotate(a,b); 
	}
	Cube.top.print();
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	int t; cin>>t;
	for(int i=0; i<t; ++i)
		solve(); 
	
	return 0;
}


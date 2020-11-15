#include<iostream>

using namespace std;
int N,K; 
int DIR[4][2] = {{0,1},{0,-1},{-1,0},{1,0}}; 
int D[13][13]; 
int HM[13][13]; 
int TURNS; 

struct horse{
	int r,c,d,i;
	int top, bottom;
	
	int getTop(){
		if(this->top) return (*(this+this->top-this->i)).getTop();
		else return this->i; 	
	}
	
	int getBottom(){
		if(this->bottom) return (*(this+this->bottom-this->i)).getBottom();
		else return this->i; 	
	}
	
	int getStack(){
		if(this->bottom) return (*(this+this->bottom-this->i)).getStack()+1;
		else return 1; 	
	}
	
	void flip(){
//		cout<<this->top<<','<<this->i<<'\n';  
		if(this->top) (*(this+this->top-this->i)).flip(); 
		int t;
		t=this->top;
		this->top=this->bottom;
		this->bottom=t; 
	}
	
	void setPos(int r,int c){
		if(this->top) (*(this+this->top-this->i)).setPos(r,c); 
		this->r=r;
		this->c=c; 
	}
};

horse H[11]; 

bool simulate(){
	if(TURNS>=1000) return false; 
	TURNS++;
//	cout<<"TURN #"<<TURNS<<'\n'; 
	
	for(int i=1; i<=K; ++i){
		auto &h = H[i]; 
		int nr=h.r+DIR[h.d][0], nc=h.c+DIR[h.d][1]; 
		if((nr<=0 || nc<=0 || nr>N || nc>N) || D[nr][nc]==2){
			if(h.d&1) h.d--;
			else h.d++; 
			nr=h.r+DIR[h.d][0], nc=h.c+DIR[h.d][1]; 
			if((nr<=0 || nc<=0 || nr>N || nc>N) || D[nr][nc]==2) continue;  
		}
//		cout<<i<<':'<<h.r<<','<<h.c<<':'<<nr<<','<<nc<<','<<h.d<<endl; 
		if(h.bottom){
			H[h.bottom].top = 0; 	
			HM[h.r][h.c] = h.bottom; 
			h.bottom = 0; 
		}else HM[h.r][h.c] = 0; 
		
		h.setPos(nr,nc); 
		if(D[nr][nc]){
			h.flip();
			int b = h.getBottom(); 
			H[b].bottom = HM[nr][nc]; 
			H[HM[nr][nc]].top = b; 
			HM[nr][nc]=i; 
		}else{
			h.bottom = HM[nr][nc]; 
			H[HM[nr][nc]].top = i; 
//			cout<<h.i<<':'<<h.getTop()<<'\n'; 
			HM[nr][nc]=h.getTop(); 
		}
//		cout<<H[HM[nr][nc]].getStack()<<'\n'; 
//		for(int j=1; j<=N; ++j){
//			for(int k=1; k<=N; ++k)
//				cout<<HM[j][k]<<' ';
//			cout<<'\n'; 
//		}
//			cout<<'\n'; 
		
		if(H[HM[nr][nc]].getStack()>=4) return false; 
//		h.r = nr, h.c = nc; 
	}
	return true; 	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>K;
	for(int i=1; i<=N; ++i) for(int j=1; j<=N; ++j) cin>>D[i][j]; 
	for(int i=1; i<=K; ++i){
		int a,b,c;cin>>a>>b>>c;
		H[i] = {a,b,c-1,i}; 	
		HM[a][b] = i; 
	}
	
	while(simulate()); 
	
	cout<<(TURNS==1000?-1:TURNS); 
	return 0;
}


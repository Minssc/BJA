#include<iostream>
#include<cstring>
using namespace std;
int N,M,K;
int H,W;
int D[41][41];
int S[11][11]; 

//void draw_b(){
//	for(int i=0; i<N; ++i){
//		for(int j=0; j<M; ++j){
//			cout<<D[i][j]<< ' ';
//		}
//		cout<<'\n';
//	}
//	cout<<'\n'; 
//}
//
//void draw(){
//	for(int i=0; i<H; ++i){
//		for(int j=0; j<W; ++j){
//			cout<<S[i][j]<< ' ';
//		}
//		cout<<'\n';
//	}
//	cout<<'\n'; 
//}

void spin(){
	int temp; 
	int NS[11][11];
	memset(NS,0,sizeof(NS)); 
	int a = max(H,W);
	
	for(int i=0; i<a; ++i)
		for(int j=0; j<a; ++j)
			NS[i][j] = S[H-j-1][i];
		
	
	temp = H;
	H = W;
	W = temp; 
	memcpy(S,NS,sizeof(S)); 
}


void stick(int h, int w){
	for(int i=0; i<H; ++i)
		for(int j=0; j<W; ++j)
			if(S[i][j])
				D[h+i][w+j] = 1;
}

bool stick_try(int h, int w){
	for(int i=0; i<H; ++i)
		for(int j=0; j<W; ++j)
			if(S[i][j] && D[h+i][w+j]) return false;
	
	stick(h,w); // actually stick it since we're here
	return true; 
}
bool search(){
	//left top to right bottom 
	for(int i=0; i<=N-H; ++i)
		for(int j=0; j<=M-W; ++j)
			if(stick_try(i,j)) return true;
		
	return false; 
}

void sticker(){
	cin>>H>>W;
	for(int i=0; i<H; ++i) for(int j=0; j<W; ++j)
		cin>>S[i][j]; 

	/*
		look for place to stick
		spin
		repeat 3 times 
		discard if not found
		apply sticker if found
	*/		
	for(int i=0; i<4; ++i){
//		cout<<"TRYING"<<'\n'; 
//		draw(); 
//		for(int j=0; j<H; ++j){
//			for(int k=0; k<W; ++k){
//				if(stick_try(j,k))
//					stick(j,k);
		if(search()) return;
//		if(search()){
//			cout<<"THE BOARD STATUS"<<'\n'; 
//			draw_b(); 
//			return; 
//		}
		
//	cout<<"SPIN"<<'\n'; 
		if(i != 3)
			spin();
//		draw(); 
	}
//	cout<<"TEST"<<endl; 
//	draw();
//	spin();
//	draw(); 
//	spin();
//	draw(); 
//	cout<<"DISCARDING THIS STICKER"<<'\n';
//	draw(); 
	memset(S,0,sizeof(S)); // memset for next sticker
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M>>K;
	for(int i=0; i<K; ++i)
		sticker();
	
		
//			cout<<"FINAL BOARD STATUS"<<'\n'; 
//			draw_b(); 
	int sum = 0; 
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j)
		if(D[i][j])
			sum++;
	cout<<sum<<'\n'; 
	return 0;
}

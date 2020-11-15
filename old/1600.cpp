#include<iostream>
#include<queue> 
#include<cstdio>
using namespace std;

int K,W,H; 
int D[201][201]; 
int C[31][201][201]; // HORSE CHECK 

struct data{
	int y,x,h;
};

int DIR[12][2] = {
	{2,1},
	{1,2},
	{-2,1},
	{-1,2},
	{-1,-2},
	{-2,-1},
	{1,-2},
	{2,-1},
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}}; 
	
void bfs(){
	queue<data> Q; 
	Q.push({0,0,0}); 
	C[0][0][0] = 1; 
	
	while(!Q.empty()){
		auto p = Q.front(); Q.pop(); 
		
		for(int i=0; i<8; ++i){
			if(p.h>=K) break; // NO MORE JUMPS 
			auto np = data({p.y+DIR[i][0],p.x+DIR[i][1],p.h+1}); 
			if(np.y<0 || np.x<0 || np.y>=H || np.x>=W) continue; //oob
			if(D[np.y][np.x]) continue; // obst
			if(C[np.h][np.y][np.x]) continue; // ALREADY VISITED 
			C[np.h][np.y][np.x] = C[p.h][p.y][p.x]+1; 
			Q.push(np); 
		}
		
		for(int i=8; i<12; ++i){
			auto np = data({p.y+DIR[i][0],p.x+DIR[i][1],p.h}); 
			if(np.y<0 || np.x<0 || np.y>=H || np.x>=W) continue; //oob
			if(D[np.y][np.x]) continue; // obst
			if(C[np.h][np.y][np.x]) continue; // ALREADY VISITED 
			C[np.h][np.y][np.x] = C[p.h][p.y][p.x]+1; 
			Q.push(np); 
		}
		
//		for(int i=0; i<12; ++i){
//			auto np = make_pair(p.first+DIR[i][0], p.second+DIR[i][1]); 
//			if(np.first<0 || np.second<0 || np.first>=H || np.second>=W) continue; //oob
//			if(D[np.first][np.second]) continue; // obst
			
//			if(C[np.first][np.second][0] && C[np.first][np.second][0] <= C[p.first][p.second][0] + 1) continue; // already visited and was faster then this try 
//			if(i<8 && C[p.first][p.second][1] >= K) continue; // can't jump anymore. 
//			
//			C[np.first][np.second][0] = C[p.first][p.second][0]+1; 
//			C[np.first][np.second][1] = C[p.first][p.second][1]; // keep the jump, we walkin 
//			
//			if(i<8)
//				C[np.first][np.second][1]++; // WE GNA JUMPPPPPPPPPPP
//			
//				

//			Q.push(np); 
//		}
	}
	
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>K>>W>>H; 
	for(int i=0; i<H; ++i) for(int j=0; j<W; ++j)
		cin>>D[i][j];		
//	K = 2;
//	W=9;
//	H=9; 
//	for(int i=0; i<H; ++i) for(int j=0; j<W; ++j)
//		D[i][j] = 0; 
	
	bfs(); 
//	
//		cout<<endl; 
//	for(int i=0; i<H; ++i){
//		for(int j=0; j<W; ++j){
//			//cout<<C[i][j][0]<< ' ';	
//			printf("%2d ", C[i][j][0]); 	
//		}
//		cout<<endl; 
//	}
//		cout<<endl; 
//	
//	for(int i=0; i<H; ++i){
//		for(int j=0; j<W; ++j){
//			cout<<C[0][i][j]<< ' ';		
//		}
//		cout<<endl; 
//	}
//		cout<<endl; 
//	
//	for(int i=0; i<H; ++i){
//		for(int j=0; j<W; ++j){
//			cout<<C[1][i][j]<< ' ';		
//		}
//		cout<<endl; 
//	}
//		cout<<endl; 
//	
//	for(int i=0; i<H; ++i){
//		for(int j=0; j<W; ++j){
//			cout<<C[2][i][j]<< ' ';		
//		}
//		cout<<endl; 
//	}
//	if(C[H-1][W-1][0])
//		cout<<C[H-1][W-1][0]-1;
//	else
//		cout<<-1; 
//
//	for(int i=0; i<=K; ++i){
//		cout << i << ":" << C[i][H-1][W-1] << '\n'; 	
//	}
	int MIN=1234567890; 
	for(int i=0; i<=K; ++i)
		if(C[i][H-1][W-1] && C[i][H-1][W-1]<MIN)
			MIN=C[i][H-1][W-1]; 
	if(MIN == 1234567890)
		cout << -1; 
	else 
		cout << MIN-1; 
	return 0;
}

#include<iostream>
#include<queue> 
#include<cstring>
#include<algorithm> 

using namespace std;
int N; 
int D[21][21]; 
int V[21][21]; 
struct point{
	int r,c;
	bool operator<(const point &t){
		return (this->r==t.r?this->c<t.c:this->r<t.r); 	
	}
};
point BABYSHARTUTURUTUTUTU;
int SIZE = 2,ATE,TIME; 
int DIR[4][2] = {{-1,0},{0,-1},{1,0},{0,1}}; 

bool FEEDTHEBABYSHARK(){ 
	memset(V,0,sizeof(V)); 
	queue<point> Q;
	Q.push(BABYSHARTUTURUTUTUTU); 
	V[BABYSHARTUTURUTUTUTU.r][BABYSHARTUTURUTUTUTU.c] = 1; 
	
	vector<point> preys; 
	int mindist = 0; 
	
	while(!Q.empty()){
		auto p = Q.front(); Q.pop(); 
		for(int i=0; i<4; ++i){
			point np = {p.r+DIR[i][0], p.c+DIR[i][1]}; 
			if(np.r<0 || np.c<0 || np.r>=N || np.c>=N) continue; //oob
			if(D[np.r][np.c]>SIZE) continue; // bigger then babysharkturutututu
			if(V[np.r][np.c]) continue; 
			V[np.r][np.c] = V[p.r][p.c]+1; 
			if(mindist && mindist<V[np.r][np.c]) continue; 
			if(D[np.r][np.c] && D[np.r][np.c] < SIZE){
				preys.push_back(np); 
				mindist = V[np.r][np.c]; 
			}
			
			Q.push(np); 
		}
	}
	
	if(preys.size()){// TIME TO FEED BABYSHARTUTURUTUTUTU
		sort(preys.begin(), preys.end());
		point p = preys[0]; 
		if(++ATE == SIZE){
			SIZE++;
			ATE = 0; 	
		} // GROW MY BABYSHARKTURUTUTUTUTUTUUTTU
		
		D[p.r][p.c] = 0; //²¨¾ï  
		TIME += V[p.r][p.c]-1; 
		BABYSHARTUTURUTUTUTU = p; 	
		
		return true; 
	}else return false; //MOMYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=0; i<N; ++i) for(int j=0; j<N; ++j){
		cin>>D[i][j]; 
		if(D[i][j] == 9){
			BABYSHARTUTURUTUTUTU = {i,j}; 
			D[i][j] = 0; 
		}
	}
	
	while(FEEDTHEBABYSHARK());
	
	cout<<TIME; 
	
	return 0;
}


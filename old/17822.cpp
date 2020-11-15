#include<iostream>
#include<deque>
#include<queue>
#include<cstring>
using namespace std;
int N,M,T; 
deque<int> D[51]; 
bool V[51][51]; 

void draw(){
	cout<<'\n';
	for(int i=0; i<N; ++i){
		for(int j=0; j<M; ++j){
			cout<<D[i][j] << ' ';	
		}
		cout<<'\n';
	}
	cout<<'\n';
}

void spin(int x, int d, int k){
	if(k==0) return;
	
	for(int i=x; i<=N; ++i){
		if(i%x) continue; 
		auto &q = D[i-1];
		if(d)
			for(int j=0; j<k; ++j) q.push_back(q.front()), q.pop_front();
		else	
			for(int j=0; j<k; ++j) q.push_front(q.back()), q.pop_back(); 
	}
}

struct data{
	int first,second,third;	
};
int DIR[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; 
bool bfs(int i, int j){
	queue<data> Q;
	Q.push({i,j,D[i][j]}); 
	bool flag = false; 
	
	while(!Q.empty()){
		auto q = Q.front(); Q.pop(); 
		for(int i=0; i<4; ++i){
			data nq = {q.first+DIR[i][0],q.second+DIR[i][1], q.third}; 
			if(nq.first<0 || nq.first>=N) continue; // oob 
			if(nq.second<0) nq.second = M-1; 
			else if(nq.second>=M) nq.second = 0; 
			if(V[nq.first][nq.second] || !D[nq.first][nq.second]) continue; 
			if(nq.third == D[nq.first][nq.second]){
				V[nq.first][nq.second] = 1; 
				D[q.first][q.second] = 0; 
				D[nq.first][nq.second] = 0; 
				Q.push(nq); 
				flag = true; 
			}
		}
	}
	return flag; 
}

void eval(){
	int r = 0; 
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j)
		if(D[i][j] && !V[i][j]){
			V[i][j] = 1; 	
			r |= bfs(i,j); 
		}
		
	if(!r){ // 원판값 평균구하고 크면 1빼고 작으면 1더함  
		int sum = 0, cnt = 0; 
		for(int i=0; i<N; ++i) for(int j=0; j<M; ++j){
			if(!D[i][j]) continue; 
		 	sum += D[i][j]; 
		 	cnt++;
		}
		if(cnt){
			double avg = (double)sum/cnt; 
			for(int i=0; i<N; ++i) for(int j=0; j<M; ++j){
				if(!D[i][j]) continue; 
				if(D[i][j]>avg)
					D[i][j]--;
				else if(D[i][j]<avg)
					D[i][j]++; 
			}
		}
	}
	memset(V,0,sizeof(V)); 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	cin>>N>>M>>T; 
	deque<int> test;
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
		int v; cin >> v;
		D[i].push_back(v);
	}

	for(int t=0; t<T; ++t){
		int x,d,k; cin>>x>>d>>k; 
		spin(x,d,k%M);
		eval();
	}
	int sum = 0; 
	for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) sum += D[i][j]; 
	cout<<sum; 
	
	return 0;
}

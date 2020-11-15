#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;
int R,C; 
vector<char> D[21]; 
unordered_set<char> CV; 
int CASCII['Z'-'A'+3]; 
//int CA[21][21]; 
int ML = 0; 
int MML = 0;

int DIR[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; 
void dfs(int r, int c){
	MML = max(MML,ML); 
	if(MML == R*C)
		return;
	
	for(int i=0; i<4; ++i){
		int nr = r+DIR[i][0], nc = c+DIR[i][1];
		if(nr<0 || nc<0 || nr>=R || nc>=C) continue; 
		//if(CA[nr][nc]) continue; 
		//if(CV.find(D[nr][nc]) != CV.end()) continue; // already have that char 
		if(CASCII[D[nr][nc]-'A']) continue; 
		//CA[nr][nc] = 1; 
		//CV.insert(D[nr][nc]); 
		CASCII[D[nr][nc]-'A'] = 1;
		ML+=1;
		dfs(nr,nc); 	
		ML-=1;
		CASCII[D[nr][nc]-'A'] = 0;
		//CV.erase(D[nr][nc]); 
		//CA[nr][nc] = 0; 
	}
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0); 
	cin>>R>>C; 
	for(int i=0; i<R; ++i){
		string s; cin>>s; 
		for(auto c:s)
			D[i].push_back(c);
	}
	
//	for(auto c:D[0])
//		cout << c << ' ';
//	cout<<endl; 
//	C = ""; 
	//CV.clear(); 
	//CV.insert(D[0][0]); 
	//CA[0][0] = 1; 
	CASCII[D[0][0]-'A'] = 1; 
	ML=1;
	dfs(0,0); 
	
	cout<<MML; 
	
	return 0;
}

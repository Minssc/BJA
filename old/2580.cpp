#include<iostream>
#include<vector>
using namespace std;
int D[10][10]; 

int sudoku(){
	int r,c;
	for(int i=0; i<9; ++i)
		for(int j=0; j<9; ++j)
			if(!D[i][j]){
				r=i; c=j; goto FOUND_POS;
			}
	return 1; // no more blank spots, DONE!!! 
FOUND_POS:
	
	vector<int> candidate;
	for(int i=1; i<=9; ++i)
		if([&](){
			for(int j=0; j<9; ++j)
				if(D[r][j] == i || D[j][c] == i)
					return false; 	
					
			int gr=(r/3)*3, gc=(c/3)*3;
			
			for(int j=gr; j<gr+3; ++j)
				for(int k=gc; k<gc+3; ++k)
					if(D[j][k] == i)
						return false; 
			return true;
		}()) candidate.push_back(i); 
	
	for(auto &i:candidate){
		D[r][c] = i;	
		if(sudoku())
			return 1; 
		D[r][c] = 0; 
	}
	
	return 0; 
}

int main(){
	cin.tie(0), ios_base::sync_with_stdio(0);
	for(int i=0; i<9; ++i) for(int j=0; j<9; ++j)
		cin>>D[i][j]; 
		
	sudoku(); 
			
	for(int i=0; i<9; ++i){
		for(int j=0; j<9; ++j){
			cout << D[i][j] << ' ';
		}
		cout<<'\n'; 
	}
	
	return 0;
}

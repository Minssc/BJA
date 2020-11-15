#include<iostream>
using namespace std;
int *g_MS; 

void merge(int *A, int l, int m, int r){
	int L = l;
	int I = l; 
	int R = m+1; 
	
	while(L<=m && R<=r)
		if(A[L] < A[R]) 
			g_MS[I++] = A[L++]; 
		else 
			g_MS[I++] = A[R++]; 
	while(L<=m) g_MS[I++] = A[L++];
	while(R<=r) g_MS[I++] = A[R++];
	
	for(int i=l; i<=r; ++i){
		A[i] = g_MS[i]; 
	}
	
}

void mergeSort(int *A, int left, int right){
	if(left < right){
		int middle = (left+right)/2; 	
		mergeSort(A, left, middle);
		mergeSort(A, middle+1, right); 
		merge(A, left, middle, right); 
	}
}

int main(){
	cin.tie(NULL),ios_base::sync_with_stdio(false);
	int N;
	cin>>N;
	
	int *A = new int[N]; 
	g_MS = new int[N]; 
	
	for(int i=0; i<N; ++i)
		cin>>A[i]; 
	
	mergeSort(A, 0, N-1); 
	
	for(int i=0; i<N; ++i)
		cout << A[i] << endl; 
	
	delete[] A;
	delete[] g_MS; 
	return 0;	
}

#include <bits/stdc++.h>
using namespace std;
vector<int> corriendo(int T, int K, int N){
	int sumaVueltas=0; 
	if (N>=T) sumaVueltas+=K*(N/T); 
	int resto=N%T; 
	int maxi=sumaVueltas+min(resto, K); 
	int mini=sumaVueltas;
	if (resto>T-K) mini+=resto-(T-K);
	return {mini,maxi};
}

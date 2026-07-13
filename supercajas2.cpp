#include <bits/stdc++.h>
#define ff first 
#define sc second
#define pii pair <int,int>
using namespace std;
int supercajas(int N, int X, int Y, int Z, vector<int> &a, vector<int> &b, vector<int> &c){
	vector <int> dims={X,Y,Z}; sort(dims.begin(),dims.end()); 
	int minVol=1e8; 
	map <pair <pii,pii>,int> ops; 
	for (int i=0;i<a.size();i++){
		vector <int> aux={a[i],b[i],c[i]}; 
		sort (aux.begin(),aux.end()); 
		if (aux[0]>=dims[0] && aux[1]>=dims[1] && aux[2]>=dims[2]) {
			int sobrante=aux[0]*aux[1]*aux[2]-dims[0]*dims[1]*dims[2]; 
			ops[{{sobrante,aux[0]},{aux[1],aux[2]}}]++;
	}
}
	for (auto i:ops) if (i.sc>=N) return i.ff.ff.ff; 
	return -1;
}

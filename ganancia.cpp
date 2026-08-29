#include <bits/stdc++.h>
using namespace std; 
#define ff first 
#define sc second 
#define pii pair <int,int>
struct PQ{ int precio, cantidad; } ;
int ganancia( int P, vector< PQ > fabricantes, vector< PQ > compradores, int & Fab, int & Comp )
{
	vector <pair<pii,pii>> ops; 
	for (int j=0;j<fabricantes.size(); j++){
		auto i=fabricantes[j];
		ops.push_back({{i.cantidad, 0},{i.precio,j+1}});
	}
	for (int j=0;j<compradores.size(); j++){
		auto i=compradores[j];
		ops.push_back({{i.cantidad, 1},{i.precio,j+1}});
	}
	sort(ops.begin(), ops.end()); 
	Fab=0,Comp=0;  
	int ganancia=-1; 
	pii minPrecio={INT_MAX, -1};
	for (auto i:ops){
		if (!i.ff.sc){
			if (i.sc.ff<minPrecio.ff) minPrecio=i.sc;
		}
		else{
			if (minPrecio.sc==-1) continue;
			if (ganancia<i.ff.ff*(i.sc.ff-minPrecio.ff) && minPrecio.ff*i.ff.ff<=P) 
				ganancia=i.ff.ff*(i.sc.ff-minPrecio.ff), Comp=i.sc.sc, Fab=minPrecio.sc; 
		}
	}
	reverse(ops.begin(), ops.end()); 
	pii minCosto={INT_MAX,-1};
	for (auto i:ops){
		if (!i.ff.sc){
			if (i.sc.ff*i.ff.ff<=P && i.sc.ff*i.ff.ff<minCosto.ff) minCosto={i.sc.ff*i.ff.ff, i.sc.sc}; 
		}
		else {
			if (minCosto.sc==-1) continue;
			if (i.ff.ff*i.sc.ff-minCosto.ff>ganancia) Fab=minCosto.sc, Comp=i.sc.sc, ganancia=i.ff.ff*i.sc.ff-minCosto.ff;
		}	
	}
	return ganancia;
}

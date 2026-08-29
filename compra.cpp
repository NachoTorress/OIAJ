#include <bits/stdc++.h>
#define ff first
#define sc second
#define pii pair<int,int>
using namespace std;
int compra( int P, vector< PQ > fabricantes, vector< PQ > compradores, vector< FQ > &Fab, int & Comp ){
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
	Fab.push_back({0,0}),Comp=0;  
	int ganancia=-1; 
	pii minPrecio={INT_MAX, -1};
	for (auto i:ops){
		if (!i.ff.sc){
			if (i.sc.ff<minPrecio.ff) minPrecio=i.sc;
		}
		else{
			if (minPrecio.sc==-1) continue;
			if (ganancia<i.ff.ff*(i.sc.ff-minPrecio.ff) && minPrecio.ff*i.ff.ff<=P) 
				ganancia=i.ff.ff*(i.sc.ff-minPrecio.ff), Comp=i.sc.sc, Fab[0].fabricante=minPrecio.sc, Fab[0].cantidad=i.ff.ff; 
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
			if (i.ff.ff*i.sc.ff-minCosto.ff>ganancia) Fab[0].fabricante=minCosto.sc, Fab[0].cantidad=fabricantes[minCosto.sc-1].cantidad, Comp=i.sc.sc, ganancia=i.ff.ff*i.sc.ff-minCosto.ff;
		}	
	}
	if (ganancia==-1) Fab.pop_back();
	return ganancia;
}

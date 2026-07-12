#include <bits/stdc++.h>
#define ll long long
#define ff first 
#define sc second
#define pll pair <ll,ll>
using namespace std;
vector <pll> dist; 
vector <vector<pair <ll,pll>>> ady; 
vector<long long> millas(int N, vector<int> &a, vector<int> &b, vector<int> &d, vector<int> &m){
	ll M=a.size();
	ady.resize(N+1), dist.resize(N+1,{1e15,1e15});
	for (int i=0;i<M;i++){
		ll ai=a[i], bi=b[i], di=d[i], mi=m[i]; 
		ady[ai].push_back({bi, {di,mi}});
	}
	priority_queue <pair <pll,ll>> cola; 
	cola.push({{0,0},1}); 
	while (cola.size()){
		ll nodo=cola.top().sc, dinero=-cola.top().ff.ff, millas=-cola.top().ff.sc; 
		cola.pop(); 
		if (dist[nodo].ff<dinero || (dist[nodo].ff==dinero && dist[nodo].sc<=millas)) continue; 
		dist[nodo]={dinero,millas}; 
		for (auto i:ady[nodo]){
			ll b=i.ff, millasi=i.sc.sc, dineroi=i.sc.ff; 
			if (millasi!=-1) cola.push({{-dinero, -(millas+millasi)}, b}); 
			else cola.push({{-(dinero+dineroi),-millas},b}); 
		}
	}
	vector <ll> res={dist[N].ff ,dist[N].sc}; 
	return res;
}

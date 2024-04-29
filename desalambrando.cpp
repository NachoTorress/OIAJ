#include <string>
#include <vector>

using namespace std;
#include <bits/stdc++.h>
#define ll long long
vector <ll> ID;
vector <vector <ll>> comp;
vector <pair<ll, pair<ll,ll>>> edges;
bool unionFind(ll a, ll b){
	int x=ID[a], y=ID[b];
	if (x==y) return false;
	if (comp[x].size()<comp[y].size()){
		swap(a,b); swap(x,y);
	}
	for (auto i:comp[y]){
		comp[x].push_back(i);
		ID[i]=x;
	}
	return true;
}
long long desalambrando(int N, vector<int> &a, vector<int> &b, vector<int> &costo){
	ID.resize(N+1);
	comp.resize(N+1); 
	edges.resize(a.size());
	for (int i=1;i<=N;i++){
		comp[i].push_back(i);
		ID[i]=i;
	}
	ll total=0;
	for (int i=0;i<edges.size();i++){
		edges[i].first=costo[i];
		edges[i].second.first=a[i];
		edges[i].second.second=b[i];
		total+=costo[i];
	}
	ll costos=0;
	sort(edges.rbegin(), edges.rend());
	for (auto i:edges){
		if (!unionFind(i.second.first, i.second.second)){
			costos+=i.first;
		}
	}
	return costos;
}


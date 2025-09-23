#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define sc second
#define INF 1e15
vector <pair<ll,ll>> dist;
vector <vector<ll>> ady;
int main(){
	ll n,m,d; cin>>n>>m>>d;
	ady.resize(n+1); dist.resize(n+1,{INF,INF});
	while (m--){
		ll a,b; cin>>a>>b;
		ady[a].push_back(b); ady[b].push_back(a);
	}
	dist[1].ff=0;
	queue <ll> cola;
	cola.push(1);
	while (cola.size()){
		ll nodo=cola.front(); cola.pop();
		for (auto i:ady[nodo]){
			if (dist[nodo].ff+1<dist[i].ff){
				dist[i].ff=dist[nodo].ff+1;
				cola.push(i);
			}
		}
	}
	cola.push(n);
	dist[n].sc=0;
	while (cola.size()){
		ll nodo=cola.front(); cola.pop();
		for (auto i:ady[nodo]){
			if (dist[nodo].sc+1<dist[i].sc){
				dist[i].sc=dist[nodo].sc+1;
				cola.push(i);
			}
		}
	}
	ll cant=0;
	for (auto i:dist)
		if (i.ff + i.sc <= d) cant++;
	cout<<cant;
}

#include <bits/stdc++.h>
#define ll long long
#define ff first 
#define sc second
#define pll pair <ll,ll>
#define INF 1e15
using namespace std;
vector<long long> millas(int N, vector<int> &a, vector<int> &b, vector<int> &d, vector<int> &m){
	ll M=a.size();
	vector <vector<ll>> dist(N+1, vector <ll> (1001,INF));  
	vector <vector<pair <ll,pll>>> ady (N+1); 
	for (int i=0;i<M;i++){
		ll ai=a[i], bi=b[i], di=d[i], mi=m[i]; 
		ady[ai].push_back({bi, {di,mi}});
	}
	priority_queue <pair <pll,ll>> cola; 
	cola.push({{0,1000},1}); 
	dist[1][1000]=0; 
	while (cola.size()){
		ll nodo= cola.top().sc, dinero=-cola.top().ff.ff, millas=cola.top().ff.sc; cola.pop();
		if (dist[nodo][millas] !=dinero) continue; 
		for (auto i:ady[nodo]){
			ll v=i.ff, d=i.sc.ff, m=i.sc.sc; 
			if (dist[v][millas]>dinero+d){
				dist[v][millas]=dinero+d;
				cola.push({{-(dinero+d),millas},v});
			}
			if (m!=-1 && millas>=m && dinero <dist[v][millas-m]){
				dist[v][millas-m]=dinero; 
				cola.push({{-(dinero),millas-m},v});
			}
		}
	}
	ll respD=INF, respM=0;
	for (int i=0;i<=1000;i++){
		if (dist[N][i]<respD || (dist[N][i]==respD && 1000-i<respM)){
			respD=dist[N][i], respM=1000-i;
		}
	}
	return {respD,respM};
}

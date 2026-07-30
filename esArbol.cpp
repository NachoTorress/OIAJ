#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define sc second
vector <vector <ll>> ady; 
vector <ll> entradas;
vector <bool> visited;
ll visitados;
void dfs(ll u){
	if (visited[u]) return; 
	visited[u]=1; 
	visitados++;
	for (auto i:ady[u]) dfs(i);
}
int main(){
	ll n,m; cin>>n>>m; ady.resize(n+1), entradas.resize(n+1), visited.resize(n+1);
	vector <ll> r1, r2, r3;
	visitados=0;
	for (int i=0;i<m;i++){
		ll a,b; cin>>a>>b; entradas[b]++, ady[a].push_back(b);
	}
	for (int i=1;i<=n;i++){
		if (!entradas[i]) r1.push_back(i);
	}
	if (!r1.size()) r1.push_back(0);
	for (int i=1;i<=n;i++) if (entradas[i]>1) r2.push_back(i);  // revisar tambien con >1
	if (!r2.size()) r2.push_back(0);
	if (r1[0]==0) r3.push_back(0); 
	else {
		for (auto i:r1) dfs(i); 
		for (int i=1;i<=n;i++) if (!visited[i]) r3.push_back(i); 
	} 
		if (!r3.size()) r3.push_back(0); 
	if (visitados==n && m==n-1
		&& r1[0]!=0 
		&& r2[0]==0
		&& r3[0]==0) 
		cout<<"Si "<<r1[0];
	else {
		cout<<"No"<<endl; 
		for (auto i:r1) cout<<i<<" ";
		cout<<endl;
		for (auto i:r2) cout<<i<<" ";
		cout<<endl;
		for (auto i:r3) cout<<i<<" ";
		cout<<endl;
	}
}

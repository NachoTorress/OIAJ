#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> arcosEntrantes;
vector <vector<ll>> ady;
vector <ll> raices;
vector <ll> regla2;
vector <ll> regla3;
vector <bool> visited;
bool esArbol=true;
void hayRaiz(){
	int numRaices=0;
	for (ll i=1;i<arcosEntrantes.size();i++){
		if (arcosEntrantes[i]==0) numRaices++, raices.push_back(i);
		else if (arcosEntrantes[i]>1) regla2.push_back(i);
	}
	if (regla2.size()>0 || numRaices!=1) esArbol=false;
}
void dfs(ll u){
	if (visited[u]) return;
	visited[u]=1;
	for (auto n:ady[u]){
		dfs(n);
	}
}
void getRegla3(){
	if (raices.size()==1){
		dfs(raices[0]);
		for (int i=1;i<visited.size();i++){
			if (!visited[i]){
			 regla3.push_back(i);
			 esArbol=false;
		}
	}
}
}
int main(){
	
	freopen("arbol.in", "r", stdin);
	freopen("arbol.out", "w", stdout);
	ll n, m; cin>>n>>m;
	arcosEntrantes.resize(n+1), ady.resize(n+1), visited.resize(n+1,0);
	
	for (ll i=0;i<m;i++){
		ll a,b; cin>>a>>b;
		ady[a].push_back(b);
		arcosEntrantes[b]++;
	}
	
	hayRaiz(); getRegla3();
	
	if (esArbol) cout<<"Si "<<raices[0];
	else {
		cout<<"No"<<"\n";
		
		if (raices.size()==0) {
		cout<<"0\n";
	}
		else if (raices.size()>1){
		 for (auto i:raices) cout<<i<<' ';
		 cout<<'\n';
	}
		else {
		cout<<raices[0];
		cout<<'\n';
		}
		
		if (regla2.size()==0) cout<<"0\n";
		else {
		for (auto i:regla2) cout<<i<<' ';
		cout<<'\n';
	}
		
		if (regla3.size()==0) cout<<0;
		else for (auto i:regla3) cout<<i<<' ';
		cout<<"\n";
	}
}

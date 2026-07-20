#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define ff first
#define sc second
vector <ll> costos; 
vector <ll> caps; 
vector <set<pair<ll,ll>>>ady; 
ll dfs (ll nodo, ll costo){
	costos.push_back(costo);
	if (!ady[nodo].size()) return caps[nodo]+costo;
	ll costoAct=costo;
	int prev=0;
	for (auto i:ady[nodo]){
		costoAct=dfs(i.sc, costoAct+i.ff-prev);
		prev=i.ff;
	}
	auto it=ady[nodo].end(); 
	it--;
	ll diff= (caps[nodo])-(*(it)).ff;
	return costoAct+diff; 
}
int main(){
	ll t; cin>>t; 
	caps.resize(t); ady.resize(t);
	for (auto &i:caps) cin>>i;
	for (int i=0;i<t-1;i++){
		ll t1, d, t2; cin>>t1>>d>>t2; 
		t1--,t2--;
		ady[t1].insert({caps[t1]-d,t2});
	}
	dfs(0,1);
	sort (costos.begin(), costos.end());
	ll q; cin>>q; 
	vector <ll> resp;
	while (q--){
		ll qi; cin>>qi; 
		auto it=upper_bound(costos.begin(),costos.end(),qi);
		resp.push_back(it-costos.begin());
	}
	for (auto i:resp) cout<<i<<" ";
}

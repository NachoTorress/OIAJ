#include <bits/stdc++.h>
#define ff first
#define sc second
#define ll long long
using namespace std;
ll inst; 
vector <int> prods; 
vector <vector<pair<ll,ll>>> ops;
vector <ll> compra; 
vector <vector <pair<ll,ll>>> allPrecios; 
void inicializar(vector<int> &P, int C, int Q){
	inst=1; 
	prods = P; 
	ops.resize(P.size()); 
	allPrecios.resize(P.size());
	compra.resize(C,-1);
	for (int i=0;i<P.size();i++){
		ops[i].push_back({1,P[i]}); 
		allPrecios[i].push_back({1,P[i]});
	}
	
}
int comprar(int c, int p){
	if (compra[c]==-1){
		compra[c]=inst; 
		return prods[p];
	}
	auto it = lower_bound(ops[p].begin(), ops[p].end(),
                       make_pair(compra[c], (long long)LLONG_MIN));
    if (it==ops[p].end()) return prods[p];
    auto res=*it; 
    auto p2=upper_bound(allPrecios[p].begin(), allPrecios[p].end(), make_pair((ll)compra[c],(ll)1e15)); 
    p2--;
    return min(res.sc, p2->second);
	
}
void cambiar(int p, int v){
	prods[p]=v; 
	inst++;
	while (!ops[p].empty() && ops[p].back().sc>=v) ops[p].pop_back(); 
	ops[p].push_back({inst,v});
	allPrecios[p].push_back({inst,v});
	}

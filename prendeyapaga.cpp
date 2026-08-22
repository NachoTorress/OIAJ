#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector <vector <ll>> ady; 
#define maxN 400000
ll hijos[maxN*4], padres[maxN*4], R[maxN*4], L[maxN*4]; 
ll pot, tim;
vector <ll> tin, tout;
vector <ll> estado; 
void dfs(ll n){
	tin[n]=tim++;
	for (auto u:ady[n]) dfs(u); 
	tout[n]=tim++;
}
void sigPot(ll n){
	ll aux=1; 
	while (aux<n) aux*=2; 
	pot=aux;
}
ll query (ll ST[], ll nodo, ll a, ll b){
	if (R[nodo]<a || L[nodo]>b) return 0; 
	if (L[nodo]>=a && R[nodo]<=b) return ST[nodo]; 
	return query(ST,nodo*2,a,b)+query(ST,nodo*2+1,a,b);
}
void update (ll ST[], ll val, ll pos){
	ST[pot+pos]=val; 
	ll aux=pot+pos; 
	while (aux/=2) ST[aux]=ST[aux*2]+ST[aux*2+1];
}
vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo){
	ll n=padre.size()+1;
	ady.resize(n); 
	tim=0;
	for (int i=0;i<padre.size();i++) ady[padre[i]].push_back(i+1);
	tin.resize(n*2), tout.resize(n*2); estado.resize(n);
	dfs(0);
	sigPot(n*2);
	for (int i=0;i<pot;i++){
		L[i+pot]=R[i+pot]=i;
	}
	vector <int> resp; 
	for (int i=pot-1;i>0;i--) L[i]=L[i*2], R[i]=R[i*2+1];
	for (int i=0;i<nodo.size();i++){
		ll op, nod=nodo[i];
		if (tipo[i]==1) op=0; 
		else op=1;
		if (estado[nod]==op){
		 resp.push_back(0);
		 continue;
		 }
		if (op==0){
			update(hijos,0,tin[nod]); 
			update(padres,0,tin[nod]); 
			update(padres,0,tout[nod]);
			resp.push_back(1);
			estado[nod]=0;
		}
		else {
			ll respPadres=query(padres,1,0,tin[nod]); 
			ll respHijos=query(hijos,1,tin[nod], tout[nod]);
			if (!respPadres && !respHijos){
				estado[nod]=1; 
				update(hijos,1,tin[nod]); 
				update(padres,1,tin[nod]); 
				update(padres,-1,tout[nod]);
				resp.push_back(1);
			}
			else resp.push_back(0);
		}
	}
	return resp;
}

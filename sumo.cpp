#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxN 200000
#define ff first 
#define sc second
ll ST[maxN*4], L[maxN*4], R[maxN*4]; 
ll pot; 
void sigPot(ll n){
	ll aux=1; while (aux<n) aux*=2; pot=aux;
}
void update (ll pos){
	ll aux=pos+pot; 
	ST[aux]=1; 
	while (aux/=2) ST[aux]=ST[aux*2]+ST[aux*2+1];
}
ll query (ll nodo, ll a, ll b){
	if (L[nodo]>=a && R[nodo]<=b) return ST[nodo]; 
	else if (R[nodo] <a || L[nodo]>b) return 0; 
	return query(nodo*2,a,b)+query(nodo*2+1,a,b);
}
int main(){
	ll n; cin>>n;  
	vector <vector <ll>> luchadores (n, vector <ll>(3)); 
	set <pair <pair<ll,ll>,ll>> alts; 
	for (int i=0;i<n;i++){
		ll p,h; cin>>p>>h; 
		luchadores[i]={p,h,i};
		alts.insert({{h,p},i}); 
	}
	vector <ll> indices (n); 
	int i=0;
	for (auto j:alts){
		indices[j.sc]=i; 
		i++;
	}
	sort (luchadores.begin(), luchadores.end()); 
	sigPot(n); 
	for (int j=0;j<pot;j++){
		L[j+pot]=R[j+pot]=j;
	}
	for (int j=pot-1;j>0;j--){
		L[j]=L[j*2], R[j]=R[j*2+1];
	}
	vector <ll> resp (n); 
	for (int j=0;j<n;j++){
		resp[luchadores[j][2]]=query(1,0,indices[luchadores[j][2]]); 
		update (indices[luchadores[j][2]]);
	}
	for (auto i:resp) cout<<i<<endl;
}

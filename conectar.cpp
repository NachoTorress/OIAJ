#include <bits/stdc++.h>
#define ll int 
#define nmax 1000002
using namespace std;
vector <vector<ll>> comp;
vector <ll> ID;
void unionFind (ll a, ll b){
	ll x=ID[a], y=ID[b];
	if (x==y) return;
	if (comp[x].size()<comp[y].size()) swap(x,y);
	for (auto i:comp[y]){
		ID[i]=x;
		comp[x].push_back(i);
	}
}
int main(){
	freopen("conectar.in", "r", stdin);
	freopen("conectar.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	char eleccion;
	cin>>eleccion;
	string respuesta="";
	comp.resize(nmax), ID.resize(nmax);
	for (int i=1;i<nmax;i++){
		comp[i].push_back(i);
		ID[i]=i;
	}
	ll k1,k2;
	while (eleccion!='F'){
		cin>>k1>>k2;
		if (eleccion=='P'){
	 		respuesta+= (ID[k1]==ID[k2])? "S \n": "N \n";
		}
		else{
			unionFind(k1,k2);
		}
		cin>>eleccion;
	}
	cout<<respuesta;
}

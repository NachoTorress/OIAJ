#include <bits/stdc++.h> 
using namespace std; 
#define ll long long 
vector <vector <ll>> ady; 
vector <ll> color; 
vector <bool> esHijo; 
ll costo;
void dfs (ll nodo, vector <ll> &colores, bool indice){
	if (color[nodo]!=colores[indice]) costo++;
	for (auto i:ady[nodo]) dfs(i, colores, !indice);
}
int main(){
	ll n; cin>>n; 
	if (n==0){
    	cout << "0 A B" << endl; 
		return 0;
	}
	else if (n==1){
		ll id, hijos; char letra;
		cin>>id>>letra>>hijos; 
		ll numLetra=letra-'A'; 
		ll numC2=(numLetra+1)%3; 
		char c2=numC2+'A'; 
		cout<<0<<" "<<letra<<" "<<c2<<endl; 
		return 0;
	}
	ady.resize(n+1), color.resize(n+1), esHijo.resize(n+1,false);
	for (int i=0;i<n;i++){
		ll id, hijos; char letra; cin>>id>>letra>>hijos; 
		color[id]=letra-'A';  
		for (int j=0;j<hijos;j++){
			ll idJ; cin>>idJ; 
			esHijo[idJ]=true;
			ady[id].push_back(idJ);
		}
	}
	ll raiz; 
	for (int i=1;i<=n;i++) if (!esHijo[i]){raiz=i;break;}
	vector <vector<ll>> ops; 
	ops.push_back({0,1}); ops.push_back({1,0}); ops.push_back({0,2}); ops.push_back({2,0}); ops.push_back({1,2}); ops.push_back({2,1});
	ll minCosto=LLONG_MAX;
	vector <ll> resp; 
	for (auto i:ops){
		costo=0; 
		dfs(raiz,i,0); 
		if (costo<minCosto) resp=i, minCosto=costo;	
	}
	char c1=resp[0]+'A', c2=resp[1]+'A';
	cout<<minCosto<<" "<<c1<<" "<<c2<<endl;
}

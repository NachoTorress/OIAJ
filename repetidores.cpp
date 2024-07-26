#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;
vector <ll> colores;
vector <vector <ll>> ady;
vector <bool> visited;
vector <bool> esRaiz;
ll costo;
void  dfs (vector <ll> colores2,bool color, ll nodo){
	if (visited[nodo])	 return;

	visited[nodo]=true;
	if (colores2[color]!=colores[nodo]) costo++;
	colores[nodo]=colores2[color];
	for (auto i:ady[nodo]){
		dfs(colores2, !color, i);
	}
	
}
int main(){
	freopen("repetidores.in", "r", stdin);
	freopen("repetidores.out", "w", stdout);
	ll n; cin>>n;
	if (n==0){
		int mini=0;
		char l1='A', l2='B';
		cout<<mini<<" "<<l1<<" "<<l2<<"\n";
		return 0;
	}
	colores.resize(n);
	ady.resize(n);
	esRaiz.resize(n, true);
	visited.resize(n, 0);
	for (ll i=0;i<n;i++){
		ll numero, dependientes;
		char color;
		cin>>numero>>color>>dependientes;
		numero--;
		colores[numero]=color-'A';
		for (ll j=0;j<dependientes;j++){
			ll hijo; cin>>hijo; hijo--;
			ady[numero].push_back(hijo);
		}
	}
	for (int i=0;i<ady.size();i++){
		for (int j=0;j<ady[i].size();j++) esRaiz[ady[i][j]]=false;
	}
	ll raiz;
	for (int i=0;i<n;i++) {
		if (esRaiz[i]){
			raiz=i;
			break;
		}
	}
	vector <ll>coloresAux=colores;
	vector <bool> visitedAux=visited;
	ll mini=INF; ll letra1, letra2;
	costo=0;
	vector<ll> colores2={0,1};
	dfs(colores2,0,raiz);
	if (costo<mini){
		letra1=0, letra2=1, mini=costo;
	}
	costo=0;
	colores=coloresAux;
	visited=visitedAux;
	colores2={1,0};
	dfs(colores2,0,raiz);
	if (costo<mini){
		letra1=1, letra2=0, mini=costo;
		
	}
	costo=0;
	colores=coloresAux;
	visited=visitedAux;
	colores2={0,2};
	dfs(colores2,0,raiz);
	if (costo<mini){
		letra1=0, letra2=2, mini=costo;
	}
	costo=0;
	colores=coloresAux;
	visited=visitedAux;
	colores2={2,0};
	dfs(colores2,0,raiz);
	if (costo<mini){
		letra1=2, letra2=0, mini=costo;
	}
	costo=0;
	colores=coloresAux;
	visited=visitedAux;
	colores2={1,2};
	dfs(colores2,0,raiz);
	if (costo<mini){
		letra1=1, letra2=2, mini=costo;
	}
	costo=0;
	colores=coloresAux;
	visited=visitedAux;
	colores2={2,1};
	dfs(colores2,0,raiz);
	if (costo<mini){
		letra1=2, letra2=1, mini=costo;
	}
	costo=0;
	colores=coloresAux;
	char l1=letra1+'A', l2=letra2+'A';
	cout<<mini<<" "<<l1<<" "<<l2<<"\n";
}

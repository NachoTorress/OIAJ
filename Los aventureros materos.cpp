#include <bits/stdc++.h>
#include <fstream>
#define ll long long
#define MAX_N 400000
using namespace std;
ll ST[MAX_N*4];
ll pot;
vector <ll> resp;
vector <ll> procesado;
unsigned ll sumatoria;
ll sigPot(int n){
	int pot2=1;
	while (pot2<n){
		pot2*=2;
	}
	return pot2;
}
void query (ll nodo, ll buscando){
	/*cout<<"NODO ACTUAL: "<<nodo<<" Valor: "<<ST[nodo]<<endl;
	cout<<"HIJOS: "<<endl;
	cout<<"DERECHA: "<<nodo*2<<" VALOR: "<<ST[nodo*2]<<endl;
    cout<<"BUSCANDO: "<<buscando<<endl;
	cout<<endl;*/
	if (nodo>=pot && ST[nodo]==buscando){
		procesado[nodo-pot+1]=true;
		resp.push_back(nodo-pot+1);
		ST[nodo]=0;
		//cout<<"SE ENCONTRO"<<endl;
		while (nodo/=2){
			ST[nodo]=ST[nodo*2]+ST[nodo*2+1];
		}
		return;
	}
	if (ST[nodo*2]>=buscando) return query(nodo*2, buscando);
	else return query(nodo*2+1, buscando-ST[nodo*2]);
}
int main(){
freopen("aventureros.in", "r", stdin);
freopen("aventureros.out", "w", stdout);
	int n; cin>>n;
	procesado.resize(n+1,false);
	vector <ll> nums(n);
	for (int i=0;i<n;i++){
		nums[i]=i;
	}
	 pot =sigPot(n);
	for (int i=pot;i<pot+n;i++){
		ST[i]=1;
	}
	for (int i=pot-1;i>0;i--){
		ST[i]=ST[i*2]+ST[i*2+1];
	}
	int a=1;
	for (int i=0;i<n-1;i++){
		int b; cin>>b;
      //  a++;
		a=(a+b)%(n-i);
	
        
        if (!a) a=n-i;
		query(1, a);
		
	}
	for (auto i:resp) cout<<i<<" ";
	cout<<endl;
	for (int i=1;i<=n;i++){
		if (!procesado[i]){
			cout<<i;
			break;
		}
	}
	
}

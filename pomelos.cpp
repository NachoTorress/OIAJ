#include <bits/stdc++.h>
#define ll long long
#define maxN 200000
#define ff first 
#define sc second 
using namespace std;
pair<ll,ll> ST[maxN*4];
ll L[maxN*4], R[maxN*4];
ll lazy[maxN*4];
ll pot; 
ll sigPot(int n){
	ll aux=1; while (aux<n) aux*=2; return aux;
}
void push(ll nodo){
	if (lazy[nodo]!=0){
		if (L[nodo]!=R[nodo]) lazy[nodo*2]+=lazy[nodo], lazy[nodo*2+1]+=lazy[nodo]; 
		ST[nodo].sc+=lazy[nodo];
		lazy[nodo]=0;
	//	cout<<"actualizando algo"<<endl;
	}
}
void updateRange(ll nodo, ll a, ll b, ll dif){
	push(nodo); 
	if (a>R[nodo] || L[nodo]>b) return; 
	if (L[nodo]>=a && R[nodo]<=b){
		lazy[nodo]+=dif; 
		push(nodo);
		return; 
	}
	updateRange(nodo*2,a,b,dif),updateRange(nodo*2+1,a,b,dif);
	ST[nodo].sc=max(ST[nodo*2].sc, ST[nodo*2+1].sc);
}
void updateTiempo(ll pos, ll valor){
	ll dif=valor-ST[pot+pos].ff; 
	ST[pos+pot].ff=valor; 
	ll aux=pos+pot; 
	while (aux/=2) ST[aux].ff=ST[aux*2].ff+ST[aux*2+1].ff; 
	updateRange(1,pos,pot,dif);
}
ll queryTiempo(ll nodo, ll a, ll b){
	if (a>R[nodo] || L[nodo]>b) return 0; 
	if (L[nodo]>=a && R[nodo]<=b) return ST[nodo].ff; 
	return queryTiempo(nodo*2,a,b) + queryTiempo(nodo*2+1,a,b);
}
ll queryCosto(ll nodo, ll a, ll b){
	push(nodo);
	if (a>R[nodo] || L[nodo]>b) return -1; 
	if (L[nodo]>=a && R[nodo]<=b) return ST[nodo].sc; 
	return max(queryCosto(nodo*2,a,b), queryCosto(nodo*2+1,a,b));
}
vector<long long> pomelos(int N, vector<string> &e, vector<int> &p1, vector<int> &p2){
	pot=sigPot(N); 
	vector <ll> poms(N,0), res;
	for (int i=0;i<pot;i++){
	if (i>=N) ST[pot+i].sc=-1; 
	L[i+pot]=R[pot+i]=i; 
	}
	for (int i=pot-1;i>0;i--)
		L[i]=L[i*2], R[i]=R[i*2+1]; 
	for (int i=0;i<e.size();i++){
		if (e[i]=="A"){
			ll pos=p1[i], x=p2[i]; 
			pos--; 
			updateTiempo(pos,x);
		}
		else if (e[i]=="B"){
			ll pos=p1[i], x=p2[i];
			pos--;
			ll dif=x-poms[pos];
			updateRange(1, pos,pos,dif);
			poms[pos]=x;
		}
		else {
			ll a=p1[i], b=p2[i]; 
			a--,b--;
			ll costo=queryCosto(1,a,b); 
			ll tiempo=queryTiempo(1,0,a-1);
			ll resu=costo-tiempo; 
			res.push_back(resu);
		}
	}
//	for (int i=1;i<=pot;i++) cout<<" hoja: "<<i<< ": "<<ST[i].sc<<endl;
//	cout<<pot;
	return res;
	
}

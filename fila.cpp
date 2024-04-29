#include <vector>
#include <bits/stdc++.h>
#define ll long long
#define maxN 300000
using namespace std;
ll pot;
ll n;
ll actual;
struct Fecha
{
    int dia, mes,anno;
};
Fecha ST[maxN*4];
void sigPot(){
	pot=1;
	while (pot<n){
		pot*=2;
	}
}
Fecha getMenor(Fecha fecha1, Fecha fecha2){
	if (fecha1.anno>fecha2.anno) return fecha1;
	if (fecha2.anno>fecha1.anno) return fecha2;
	if (fecha1.mes>fecha2.mes) return fecha1;
	if (fecha2.mes>fecha1.mes) return fecha2;
	if (fecha1.dia>fecha2.dia) return fecha1;
	return fecha2;
}
bool esMenor(Fecha fecha1, Fecha fecha2){
	if (fecha1.anno>fecha2.anno) return true;
	if (fecha2.anno>fecha1.anno) return false;
	if (fecha1.mes>fecha2.mes) return true;
	if (fecha2.mes>fecha1.mes) return false;
	if (fecha1.dia>fecha2.dia) return  true;
	return false;
}
ll query (ll nodo, Fecha buscarMenor){
	if (!esMenor(ST[nodo], buscarMenor) || nodo-pot>actual) return -1;
	if (nodo>=pot && esMenor(ST[nodo], buscarMenor)&& nodo-pot<actual) return nodo-pot;
	if (esMenor(ST[nodo*2], buscarMenor)) return query(nodo*2,buscarMenor);
	return query(nodo*2+1, buscarMenor);
}
int fila(vector<Fecha> orden, vector<int> &enojados)
{
    n=orden.size();
    sigPot();
    Fecha aux;
    aux.anno=1;
    aux.dia=1;
    aux.mes=1;
    vector <pair <ll,ll>> furias;
    for (ll i=0;i<n;i++){
    	ST[i+pot]=orden[i];
	}
	for (ll i=n+1;i<pot;i++){
		ST[i+pot]=aux;
	}
	for (int i=pot-1;i>0;i--){
		ST[i]=getMenor(ST[i*2], ST[i*2+1]);
	}
	ll maxi=0;
    for (int i=1;i<n;i++){
    	actual=i;
    	ll pos=query(1, orden[i]);
    	if (pos!=-1){
    		furias.push_back({i-pos, -(i+1)});
    		maxi=max(maxi, i-pos);
    		//if (i+1==3) cout<<"POS DE 3: "<<pos<<endl;
		}
	}
	sort (furias.rbegin(), furias.rend());
	for (auto i:furias) enojados.push_back(-i.second);
	return maxi;
}

#include <string>
#include <vector>
#define ll long long
#define MAX_N 1000000

using namespace std;
ll ST[MAX_N*4], L[MAX_N*4], R[MAX_N*4];
ll pot;
void sigPot(ll n){
	pot=1;
	while (pot<n){
		pot*=2;
	}
}
void inicializar() {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    sigPot(MAX_N);
    for (int i=0;i<pot;i++){
    	ST[i+pot]=0;
    	L[i+pot]=R[i+pot]=i+pot;
	}
	for (int i=pot-1;i>0;i--){
		ST[i]=ST[i*2]+ST[i*2+1];
		L[i]=L[i*2], R[i]=R[i*2+1];
	}
    
}

void nuevoNumero(int x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    ll indice=x+pot;
    ST[indice]++;
    while (indice/=2){
    	ST[indice]=ST[indice*2]+ST[indice*2+1];
	}
}
int query(ll nodo, ll a, ll b){
if (L[nodo]>b || R[nodo]<a) return 0;
	if (L[nodo]>=a && R[nodo]<=b) return ST[nodo];
	return query(nodo*2,a,b)+query(nodo*2+1,a,b);
}

int contar(int a, int b) {
	a+=pot, b+=pot;
	return query(1,a,b);
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    
}

#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool can (ll k, vector <int> ciudades,  vector <int> peajes){
	ll saldo=0;
	for (int i=0;i<ciudades.size()-1;i++){
		saldo-=(k-ciudades[i]);
		if (saldo>0 && saldo-peajes[i]>=0){
			saldo-=peajes[i];
		}
		else if (saldo>0 && saldo-peajes[i]<0){
			saldo=0;
		}
		else if (saldo<0) saldo-=peajes[i];
	}
	saldo+=(ciudades[ciudades.size()-1]-k);
	return saldo>=0;
}
int panes(vector<int> &ciudades, vector<int> &peajes) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int  mini=1000000001, maxi=-1;
    for (auto i:ciudades){
    	mini=min(mini,i); maxi=max(maxi,i);
	}
	ll hi=maxi, lo=mini, mid;
	while (hi-lo>1){
		mid=(hi+lo)/2;
		if (can(mid, ciudades, peajes)) lo=mid;
		else hi=mid;
	}
    return lo;
}

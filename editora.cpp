#include <bits/stdc++.h>
#define ll long long 
#define ff first 
#define sc second 
using namespace std;
ll n; 
bool iguales; 
ll calcCosto(vector<int> &tinta, ll numero){
		if (iguales){
		string str=to_string(numero);

		return str.size()*tinta[0];
	}
    ll res = 0;
    while (numero > 0){
        res += tinta[numero % 10];
        numero /= 10;
    }
    return res;
}
int editora(vector<int> &tinta, vector<long long> &articulos, string &ordenamiento){
	ll n=articulos.size(); 
	iguales=true; 
	for (int i=1;i<=9;i++){
		if (tinta[i]!=tinta[i-1]) iguales=false; 
	}
	unsigned ll sum=0; 
	if (n==1){ordenamiento="A"; return tinta[1];}
	ll mask=(1<<(n))-1;
	vector <pair<ll,ll>> dp (mask+1,{1e15,0});
	vector <ll> costoMask (mask+1,0); 
	vector <char> last (mask+1);
	dp[0]={0,0};
	for (int i=1;i<=mask;i++){
		ll temp=i;
		while (temp > 0) {
        int lsbit = temp & -temp; 
        int j = __builtin_ctz(lsbit);
        ll aux = lsbit;
        ll indice = dp[i - aux].sc + 1;
        ll costo=costoMask[i-aux];
        if(!costo) costo=calcCosto(tinta,indice), costoMask[i-aux]=costo;
        if (dp[i - aux].ff + costo<dp[i].ff){
        	last[i]='A'+j; 
        	dp[i].ff=dp[i - aux].ff + costo;
		}
        dp[i].sc = dp[i - aux].sc + articulos[j];
        temp -= lsbit; 
    }
	}
	string res=""; 
	ll aux=mask; 
	while (aux>0){
		res+=last[aux]; 
		ll bit=last[aux]-'A';
		aux-=1<<(bit);
	}
	reverse (res.begin(),res.end()); 
	ordenamiento=res;
	return dp[mask].ff;
}

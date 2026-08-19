#include <bits/stdc++.h>
using namespace std;
#define ll long long 
vector <bool> compuesto;
void criba (ll lim, ll limB){
	compuesto.resize (limB+1, false);  
	for (ll i=2;i<=lim;i++){
		if (!compuesto[i]){ 
			compuesto[i]=1;
			for (int j=i*i;j<=limB;j+=i) compuesto[j]=1;
		}
	}
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	
	ll a,b,c; cin>>a>>b>>c; 
	ll lim = c;
	criba(lim,b);
	ll resp=0;
	for (ll i=a;i<=b;i++){
		resp+=!compuesto[i];
	}
	cout<<resp;
	
}

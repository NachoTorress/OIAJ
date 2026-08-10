#include <bits/stdc++.h>
using namespace std;
#define ff first 
#define sc second
#define ll long long
int main (){
	ll n; cin>>n; 
	vector <pair <ll,ll>> mesadas; 
	for (int i=0;i<n;i++){
		ll a,b; cin>>a>>b;
		if (b>a) swap(a,b); mesadas.push_back({a,b}); 
	}
	sort(mesadas.rbegin(), mesadas.rend()); 
	multiset <ll> ops; 
	ops.insert(mesadas[0].sc); 
	for (int i=1; i<n;i++){
		auto it=ops.lower_bound(mesadas[i].sc); 
		if (it!=ops.end()) ops.erase(it);
		ops.insert(mesadas[i].sc); 
	}
	cout<<ops.size();
}

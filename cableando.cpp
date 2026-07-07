#include <bits/stdc++.h>
using namespace std; 
#define ll long long 
int main(){
	ll n, central; 
	cin>>n>>central; 
	vector <ll> pos(n); for (auto &i:pos) cin>>i;
	pos.push_back(central);
	sort(pos.begin(), pos.end());
	ll res=0;
	for (int i=0;i<n;i++){
		res+=pos[i+1]-pos[i];
	}
	cout<<res;
}

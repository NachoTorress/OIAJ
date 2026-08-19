#include <bits/stdc++.h>
using namespace std;
#define ll long long
char sumar (char a, char b){ 
	if (b=='.') return a;
	if (b=='M') return 'M';
	if ((a=='A' && b=='R') || (a=='R' && b=='A')) return 'N'; 
	if ((a=='A' && b=='Z') || (a=='Z' && b=='A')) return 'V'; 
	if ((a=='R' && b=='Z') || (a=='Z' && b=='R')) return 'P'; 
	if ((a=='A' && b=='P') ||
		(a=='Z' && b=='N') ||
		(a=='R' && b=='V')) return 'M';
	
	return b;
}
int main()
{
	ll n,t; cin>>n>>t; 
	vector <char> senda (n,'.'); 
	for (int i=0;i<t;i++){
		ll a,b; char col; cin>>a>>b>>col; a--,b--;
		for (int j=a;j<=b;j++) senda[j]=sumar(col,senda[j]);
	}
	for (auto i:senda) cout<<i;
}

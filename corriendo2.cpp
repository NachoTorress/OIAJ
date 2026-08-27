#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> subidas(int N, vector<int> &cuadras){
	ll t=cuadras.size(); 
	vector <ll> prefix (t);
	prefix[0]=cuadras[0]; 
	for (int i=1;i<cuadras.size();i++) prefix[i]=prefix[i-1]+cuadras[i]; 
	ll resto=N%t; 
	ll vueltas=prefix[t-1]*(N/t);
	if (N%t==0) return {vueltas,vueltas}; 
	ll mini=LLONG_MAX, maxi=-1; 
	for (int i=0;i<t;i++){
		ll aux=0;
		if (i-resto+1<0)
    		aux=(prefix[t-1]-prefix[t-resto+i])+(prefix[i]);
		else aux=prefix[i]-(i-resto>=0? prefix[i-resto] : 0);
		mini=min(mini,aux), maxi=max(maxi,aux);
	}
	return {mini+vueltas,maxi+vueltas};
}

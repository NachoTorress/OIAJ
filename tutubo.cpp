#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> tutubo(vector<int> &siguiente, vector<int> &preguntaX, vector<long long> &preguntaK){
	ll n=siguiente.size(); 
	ll up [n][62];
	for (int i=0;i<n;i++) up[i][0]=siguiente[i]; 
	for (int i=1;i<=61;i++){
		for (int j=0;j<n;j++) up[j][i]=up[up[j][i-1]][i-1]; 
	}
	vector <int> resp;
	for (int i=0;i<preguntaX.size();i++){
		ll ini=preguntaX[i], subir=preguntaK[i];
		for (ll i=61;i>=0;i--){
			if (subir & ((ll)1<<i)) ini=up[ini][i];
		}
		resp.push_back(ini);
	}
	return resp;
}

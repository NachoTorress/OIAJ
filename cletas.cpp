#include <string>
#include <vector>
#define ll long long
#include <bits/stdc++.h>
using namespace std;

long long cletas(vector<int> &x, vector<int> &c) {
	ll total=0;
	vector <pair <ll,ll>> estaciones;
	for (int i=0;i<c.size();i++)
		estaciones.push_back({x[i],c[i]});
	ll totalBicis=0;
	for (auto i:c) totalBicis+=i;
	totalBicis*=2; 
	ll n=x.size();
	ll B=totalBicis/n;
	sort (estaciones.begin(), estaciones.end());
	ll acumulado=0;
	ll traer=0, llevar=0;
	for (int i=0;i<estaciones.size()-1;i++){

		if (estaciones[i].second<B/2){
			traer+=B/2-estaciones[i].second;			
		}
		else if (estaciones[i].second>B/2){
			traer+=B/2-estaciones[i].second;
		}
		acumulado+=(estaciones[i+1].first-estaciones[i].first)*abs(traer);
	}
	return acumulado;
}

#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define ff first
#define sc second
struct corredor {
	ll edad; char sexo; ll numero; 
};
int main(){
	ll a, cf,cm, l; cin>>a>>cf>>cm>>l;
	vector <pair<ll,ll>> catsF, catsM;
	for (int i=0;i<cf;i++){
		ll c,b; cin>>c>>b; 
		catsF.push_back({c,b});
	}
	for (int i=0;i<cm;i++){
		ll c,b; cin>>c>>b; 
		catsM.push_back({c,b});
	}
	vector <corredor> corredores; 
	for (int i=0;i<a;i++){
		corredor aux; cin>>aux.edad>>aux.sexo; 
		aux.numero=i+1;
		corredores.push_back(aux);
	}
	vector <vector <ll>> ganadoresF(cf), ganadoresM(cm);
	for (int i=0;i<l;i++){
		ll aux; cin>>aux; 
		corredor act=corredores[aux-1]; 
		if (act.sexo=='M'){
			for (int i=0;i<catsM.size();i++){
				if(act.edad>=catsM[i].ff && act.edad<=catsM[i].sc && ganadoresM[i].size()<3) ganadoresM[i].push_back(aux);
			}
		}
		if (act.sexo=='F'){
			for (int i=0;i<catsF.size();i++){
				if(act.edad>=catsF[i].ff && act.edad<=catsF[i].sc && ganadoresF[i].size()<3) ganadoresF[i].push_back(aux);
			}
		}
	}
	for (int i=0;i<ganadoresF.size();i++){
		cout<<i+1<<" ";
		if (ganadoresF[i].size()<3) ganadoresF[i].resize(3,0);
		for (auto j:ganadoresF[i]) cout<<j<<" ";
		cout<<endl;
	}
	for (int i=0;i<ganadoresM.size();i++){
		cout<<i+1<<" ";
		if (ganadoresM[i].size()<3) ganadoresM[i].resize(3,0);
		for (auto j:ganadoresM[i] )cout<<j<<" ";
		cout<<endl;
	}
}

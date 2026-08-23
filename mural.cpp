#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ll n,pH, pV; cin>>n>>pH>>pV;
	vector <vector <vector<ll>>> mural (n, vector <vector<ll>> (n, vector <ll>(3,0)));
	ll tiempo=1;
	for (int i=0;i<pH;i++,tiempo++){
		ll fila, inicio,final; 
		char color;
		cin>>fila>>color>>inicio>>final; 
		fila--,inicio--, final--; 
		ll indice; 
		if (color=='R') indice=0; 
		else if (color=='Z') indice=1; 
		else indice=2; 
		for (int j=inicio;j<=final;j++) mural[fila][j][indice]=tiempo;
	}	
	for (int i=0;i<pV;i++,tiempo++){
		ll col, inicio,final; 
		char color;
		cin>>col>>color>>inicio>>final; 
		col--,inicio--, final--; 
		ll indice; 
		if (color=='R') indice=0; 
		else if (color=='Z') indice=1; 
		else indice=2; 
		for (int j=inicio;j<=final;j++) mural[j][col][indice]=tiempo;
	}
	vector <vector <char>> resp (n,vector <char>(n)); 
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (mural[i][j][0]==0 & mural[i][j][1]==0 & mural[i][j][2]==0) resp[i][j]='.'; 
			else if (mural[i][j][0]>0 & mural[i][j][1]==0 & mural[i][j][2]==0) resp[i][j]='R';
			else if (mural[i][j][0]==0 & mural[i][j][1]>0 & mural[i][j][2]==0) resp[i][j]='Z';
			else if (mural[i][j][0]==0 & mural[i][j][1]==0 & mural[i][j][2]>0) resp[i][j]='A';
			else if (mural[i][j][0]==0 & mural[i][j][1]>0 & mural[i][j][2]>0) resp[i][j]='V';
			else if (mural[i][j][0]>0 & mural[i][j][1]==0 & mural[i][j][2]>0) resp[i][j]='N';
			else if (mural[i][j][0]>0 & mural[i][j][1]>0 & mural[i][j][2]==0) resp[i][j]='P';
		}
	}
	for (auto i:resp){
		for (auto j:i)cout<<j; 
		cout<<endl;
	}
}

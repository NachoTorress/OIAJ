#include <vector>
#include <bits/stdc++.h>
#define INF 1e8
using namespace std;
vector <int> ubicaciones;
vector <int> padres;
vector <int> minimos;
vector <int> indices;
vector<int> electromovil(int E, vector<int> ubicacion, vector<int> autonomia)
{
	padres.resize(E,-1);
	minimos.resize(E,INF);
	int id;
	for (int i=E-1;i>=0;i--,id++){
		ubicaciones.push_back(-ubicacion[i]);
	}
	minimos[0]=0;
   for (int i=0;i<E-1;i++){
   	//	cout<<i<<endl;
   		auto it=lower_bound(ubicaciones.begin(), ubicaciones.end(),-(ubicacion[i]+autonomia[i]));
   	//	if (it==ubicaciones.end())cout<<"NO SE ENCONTRO "<<endl;
   		if (it!=ubicaciones.end()){
   			int proximaEstacion=it-ubicaciones.begin();
   			proximaEstacion=abs(E-proximaEstacion-1);
   		//	cout<<"Proxima estacion de "<<i<<" :"<<proximaEstacion<<endl;
   			while(proximaEstacion>=i && minimos[i]+1<minimos[proximaEstacion]){
   			//	cout<<"ProximaEstacion: "<<proximaEstacion<<endl;
   				if (minimos[i]+1<minimos[proximaEstacion]){
   					padres[proximaEstacion]=i;
   					minimos[proximaEstacion]=minimos[i]+1;
				   }
				   proximaEstacion--;
			   }
		   }
   }
   // for (auto i:minimos) cout<<i<<" ";
  // cout<<endl;
   if (padres[E-1]==-1) return vector <int>(0);
   int actual=E-1;
  // cout<<"MINIMOS: "<<endl;
  
   vector <int> resp;
   while (actual){
   	resp.push_back(ubicacion[actual]);
   	actual=padres[actual];
   }
   reverse(resp.begin(),resp.end());
   return resp;
}

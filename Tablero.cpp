#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;
vector <vector <ll>> dist;
ll filaFinal, colFinal;
void mostrarTablero(){
	cout<<"DISTANCIAS: "<<endl;
	for (int i=0;i<8;i++){
		for (int j=0;j<8;j++){
			if (dist[i][j]!=INF) cout<<dist[i][j]<<" ";
			else cout<<-1<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void torre(queue<pair<ll,ll>>&cola, pair <ll,ll> posActual, vector<string> escaques ){
	ll fila=posActual.first, col=posActual.second;
	for (int i=1;i<=7;i++){
		if (col+i<8 && escaques[fila][col+i]!='X'){
			if (dist[fila][col+i]>dist[fila][col]+1){
			dist[fila][col+i]=dist[fila][col]+1;
			cola.push({fila,col+i});
			
			}
		}
		else break;
	}
//	mostrarTablero();
	for (int i=1;i<=7;i++){
		if (col-i>=0 && escaques[fila][col-i]!='X'){
			if (dist[fila][col-i]>dist[fila][col]+1){
				dist[fila][col-i]=dist[fila][col]+1;
				cola.push({fila,col-i});
			}
		}
		else  break;
	}
	for (int i=1;i<=7;i++){
		if (fila+i<8 && escaques[fila+i][col]!='X'){
			if (dist[fila+i][col]>dist[fila][col]+1){
				dist[fila+i][col]=dist[fila][col]+1;
				cola.push({fila+i,col});
			}
	}	
		else  break;
	}
	for (int i=1;i<=7;i++){
		if (fila-i>=0 && escaques[fila-i][col]!='X'){
			if (dist[fila-i][col]>dist[fila][col]+1){
				dist[fila-i][col]=dist[fila][col]+1;
				cola.push({fila-i,col});
			}
		
	}
	else  break;
	}
}
void alfil (queue<pair<ll,ll>>&cola, pair <ll,ll> posActual, vector<string> escaques ){
	ll fil=posActual.first, col=posActual.second;
	for (int i=1;i<=7;i++){
		if (fil-i>=0 && col-i>=0  && escaques[fil-i][col-i] !='X'){
			if (dist[fil-i][col-i]>dist[fil][col]+1){
				dist[fil-i][col-i]=dist[fil][col]+1;
				cola.push({fil-i,col-i});
			}
		}
		else break;
	}
	for (int i=1;i<=7;i++){
		if (fil-i>=0 && col+i<8 && escaques[fil-i][col+i] !='X'){
			if (dist[fil-i][col+i]>dist[fil][col]+1){
				dist[fil-i][col+i]=dist[fil][col]+1;
				cola.push({fil-i,col+i});
			}
		}
		else break;
	}
	for (int i=1;i<=7;i++){
		if (fil+i<8 && col-i>=0  && escaques[fil+i][col-i] !='X'){
			if (dist[fil+i][col-i]>dist[fil][col]+1){
				dist[fil+i][col-i]=dist[fil][col]+1;
				cola.push({fil+i,col-i});
			}
		}
		else break;
	}
	for (int i=1;i<=7;i++){
		if (fil+i<8 && col+i<8  && escaques[fil+i][col+i] !='X'){
			if (dist[fil+i][col+i]>dist[fil][col]+1){
				dist[fil+i][col+i]=dist[fil][col]+1;
				cola.push({fil+i,col+i});
			}
		}
		else break;
	}

}
void caballo (queue<pair<ll,ll>>&cola, pair <ll,ll> posActual, vector<string> escaques){
	ll fil=posActual.first, col=posActual.second;
	/*-1 -2*/if (fil-1>=0 && col-2>=0 && escaques[fil-1][col-2]!='X'){
		if (dist[fil-1][col-2]>dist[fil][col]+1){
			dist[fil-1][col-2]=dist[fil][col]+1;
			cola.push({fil-1,col-2});
		}
	}
	/*-1 +2*/if (fil-1>=0 && col+2<8 && escaques[fil-1][col+2]!='X'){
		if (dist[fil-1][col+2]>dist[fil][col]+1){
			dist[fil-1][col+2]=dist[fil][col]+1;
			cola.push({fil-1,col+2});
		}
	}
	/*+1 -2*/ if (fil+1<8 && col-2>=0 && escaques[fil+1][col-2]!='X'){
		if (dist[fil+1][col-2]>dist[fil][col]+1){
			dist[fil+1][col-2]=dist[fil][col]+1;
			cola.push({fil+1,col-2});
		}
	}
	/* +1 +2*/ if (fil+1<8 && col+2<8 && escaques[fil+1][col+2]!='X'){
			if (dist[fil+1][col+2]>dist[fil][col]+1){
				dist[fil+1][col+2]=dist[fil][col]+1;
				cola.push({fil+1,col+2});
			}
	}
	/* -2 -1*/ if (fil-2>=0 && col-1>=0 && escaques[fil-2][col-1]!='X'){
		if (dist[fil-2][col-1]>dist[fil][col]+1){
			dist[fil-2][col-1]=dist[fil][col]+1;
			cola.push({fil-2,col-1});
		}
	}
	/* -2 +1*/ if (fil-2>=0 && col+1<8 && escaques[fil-2][col+1]!='X'){
		if (dist[fil-2][col+1]>dist[fil][col]+1){
			dist[fil-2][col+1]=dist[fil][col]+1;
			cola.push({fil-2,col+1});
		}
	}
	/* +2 -1*/ if (fil+2<8 && col-1>=0 && escaques[fil+2][col-1]!='X'){
		if (dist[fil+2][col-1]>dist[fil][col]+1){
			dist[fil+2][col-1]=dist[fil][col]+1;
			cola.push({fil+2,col-1});
		}
	}
	/* +2 +1*/ if (fil+2<8 && col+1<8 && escaques[fil+2][col+1]!='X'){
		if (dist[fil+2][col+1]>dist[fil][col]+1){
			dist[fil+2][col+1]=dist[fil][col]+1;
			cola.push({fil+2,col+1});
		}
	}
}
void rey (queue<pair<ll,ll>>&cola, pair <ll,ll> posActual, vector<string> escaques){
	ll fil=posActual.first, col=posActual.second;
	if (fil-1>=0){
		if (col-1>=0 && escaques[fil-1][col-1]!='X'){
			if (dist[fil-1][col-1]>dist[fil][col]+1){
				dist[fil-1][col-1]=dist[fil][col]+1;
				cola.push({fil-1,col-1});
			}
		}
		if (escaques[fil-1][col]!='X'){
			if (dist[fil-1][col]>dist[fil][col]+1){
				dist[fil-1][col]=dist[fil][col]+1;
				cola.push({fil-1,col});
			}
		}
		if (col+1<8 && escaques[fil-1][col+1]!='X'){
			if (dist[fil-1][col+1]>dist[fil][col]+1){
				dist[fil-1][col+1]=dist[fil][col]+1;
				cola.push({fil-1,col+1});
			}
		}
	}
	if (col-1>=0 && escaques[fil][col-1]!='X'){
		if (dist[fil][col-1]>dist[fil][col]+1){
			dist[fil][col-1]=dist[fil][col]+1;
			cola.push({fil,col-1});
		}
	}
	if (col+1<8 && escaques[fil][col+1]!='X'){
		if (dist[fil][col+1]>dist[fil][col]+1){
			dist[fil][col+1]=dist[fil][col]+1;
			cola.push({fil,col+1});
		}
	}
	if (fil+1<8){
		if (col-1>=0 && escaques[fil+1][col-1]!='X'){
			if (dist[fil+1][col-1]>dist[fil][col]+1){
				dist[fil+1][col-1]=dist[fil][col]+1;
				cola.push({fil+1,col-1});
			}
		}
		if (escaques[fil+1][col]!='X'){
			if (dist[fil+1][col]>dist[fil][col]+1){
				dist[fil+1][col]=dist[fil][col]+1;
				cola.push({fil+1,col});
			}
		}
		if (col+1<8 && escaques[fil+1][col+1]!='X'){
			if (dist[fil+1][col+1]>dist[fil][col]+1){
				dist[fil+1][col+1]=dist[fil][col]+1;
				cola.push({fil+1,col+1});
			}
		}
	}
}
void BFS(string pieza, queue<pair<ll,ll>>&cola, pair <ll,ll> posActual, vector<string> escaques){
	if (pieza=="torre") torre(cola,posActual,escaques);
	else if (pieza=="alfil") alfil(cola,posActual,escaques);
	else if (pieza=="dama"){
		torre(cola,posActual,escaques);
		alfil(cola,posActual,escaques);
	}
	else if (pieza=="caballo") caballo(cola,posActual,escaques);
	else rey(cola,posActual,escaques);
}
int tablero(string &pieza, string &salida, string &llegada, vector<string> &escaques){
	
	ll colInicio=salida[0]-'a', filaInicio=7-(salida[1]-'0'-1); 
	colFinal=llegada[0]-'a', filaFinal=7-(llegada[1]-'0'-1);
	//cout<<"fila inicio: "<<filaInicio<<endl;
//	cout<<"fila final: "<<filaFinal<<endl;
	dist.resize(8, vector<ll> (8,INF));
	queue <pair<ll,ll>> cola;
	dist[filaInicio][colInicio]=0;
	cola.push({filaInicio, colInicio});
	
	while (cola.size()){
		pair<ll,ll> aux=cola.front(); cola.pop();
		//mostrarTablero();
		BFS(pieza,cola, aux,escaques);
	}
	
	if (dist[filaFinal][colFinal]==INF) return -1; 
	else return dist[filaFinal][colFinal];
}



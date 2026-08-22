
	#include <bits/stdc++.h>
	#include <iostream>
	#include <vector>
	#define ll long long
	using namespace std;
	int fabricante( int P, int precioVenta, int cantidadVenta, vector< int > precioCompra, vector< int > cantidadCompra, int & fabricante ){
		int ut=-1; 
		fabricante=0;
		ll venta=(ll) cantidadVenta* (ll) precioVenta;
		if (!precioCompra.size()) return 0;
		for (int i=0;i<precioCompra.size();i++){
			int cantAct=max(cantidadCompra[i], cantidadVenta); 
			ll compra=(ll) precioCompra[i]*(ll)cantAct;
			if (compra>P) continue;
			ll aux=venta-compra;
			if (aux>ut) fabricante=i+1, ut=aux;
		}
		if (ut<0) return -1;
		return ut;
	}

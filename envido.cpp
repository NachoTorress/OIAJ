#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int envido(int numero1, string &palo1, int numero2, string &palo2, int numero3, string &palo3){
	int res=0;
	bool envido=false;
	if (numero1>=10) numero1=0; 
	if (numero2>=10) numero2=0;
	if (numero3>=10) numero3=0; 
	if (palo1==palo2) res=max(res, numero1+numero2), envido=1;
	if (palo2==palo3) res=max(res, numero2+numero3), envido=1;
	if (palo1==palo3) res=max(res, numero1+numero3), envido=1;
	if (!envido) return max(numero1, max(numero2,numero3));
	else return res+20;
}

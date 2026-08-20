#include <bits/stdc++.h>
#define ll long long
#define ff first
#define sc second
using namespace std;
vector<int> robosort(vector<int> &muestras){
	ll n=muestras.size(); 
		vector <int> resp (n,0);
	for (int i=0;i<n;i++){
		ll posMenor=-1, menor=LLONG_MAX; 
		for (int j=i;j<n;j++){
			if (muestras[j]<menor) posMenor=j, menor=muestras[j];
		}
		resp[i]=posMenor+1;
		reverse(muestras.begin()+i, muestras.begin()+posMenor+1);
	}
	return resp;
}

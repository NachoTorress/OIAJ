#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector <ll>ps;
ll F;
bool can(ll dias){
//	cout<<"DIAS ANALIZANDOSE: "<<dias<<endl;
	for (int i=0;i<=ps.size()-dias;i++){
		if (ps[i + dias - 1] - (i > 0 ? ps[i - 1] : 0) <= F) return true;
	}
//	cout<<"retornando falso"<<endl;
	return false;
}
void mostrarV(vector <ll> v){
	cout<<"VECTOR: "<<endl;
	for (auto i:v)cout<<i<<" ";
	cout<<endl;
}
int main(){
	ll n, d, f;
	cin>>n>>d>>f;
	vector <ll> dias(d,1);
	for (int i=0;i<n;i++){
		ll aux; cin>>aux;
		dias[aux-1]--;
	}
	ps.resize(d);
	ps[0]=dias[0];
	for (int i=1;i<d;i++){
		ps[i]=ps[i-1]+dias[i];
		
	}
	F=f;
	ll lo=f, hi=d, mid, pos=0;
	//mostrarV(ps);
	while (lo<=hi){
		mid=(hi+lo)/2;
		if (can(mid)) {
			
		lo=mid+1;
		pos=max(pos, mid);
	}
		else hi=mid-1;
	}
	cout<<pos;
}

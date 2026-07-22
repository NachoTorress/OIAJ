#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ff first
#define sc second
int main(){
	ll n; cin>>n; 
	vector <ll> nums (n); 
	ll total=0;
	for (auto &i:nums){
		cin>>i; 
		total+=i;
	}
	vector <vector <pair<ll,ll>>> ops(2);
	vector <ll> dp1(n+2,0), dp2 (n+2,0); 
	for (int i=0;i<n-2;i++){
		ll aux=nums[i]*nums[i+2];
		ops[i%2].push_back({aux,nums[i]});
	}
	for (int i=0;i<ops[0].size();i++){
		ll i1=0,i2=0; 
		if (i-1>=0) i1=dp1[i-1];
		if (i-2>=0) i2=dp1[i-2]; 
		dp1[i]=max(i1, i2+ops[0][i].ff); 
	}
	for (int i=0;i<ops[1].size();i++){
		ll i1,i2; 
		if (i-1>=0) i2=dp2[i-2]; 
		if (i-1>=0) i1=dp2[i-1];
		dp2[i]=max(i1, i2+ops[1][i].ff); 
	}
	if (n<=2) {
	cout<<0<<endl<<total;
	return 0;
	}
	else if (n==3){
	cout<<ops[0][0].ff<<endl<<nums[1]<<endl;
	return 0;
	}
	ll sum=0; 
	for (int i=ops[0].size()-1;i>=0;i--){
		ll i2=0; if (i-2>=0) i2=dp1[i-2];
		if (dp1[i]==ops[0][i].ff+i2) sum+=ops[0][i].sc+ops[0][i].ff/ops[0][i].sc, i--;
	}
	for (int i=ops[1].size()-1;i>=0;i--){
		ll i2=0; if (i-2>=0) i2=dp2[i-2];
		if (dp2[i]==ops[1][i].ff+i2) sum+=ops[1][i].sc+ops[1][i].ff/ops[1][i].sc, i--;
	}
	cout<<dp1[ops[0].size()-1]+dp2[ops[1].size()-1]<<endl; 
	cout<<total-sum;
}

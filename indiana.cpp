#include <bits/stdc++.h> 
using namespace std;
#define ll long long 
#define ff first 
#define sc second
ll n; 
int main(){
	cin>>n; 
	vector <string> sentido (n);
	for (auto &i:sentido) cin>>i;
	vector <vector <ll>> ej (n,vector <ll>(4,LLONG_MAX));
	vector <vector <vector <ll>>> dp (n,ej);
	dp[0][0][2]=2; 
	if (sentido[0][0]=='H') dp[0][0][3]=3; 
	else dp[0][0][3]=1;
	for (int i=1;i<n;i++){
		dp[0][i][2]=dp[0][i-1][2]+2; 
		if (sentido[0][i]=='H') dp[0][i][3]=dp[0][i-1][2]+3; 
		else dp[0][i][3]=dp[0][i-1][2]+1; 
	}
	for (int i=1;i<n;i++){
		dp[i][0][3]=dp[i-1][0][3]+2;
		if (sentido[i][0]=='H') dp[i][0][2]=dp[i-1][0][3]+1; 
		else dp[i][0][2]=dp[i-1][0][3]+3;
	}
	for (int i=1;i<n;i++){
		for (int j=1;j<n;j++){
			ll costoArriba=dp[i-1][j][3]; 
			ll costoIzq=dp[i][j-1][2]; 	
			if (sentido[i][j]=='H') dp[i][j][2]=min(costoArriba+1,costoIzq+2), dp[i][j][3]=min(costoArriba+2,costoIzq+3); 
			else dp[i][j][2]=min(costoArriba+3,costoIzq+2), dp[i][j][3]=min(costoArriba+2,costoIzq+1); 
		}
	}
	cout<<dp[n-1][n-1][2];
}

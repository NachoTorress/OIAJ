#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define sc second
ll n,m;
bool esCamino(ll a, ll b){
	if (a<0 || b<0 || a>=n || b>=m) return false; 
	return true; 
}
int main(){
	cin>>n>>m;
	vector <vector<ll>> dp (n, vector <ll>(m,-1));
	vector <string> grid(n);
	for (auto &i:grid) cin>>i;
	for (int i=0;i<n;i++) if (grid[i][0]=='A') dp[i][0]=0;
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			ll a=j, b=i;
			if (dp[j][i]!=-1){
				if (esCamino(a-1,b+1)){
					if (grid[a-1][b+1]!='M') dp[a-1][b+1]=max(dp[a-1][b+1], dp[j][i]+(grid[a-1][b+1]=='J'));
					else if (dp[a][b]>0) dp[a-1][b+1]=max(dp[a-1][b+1], (ll)0);
				}
				if (esCamino(a,b+1)){
					if (grid[a][b+1]!='M') dp[a][b+1]=max(dp[a][b+1], dp[j][i]+(grid[a][b+1]=='J'));
					else if (dp[a][b]>0) dp[a][b+1]=max(dp[a][b+1],(ll)0);
				}
				if (esCamino(a+1,b+1)){
					if (grid[a+1][b+1]!='M') dp[a+1][b+1]=max(dp[a+1][b+1], dp[j][i]+(grid[a+1][b+1]=='J'));
					else if (dp[a][b]>0) dp[a+1][b+1]=max(dp[a+1][b+1],(ll)0);
				}
			}
		}
	}
	ll maxi=dp[0][m-1]; 
	for (int i=1;i<n;i++) maxi=max(maxi,dp[i][m-1]);
	if (maxi==-1) cout<<"SIN SALIDA";
	else cout<<maxi;
}

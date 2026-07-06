#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int sandias(int T, vector<int> &x, vector<int> &p, vector<int> &ubicaciones){
	ll n=x.size();
	vector <vector<ll>> dp (T+1, vector <ll>(n+1,0));
	for (int i=1;i<=T;i++){
		for (int j=1;j<=n;j++){
			if (p[j-1]<=i) dp[i][j]=max(dp[i-p[j-1]][j-1]+p[j-1], max(dp[i-1][j], dp[i][j-1]));
			else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	
	ll a=T, b=n;
	vector <ll> pos; 
	while (a && b){
		if (dp[a][b]==dp[a][b-1]) b--;
		else if (dp[a][b]==dp[a-1][b]) a--; 
		else {
			pos.push_back({b-1});
			a-=p[b-1]; 
			b--;
		}
	}
	for (int i=pos.size()-1;i>=0;i--){
		ubicaciones.push_back(x[pos[i]]);
	}
	}
	return dp[T][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    int Q;
    cin >> Q;
    vector<int> x;
    vector<int> p;
    x.resize(Q);
    p.resize(Q);
    for (int i = 0; i < Q; i++) {
        cin >> x[i];
        cin >> p[i];
    }
    vector<int> ubicaciones;
    ubicaciones.resize(0);
    int returnedValue;
    returnedValue = sandias(T, x, p, ubicaciones);
    cout << returnedValue << "\n";
    for (int i = 0; i < int(ubicaciones.size()); i++) {
        if (i > 0) cout << " ";
        cout << ubicaciones[i];
    }
    cout << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n, x[100001];
	cin >> t;
	while(t--){
		cin >> n;
		cin >> x[0];
		int mx = x[0];
		int ans = INT_MIN;
		for(int i=1;i<n;i++){
			cin >> x[i];
			ans = max(ans, mx-x[i]);
			mx = max(x[i], mx);
		}
		cout << ans << endl;
	}
}
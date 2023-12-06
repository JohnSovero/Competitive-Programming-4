#include<iostream>

using namespace std;
int main(){
	int t,n,x[100001],mx;
	cin >> t;
	while(t--){
		cin >> n;
		cin >> x[0];
		mx = x[0];
		for(int i=1;i<n;i++)
            cin >> x[i];
		int MAX = INT_MAX * -1;
		for(int i=1;i<n;i++){
			MAX = max(MAX, mx-x[i]);
			mx = max(x[i],mx);
		}
		cout << MAX << endl;
	}
}
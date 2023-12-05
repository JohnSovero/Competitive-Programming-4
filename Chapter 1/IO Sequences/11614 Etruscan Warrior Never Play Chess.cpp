#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t, n;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        printf("%lld\n", (ll)(-1 + sqrt(1 + 8*n)) / 2);
    }
    return 0;
}
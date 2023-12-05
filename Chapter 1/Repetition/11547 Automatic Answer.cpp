//https://onlinejudge.org/external/115/11547.pdf
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;
    scanf("%lld", &t);
    while(t--){
        int n;
        scanf("%lld", &n);
        int a = (((((n*567) / 9) + 7492) * 235) / 47) - 498;
        printf("%lld\n",  abs((a/10) % 10));
    }
    return 0;
}
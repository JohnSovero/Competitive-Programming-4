//https://onlinejudge.org/external/110/11044.pdf
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        printf("%d\n", (n/3) * (m/3));
    }
    return 0;
}
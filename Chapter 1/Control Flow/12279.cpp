//53
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, c = 1;
    while(scanf("%d", &n), n){
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int x; 
            scanf("%d", &x);
            if(x) ans++;
            else ans--;
        }
        printf("Case %d: %d\n", c, ans);
        c++;
    }
    return 0;
}
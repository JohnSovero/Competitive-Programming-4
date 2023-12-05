#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc, c = 1;
    scanf("%d", &tc);
    while(tc--){
        int n, ans = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            int current;
            scanf("%d", &current);
            ans = max(ans, current);
        }
        printf("Case %d: %d\n", c, ans);
        c++;
    }
    return 0;
}
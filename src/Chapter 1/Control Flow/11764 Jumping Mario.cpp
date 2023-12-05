#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc, c = 1;
    scanf("%d", &tc);
    while(tc--){
        int n, current, after, hj = 0, lj = 0;
        scanf("%d", &n);
        scanf("%d", &current);
        
        for(int i = 1; i < n; ++i){
            scanf("%d", &after);
            if(current > after) 
                lj++;
            else if(current < after)
                hj++;
            current = after;
        }
        printf("Case %d: %d %d\n", c, hj, lj);
        ++c;
    }
    return 0;
}
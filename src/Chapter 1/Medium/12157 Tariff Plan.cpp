#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        int n, cnt = 0, cnt2 = 0;
        scanf("%d", &n);
        while(n--){
            int x;
            scanf("%d", &x);
            cnt += 10 * ((x / 30) + 1);
            cnt2 += 15 * ((x / 60) + 1);
        }
        printf("Case %d: %s %d\n", t, cnt > cnt2? "Juice" : cnt == cnt2 ? "Mile Juice": "Mile", min(cnt, cnt2));
    }
    return 0;
}
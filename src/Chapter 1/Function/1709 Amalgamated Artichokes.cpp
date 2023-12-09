//https://onlinejudge.org/external/17/1709.pdf
#include <bits/stdc++.h>
using namespace std;

int main(){
    int p, a, b, c, d, n;
    while(scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n) == 6){
        double ans = 0;
        double before = p * (sin((a + b)) + cos((c + d)) + 2);
        for(int k = 2; k <= n; ++k){
            double current = p * (sin((a * k + b)) + cos((c * k + d)) + 2);
            before = max(before, current);
            if(before > current){
                ans = max(ans, before - current);
            }
            else{
                before = current;
            }
        }
        printf("%.7lf\n", ans);
    }
    return 0;
}
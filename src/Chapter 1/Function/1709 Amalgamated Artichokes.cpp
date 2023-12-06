//https://onlinejudge.org/external/17/1709.pdf
#include <bits/stdc++.h>
using namespace std;

int main(){
    int p, a, b, c, d, n;
    while(scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n) == 6){
        double max_decline = 0;
        double max_height = p * (sin((a + b)) + cos((c + d)) + 2);
        for(int k = 2; k <= n; ++k){
            double current = p * (sin((a * k + b)) + cos((c * k + d)) + 2);
            if(max_height > current){
                max_decline = max(max_decline, max_height - current);
            }
            else{
                max_height = current;
            }
        }
        printf("%.7lf\n", max_decline);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, cnt = 0;
    scanf("%d", &n);
    while(n--){
        double l, wi, d, w;
        scanf("%lf %lf %lf %lf", &l, &wi, &d, &w);
        if((l <= 56.00 && wi <= 45.00 && d <= 25.00 || l + wi + d <= 125.00) && w <= 7.00){
            puts("1");
            cnt++;
        }
        else{
            puts("0");
        }
    }
    printf("%d\n", cnt);
    return 0;
}
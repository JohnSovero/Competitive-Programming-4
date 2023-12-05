#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc, i = 1;
    scanf("%d", &tc);
    while(tc--){
        int l, w, h;
        scanf("%d%d%d", &l, &w, &h);
        if(l <= 20 && w <= 20 && h <= 20){
            printf("Case %d: good\n", i);
        }
        else{
            printf("Case %d: bad\n", i);
        }
        ++i;
    }
    return 0;
}